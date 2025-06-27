#!/bin/bash

python3 bench.py run --tools cpachecker --suites Suite1-SVCOMP
python3 bench.py run --tools cpachecker --suites Suite2-SafeExamples
python3 bench.py run --tools cpachecker --suites Suite3a-LockAndKey-Parametric
python3 bench.py run --tools cpachecker --suites Suite3b-LockAndKey-NonParametric
python3 bench.py run --tools cpachecker --suites Suite3c-LockAndKey-StateMachines

