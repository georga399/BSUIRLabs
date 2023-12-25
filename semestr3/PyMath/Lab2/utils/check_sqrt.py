import numpy as np

def check_sqrt(A: np.ndarray) -> bool:
    shape = A.shape
    sum = 0
    for i in range(shape[0]):
        for j in range(shape[1]):
            sum += A[i][j]*A[i][j]
    return np.sqrt(sum) < 1