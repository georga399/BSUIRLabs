import numpy as np

def sum_non_diag(matrix: np.ndarray):
    n = matrix.shape[0]
    sum = 0
    for i in range(n):
        for j in range(0, i):
            sum += abs(matrix[i, j])
        for j in range(i+1, n):
            sum += abs(matrix[i, j])
        return sum