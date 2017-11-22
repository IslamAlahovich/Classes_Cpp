# -*- coding: utf-8 -*-
"""
Created on Sat Nov 18 11:00:53 2017

@author: User
"""

import numpy as np
from scipy import double
import scipy.integrate as scintegrate
import scipy.special as scispecial
from scipy.misc import derivative
from sympy import symbols, solve
from time import time

def myF(x):
    return abs(np.sin(x))

def Gauss3(a, b):
    #tic = time()
    c1, c2, c3, x1, x2, x3 = symbols("c1, c2, c3, x1, x2, x3")
    Solves = double(solve([c1 + c2 + c3 - (b-a), 
                           c1*x1 + c2*x2 + c3*x3- ((b**2 - a**2)/2), 
                           c1*x1**2 + c2*x2**2 + c3*x3**2 - ((b**3 - a**3)/3), 
                           c1*x1**3 + c2*x2**3 + c3*x3**3 - ((b**4 - a**4)/4), 
                           c1*x1**4 + c2*x2**4 + c3*x3**4 - ((b**5 - a**5)/5), 
                           c1*x1**5 + c2*x2**5 + c3*x3**5 - ((b**6 - a**6)/6)], 
                          [c1, c2, c3, x1, x2, x3])[0])
    I = Solves[0]*myF(Solves[3]) + Solves[1]*myF(Solves[4]) + Solves[2]*myF(Solves[5])
    print("c1: ", Solves[0], "c2: ", Solves[1], "c3: ", Solves[2],
          "x1: ",Solves[3], "x2: ", Solves[4], "x3: ", Solves[5])
    print("I: ", I)
    #toc = time()
    #print("RunTime: ", toc - tic)
    return I

def FGauss3(a, b, n):
    tic = time()
    X = np.linspace(a, b, n)
    I = 0
    for i in range(len(X)-1): 
        print(X[i], X[i+1])
        I += Gauss3(X[i], X[i+1])
    toc = time()
    #print("RunTime: ", toc - tic)
    #print("Difference: ", abs(RealI - I))
    #print("TheorDifference: ", )
    return I

a = -2
b = 2
RealI = scintegrate.quad(myF, -2, 2)[0]
#print(RealI)
print(FGauss3(a, b, 3))
print(RealI)
print(FGauss3(a, b, 4))
print(RealI)
#print(FGauss3(a, b, 12))
#print(RealI)
#print(FGauss3(a, b, 20))
#print(RealI)
#print(FGauss3(a, b, 64))