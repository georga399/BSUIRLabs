import numpy as np

def check_line_dominance(A: np.ndarray):
    shape = A.shape
    for i in range(shape[0]):
        dom = A[i][i]
        sum = 0
        for j in range(i):
            sum += A[i][j]
        for j in range(i + 1, shape[0]):
            sum += A[i][j]
        return dom > sum
        