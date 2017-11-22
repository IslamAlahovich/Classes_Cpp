# -*- coding: utf-8 -*-
"""
Created on Sun Nov 19 11:31:38 2017

@author: User
"""

import numpy as np
from scipy.misc import derivative

def myEq(x):
    return x**3 - 2.2 * x**2 + 1.56 * x - 0.36 #x**2 - np.sin(x) - 1

def M(a, b, k):
    X = np.linspace(a, b, 100)
    M = derivative(myEq, a, dx=1e-6, n=k)
    for i in X:
        if((derivative(myEq, i, dx=1e-6, n=k)) > M): M = derivative(myEq, a, dx=1e-6, n=k)
    return M

def m(a, b, k):
    X = np.linspace(a, b, 100)
    m = derivative(myEq, a, dx=1e-6, n=k)
    for i in X:
        if((derivative(myEq, i, dx=1e-6, n=k)) < m): m = derivative(myEq, a, dx=1e-6, n=k)
    return m

def dich(a, b):
    X = np.linspace(a, b, 1000)
    dX = [[X[i], X[i+1]] for i in range(len(X)-1) if (myEq(X[i]) >= 0 and myEq(X[i+1]) <= 0) or (myEq(X[i]) <= 0 and myEq(X[i+1]) >= 0)]
    ROOTS = []
    
    for i in dX:
        while(abs(i[0] - i[1]) > (1e-10)):
                mid = (i[0] + i[1])*0.5
                if (myEq(i[0]) < 0 and myEq(mid) > 0) or (myEq(i[0]) > 0 and myEq(mid) < 0): 
                    i[1] = mid
                else:
                    i[0] = mid
        ROOTS.append(i[0])
    return(ROOTS)

def eazyE(a, b):
    x = 1 #uniform(a, b)
    tau = 2 / (M(a, b, 1) + m(a, b, 1))
    while(abs(myEq(x)) >= 1e-10): 
        x = x + tau * myEq(x)
    return x

def Newton(a, b):
    X = np.linspace(a, b, 100)
    for i in X:
        if((myEq(i)*(derivative(myEq, i, dx=1e-6, n=2))) > 0):
            x = i
            break
    while(abs(myEq(x)) >= 1e-10): 
        tau = derivative(myEq, x, dx=1e-6, n=1)
        x = x - myEq(x)/tau
    return x

def Chord(a, b):
    X = np.linspace(a, b, 100)
    for i in X:
        if((myEq(i)*(derivative(myEq, i, dx=1e-6, n=2))) > 0):
            x0 = i
            break
    for i in X:
        if((myEq(i) * myEq(x0)) < 0):
            x = i
            break
    while(abs(myEq(x)) >= 1e-10): 
        tau = (x - x0)/(myEq(x) - myEq(x0))
        x = x - myEq(x)*tau
    return x

def Secant(a, b):
    X = np.linspace(a, b, 100)
    for i in X:
        if((myEq(i)*(derivative(myEq, i, dx=1e-6, n=2))) > 0):
            x0 = i
            break
    for i in X:
        if((myEq(i) * myEq(x0)) < 0):
            x1 = i
            break
    while(abs(myEq(x1)) >= 1e-10): 
        tau = (x1 - x0)/(myEq(x1) - myEq(x0))
        x2 = x1 - myEq(x1)*tau
        x0, x1 = x1, x2
    return x1

def Cheb(a, b):
    x = 1
    while(abs(myEq(x)) >= 1e-10):
        dmyEq = derivative(myEq, x, dx=1e-6, n=1)
        d2myEq = derivative(myEq, x, dx=1e-6, n=2)
        x = x - (myEq(x) / dmyEq) - ((d2myEq * myEq(x)**2) / (2 * dmyEq**3))
    return x

def Parab(a, b):
    x0 = 0
    x1 = -1
    x2 = 1
    while(abs(myEq(x2)) >= 1e-10):
        a = (myEq(x2) / ((x2 - x0) * (x2 - x1))) + (myEq(x1) / ((x1 - x2) * (x1 - x0))) + (myEq(x0) / ((x0 - x2) * (x0 - x1)))
        b = ((myEq(x2) - myEq(x1)) / (x2 - x1)) + (x2 - x1) * a
        c = myEq(x2)
        z1 = (-b + np.sqrt(b**2 - 4 * a * c)) / 2 * a
        z2 = (-b - np.sqrt(b**2 - 4 * a * c)) / 2 * a
        if(abs(z1) > abs(z2)): z1 = z2
        x0, x1 = x1, x2
        x2 = x2 + z1
    return x2
print(eazyE(-1, 2))
print(Newton(-1, 2))
print(Chord(-1, 2))
print(Secant(-1, 2))
print(Cheb(-1, 2))
print(Parab(-1, 2))