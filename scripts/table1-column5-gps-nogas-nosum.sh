#!/bin/bash
set -x

python3 bench.py run --tools gps-nogas-nosum --suites Suite1-SVCOMP
python3 bench.py run --tools gps-nogas-nosum --suites Suite2-SafeExamples
python3 bench.py run --tools gps-nogas-nosum --suites Suite3a-LockAndKey-Parametric
python3 bench.py run --tools gps-nogas-nosum --suites Suite3b-LockAndKey-NonParametric
python3 bench.py run --tools gps-nogas-nosum --suites Suite3c-LockAndKey-StateMachines


