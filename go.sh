#!/bin/bash

set -x

g++ \
	-shared \
	-std=c++11 \
	-fPIC \
	$(python3 -m pybind11 --includes) \
	py2cpp.cpp \
	-o py2cpp$(python3-config --extension-suffix)

pip install mypy

stubgen -m py2cpp -o .

./py_call_cpp.py

