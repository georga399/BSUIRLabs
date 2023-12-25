import numpy as np

def max_without_diag(matrix):
    n = matrix.shape[0]
    max_a = matrix[0, 1]
    max_i = 0
    max_j = 1
    for i in range(n):
        for j in range(i + 1, n):
            if abs(matrix[i, j]) > abs(max_a):
                max_a = matrix[i, j]
                max_i = i
                max_j = j

    return max_a, max_i, max_j