import numpy as np
from conf import eps
from utils.check_accurancy import check_accur
# from utils.is_correct import is_correct


def simple_iteration(A: np.ndarray, B: np.ndarray) -> np.ndarray:
    shapeB = B.shape
    shapeA = A.shape
    xk1: np.ndarray = B.copy()
    xk0: np.ndarray = np.zeros(shapeB)
    counter = 0
    while(not check_accur(xk0, xk1)):
        counter += 1
        xk0 = xk1.copy()
        for i in range(shapeA[0]):
            xk1[i] = B[i]
            for j in range(i):
                xk1[i] += A[i][j]*xk0[j]
            for j in range(i+1, shapeA[1]):
                xk1[i] += A[i][j]*xk0[j]
    print(f"iterations: {counter}")
    return xk1