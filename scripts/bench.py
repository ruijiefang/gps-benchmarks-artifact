import sys
import os
import glob
from string import Template
import subprocess
import tempfile
import types
import statistics

toolbins = {
        'gpsnogas' :  '/gps-ae/duet-gps/',
        'gpsnogasnosum' :  '/gps-ae/duet-gps/',
        'veriabs' : '/gps-ae/VeriAbs/',
        'cpachecker': '/gps-ae/CPAchecker-2.3-unix/', # 2.3 is the SVCOMP-24 version checkpointed on Zenodo
        'cpaimpact': '/gps-ae/CPAchecker-4.0-unix/', # 4.0 has ImpactRefiner-SBE.properties, which is undeprecated and documented
        'gps' : '/gps-ae/duet-gps/',
        'gpslite' : '/gps-ae/duet-gps/',
        'symbiotic': '/gps-ae/symbiotic/bin/',
}
suites = []
tools = []

cpus = None
numCpus = None
try: 
    with open('/gps-ae/tmpfiles/cpus') as f: 
        cpus = f.read().lstrip().rstrip()
        numCpus = str(len(cpus.split(',')))
except:
    print('ERROR: Could not deduce the hardware CPU requirements.')
    print('Please run /gps-ae/init.sh to initialize benchmark environment, or the following commands manually')
    print("""
        FREQ=`lscpu -e | awk '//{print $7}' | sort | uniq -c | sort -n | tail -1 | awk '//{print $2}'`;
        CPUS=`lscpu -e | awk -v freq="$FREQ" '//{ if($7==freq) print $1 }'`;
        echo $CPUS | tr ' ' ',' > /gps-ae/tmpfiles/cpus
        """)
    print("Exiting...")
    exit(1)

timeout = 600
cache = False
replace_cached = True 

table_begin = """<?xml version="1.0" ?>
<!DOCTYPE table PUBLIC "+//IDN sosy-lab.org//DTD BenchExec table 1.10//EN" "https://www.sosy-lab.org/benchexec/table-1.10.dtd">
<table>
"""
table_end = "</table>"


def run():
    for suite in suites:
        for tool in tools:
                print("Running %s on suite %s" % (tool, suite))
                # Add bench dir to PYTHONPATH so benchexec can find the
                # tool module
                my_env = os.environ.copy()
                my_env["PYTHONPATH"] = os.getcwd()
                print('PYTHONPATH: ', my_env['PYTHONPATH'])
                my_env["PATH"] = my_env["PATH"] + ":" + os.path.abspath('..')
                #memlimit = "14900000000" # 14.9G Bytes
                if tool=='gpsnogas' or tool=='CRA' or tool=='seahorn' or tool=='gpsnogasnosum' or tool=='gps' or tool == 'gpslite': # PATH is set in tools/
                  subprocess.call(["benchexec",
                                '-M',
                                '15GB',
                                '-c',
                                numCpus,
                                '--allowedCores', # https://github.com/sosy-lab/benchexec/issues/850
                                cpus,
                                "--no-container",
                                "--no-compress-results",
                                "--no-tmpfs",
                                "-W", str(timeout),
                                 "-t", suite,
                                 "benchmark-defs/%s.xml" % tool],
                                env=my_env)
                else:
                    subprocess.call(["benchexec",
                                '-M',
                                '15GB',
                                '-c',
                                numCpus,
                                '--allowedCores', # https://github.com/sosy-lab/benchexec/issues/850
                                cpus,
                                '--tool-directory',
                                toolbins[tool],
                                "--no-container",
                                "--no-tmpfs",
                                "--no-compress-results",
                                "-W", str(timeout),
                                 "-t", suite,
                                 "benchmark-defs/%s.xml" % tool],
                                env=my_env)



def recent_result(tool, suite):
    results = glob.glob("results/%s.*.%s.xml" % (tool, suite))
    results.sort()
    if len(results) == 0:
        print("No results for %s on suite %s" % (tool, suite))
        exit(-1)
    else:
        return results[-1]

def recent_result_data(tools, suites):
    data = []
    for suite in suites:
        with tempfile.TemporaryDirectory() as tmp_dir:
            p = subprocess.run(['table-generator',
                                '-f', 'csv',
                                '-o', tmp_dir,
                                '-x', 'simplecsv.xml',
                                '-q']
                               + list(map(lambda x: recent_result(x, suite), tools)))
            table = os.path.join(tmp_dir, "simplecsv.table.csv")
            # strip 3 rows of header info
            with open(table) as fd:
                w=fd.readlines()
                with open('/home/rjf/fast/table.csv', 'w+') as fd2:
                    fd2.writelines(w)
            print('------------------')
            data += list(map(lambda row: row.rstrip().split('\t'),
                             open(table).readlines()))[3:]
    return data
    

def help():
        print("Unknown command")
        print('Usage: ./bench.py run --tools tool1[,tool2,...] --suites suite1[,suite2,...]')
        print('Available tools: ')
        print(' gps\t Full GPS algorithm')
        print(' CRA\t Compositional Recurrence Analysis (static analysis only)')
        print(' gpsnogas\t GPS algorithm without gas-instrumentation')
        print(' gpsnogasnosum\t Plain GPS algorithm without gas-instrumentation and summary guidance')
        print(' gpslite\t GPSLite algorithm for summary-guided test generation and execution')
        print(' veriabs\t VeriAbs portfolio model checker (SVCOMP 2024 configuration)')
        print(' cpachecker\t CPAchecker portfolio model checker (SVCOMP 2024 configuration)')
        print(' cpaimpact\t Impact algorithm implementation inside CPAchecker 4.0')
        print(' symbiotic\t Symbiotic symbolic execution tool (SVCOMP 2024 configuration)')
        print('')
        print('Available test suites:')
        print(' Suite1-SVCOMP\t 230 intraprocedural benchmarks with LIA syntax from SVCOMP 2024')
        print(' Suite2-SafeExamples\t 9 safe intraprocedural benchmarks from the GPS paper')
        print(' Suite3a-LockAndKey-Parametric\t 50 parametrizable lock-and-key benchmarks from the GPS paper')
        print(' Suite3b-LockAndKey-NonParametric\t 1 non-parametrizable lock-and-key benchmark from the GPS paper')
        print(' Suite3c-LockAndKey-StateMachines\t 6 state-machine lock-and-key benchmarks from the GPS paper')


if __name__ == "__main__":
    if (len(sys.argv) <= 1):
        print("No command provided")
        help()
        exit(1)
    command = sys.argv[1]
    opts = sys.argv[2:]
    cache = False
    while(len(opts) > 0):
        if (opts[0] == "--timeout"):
            timeout = int(opts[1])
            opts = opts[2:]
        elif (opts[0] == "--tools"):
            tools = opts[1].split(",")
            opts = opts[2:]
        elif (opts[0] == "--suites"):
            suites = opts[1].split(",")
            opts = opts[2:]
        elif (opts[0] == "--no-cache"):
            cache = False
            opts = opts[1:]
        elif (opts[0] == "--replace-cached"):
            cache = False
            replace_cached = True
            opts = opts[1:]
        else:
            print("Unrecognized option: %s" % opts[0])
            exit (-1)

    if (command == "run"):
        run()
    else:
        help()
