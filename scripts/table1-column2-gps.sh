#!/bin/bash
set -x

python3 bench.py run --tools gps --suites Suite1-SVCOMP
python3 bench.py run --tools gps --suites Suite2-SafeExamples
python3 bench.py run --tools gps --suites Suite3a-LockAndKey-Parametric
python3 bench.py run --tools gps --suites Suite3b-LockAndKey-NonParametric
python3 bench.py run --tools gps --suites Suite3c-LockAndKey-StateMachines

