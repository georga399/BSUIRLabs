import numpy as np

def correct_zeros(A: np.ndarray, b: np.ndarray):
    shape = A.shape
    for i in range(shape[0]):
        aii = A[i][i]
        changed:bool = False
        if aii == 0:
            for j in range(shape[0]):
                if(A[j][i] != 0 and A[i][j] != 0):
                    A[[i, j]] = A[[j, i]]
                    b[[i, j]] = b[[j, i]]
                    changed = True
                    break
            if not changed:
                return False
    return True