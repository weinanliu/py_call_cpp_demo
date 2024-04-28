#!/bin/bash

set -x

pip install pybind11 mypy

g++ \
	-shared \
	-std=c++11 \
	-fPIC \
	$(python3 -m pybind11 --includes) \
	py2cpp.cpp \
	-o py2cpp$(python3-config --extension-suffix)

stubgen -m py2cpp -o .

./py_call_cpp.py

