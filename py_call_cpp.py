#!/bin/python

from py2cpp import CT
from py2cpp import add

c = CT()
c.set([0,1,2,3])  # pybind11可支持npy
res = c.fun()
print(res)

print(add(1, 2))
