import numpy as np

def check_max_col(A: np.ndarray) -> bool:
    shape = A.shape
    max_col = sum(abs(A[:, 0]))
    for i in range(1, shape[0]):
        max_col = max(sum(abs(A[:, i])), max_col)
    if(max_col < 1):
        return True
    return False