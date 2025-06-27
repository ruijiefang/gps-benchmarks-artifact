import benchexec.util as util
import benchexec.tools.template
import benchexec.result as result

class Tool(benchexec.tools.template.BaseTool):

    def executable(self):
        return ("/gps-ae/duet-gps/duet.exe")

    def name(self):
        return "gpsnogasnosum"

    def determine_result(self, returncode, returnsignal, output, isTimeout):
        output = "\n".join(output)
        if ((returnsignal == 9) or (returnsignal == 15)) and isTimeout:
            status = "TIMEOUT"
        elif returnsignal == 9:
            status = "KILLED BY SIGNAL 9"
        elif "proven safe" in output:
            status = result.RESULT_TRUE_PROP
        #elif returncode != 0:
        #    #status = "ERROR ({0})".format(returncode)
        elif "proven unsafe" in output:
            status = result.RESULT_FALSE_PROP
        else:
            #print('output: ', output)
            status = result.RESULT_UNKNOWN
        return status
