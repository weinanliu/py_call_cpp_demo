#!/bin/env python

import py2cpp
from py2cpp import CT
from py2cpp import add

c = CT()
c.set([0,1,2,3])  # pybind11可支持npy
res = c.fun()
print(res)

print(add(1, 2))


one_dict = {"host0_cuda0": 1, "host0_cuda1": 2}
py2cpp.printDict(one_dict)

class A:
    def __init__(self):
        self.ha = 1

    def fun(self, i: int):
        return i + self.ha


A_ins = A()
py2cpp.callback_pythonfun(A_ins.fun)
