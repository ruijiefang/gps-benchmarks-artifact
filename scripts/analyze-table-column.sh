#!/bin/bash

GREEN="" #'\033[0;32m'
NC="" #'\033[0m' # No Color

tool=$1

if [ -z "$1" ]; then
  echo "Error: need to specify a tool name as input."
  echo "usage: ./analyze-tool.sh <tool name>"
  echo " Available tools: "
  echo "  CRA gps gpsnogas gpsnogasnosum gpslite cpaimpact cpachecker veriabs symbiotic"
  echo " (Please make sure XML file outputs for the corresponding tool exist in the results/ folder.)"
  exit 1
fi

echo "--------------------------------------"
echo "Analyzing benchexec output for tool"$1
echo "--------------------------------------"

xmls=`ls results/ | grep $tool | grep xml`
for xml in $xmls; do
	echo " + Generating CSV file from XML output "$xml
	table-generator results/$xml
done

suite1_csv=""
suite2_csv=""
suite3a_csv=""
suite3b_csv=""
suite3c_csv=""

check_suite_csv() {
  local tool="$1"
  local suite="$2"
  local matches
  matches=($(ls results | grep "$tool" | grep "$suite" | grep csv))

  if [ "${#matches[@]}" -eq 1 ]; then
    local suite_csv="${matches[0]}"
    echo "$suite_csv"
  else
    echo -e "\n\nBad: expected exactly one CSV file for $suite, but found ${#matches[@]}:\n\n"
    echo ""
    ls results | grep CRA | grep "$suite" | grep csv
    echo ""
    echo -e "\n\nExiting... Retain only one CSV file in results/ folder before continuing.\n"
    exit 1
  fi
}

suite1_csv=$(check_suite_csv $tool Suite1) || { 
	echo $suite1_csv; exit 1 
}
suite2_csv=$(check_suite_csv $tool Suite2) || { 
	echo $suite2_csv; exit 1 
}
suite3a_csv=$(check_suite_csv $tool Suite3a) || { 
	echo $suite3a_csv; exit 1 
}
suite3b_csv=$(check_suite_csv $tool Suite3b) || { 
	echo $suite3b_csv; exit 1 
}
suite3c_csv=$(check_suite_csv $tool Suite3c) || { 
	echo $suite3c_csv; exit 1 
}

echo "Analyzing output of ${GREEN}suite 1${NC} for tool "$tool" from "$suite1_csv

python3 oopsla25-easybench/analyze-tool.py $tool `pwd`/results/$suite1_csv FALSE

echo "Analyzing output of ${GREEN}suite 2${NC} for tool "$tool" from "$suite2_csv 

python3 oopsla25-easybench/analyze-tool.py $tool `pwd`/results/$suite2_csv TRUE

echo "Analyzing output of ${GREEN}suite 3a${NC} for tool "$tool" from "$suite3a_csv 

python3 oopsla25-easybench/analyze-tool.py $tool `pwd`/results/$suite3a_csv FALSE

echo "Analyzing output of ${GREEN}suite 3b${NC} for tool "$tool" from "$suite3b_csv 

python3 oopsla25-easybench/analyze-tool.py $tool `pwd`/results/$suite3b_csv FALSE

echo "Analyzing output of ${GREEN}suite 3c${NC} for tool "$tool" from "$suite3c_csv

python3 oopsla25-easybench/analyze-tool.py $tool `pwd`/results/$suite3c_csv FALSE



