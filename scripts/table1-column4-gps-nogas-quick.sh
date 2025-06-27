#!/bin/bash
set -x

python3 bench.py run --timeout 200 --tools gpsnogas --suites Suite1-SVCOMP
python3 bench.py run --timeout 200 --tools gpsnogas --suites Suite2-SafeExamples
python3 bench.py run --timeout 200 --tools gpsnogas --suites Suite3a-LockAndKey-Parametric
python3 bench.py run --timeout 200 --tools gpsnogas --suites Suite3b-LockAndKey-NonParametric
python3 bench.py run --timeout 200 --tools gpsnogas --suites Suite3c-LockAndKey-StateMachines


