import numpy as np

def spectrum_check(A: np.ndarray) -> bool:
    return np.linalg.norm(A, ord=2) < 1
