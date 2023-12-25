import numpy as np

def check_col_dominance(A: np.ndarray):
    shape = A.shape
    for i in range(shape[0]):
        dom = A[i][i]
        sum = 0
        for j in range(i):
            sum += A[j][i]
        for j in range(i + 1, shape[0]):
            sum += A[j][i]
        return dom > sum