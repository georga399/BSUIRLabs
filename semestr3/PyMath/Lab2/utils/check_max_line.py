import numpy as np

def check_max_line(A: np.ndarray) -> bool:
    shape = A.shape
    max_line = sum(abs(A[0]))
    for i in range(1, shape[0]):
        max_line = max(sum(abs(A[i])), max_line)
    if(max_line < 1):
        return True
    return False