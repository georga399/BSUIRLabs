from sympy import *
import numpy as np

def find_error(x: np.array, y: np.array, point, expr):
    n = x.shape[0]
    w = 0
    xsym = symbols('x')
    for i in range(n):
        w *= (xsym - x[i])
    wp = np.abs(w.subs(xsym, point))
    for i in range(1, n):
        wp /= i
    dirav = diff(expr, xsym, n)
    dir: float
    if(dirav is not None):
        dir = dirav.subs(xsym, point)
    return dir*wp
    