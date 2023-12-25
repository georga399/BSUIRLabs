from interpolations.lagrange_interpolation import lagrange_interpolation
from interpolations.newton_interpolation import newton_interpolation
from conf import k, m
import numpy as np
from sympy import *
# from find_error import find_error

def task(testNum: int, point):
    data = np.genfromtxt(f"dataset/test{testNum}.csv", delimiter=', ')
    x = data[0]
    y = data[1]
    if(testNum == 0):
        y = y + (-1)**k * m
    print(f"vector of x: {x}")
    print(f"vector of y: {y}")
    print(f"point x: {point[0]}")
    lag = lagrange_interpolation(x, y)
    print(f"Lagrange polynomial: L(x) = {lag}")
    print(f"Lagrange polynomial in the point: L({point[0]}) = {lag.subs(symbols('x'), point[0])}")
    newton = newton_interpolation(x, y)
    print(f"Newton polynomial: N(x) = {newton}")
    print(f"Newton polynomial in the point: N({point[0]}) = {newton.subs(symbols('x'), point[0])}")
    # if (testNum != 0):
    #     file = open(f"dataset/func{testNum}.txt", 'r')
    #     funcexpr = sympify(file.readline())
    #     er = find_error(x, y, point[1], funcexpr)
    #     if (er is not None):
    #         print(er)