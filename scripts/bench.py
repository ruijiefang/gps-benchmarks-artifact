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
        'cpachecker': '/gps-ae/CPAchecker-2.3-unix/',
        'cpaimpact': '/gps-ae/CPAchecker-2.3-unix/',
        'gps' : '/gps-ae/duet-gps/',
        'gpslite' : '/gps-ae/duet-gps/',
        'symbiotic': '/gps-ae/symbiotic/bin/',
}
suites = []
tools = []

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
            if replace_cached and has_result(tool,suite):
                recent = recent_result(tool, suite)
                os.remove(recent)

            if cache and has_result(tool, suite):
                print("Result of %s on suite %s is cached" % (tool, suite))
            else:
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
                                '6',
                                '--allowedCores', # https://github.com/sosy-lab/benchexec/issues/850
                                '0-5',
                                "--no-container",
                                "--no-tmpfs",
                                "-W", str(timeout),
                                 "-t", suite,
                                 "benchmark-defs/%s.xml" % tool],
                                env=my_env)
                else:
                    subprocess.call(["benchexec",
                                '-M',
                                '15GB',
                                '--allowedCores', # https://github.com/sosy-lab/benchexec/issues/850
                                '0-5',
                                '--tool-directory',
                                toolbins[tool],
                                "--no-container",
                                "--no-tmpfs",
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
    

if __name__ == "__main__":
    if (len(sys.argv) <= 1):
        print("No command provided")

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
        print("Unknown command")
