import numpy as np
from conf import eps

def bin_solver(matrix: np.ndarray, left: float, right: float):
    n = matrix.shape[0]
    while (right - left) < eps:
        mid = (right - left)/2
        mid_matrix = matrix - np.diag([mid]*n)
        left_matrix = matrix - np.diag([left]*n)
        mid_det = np.linalg.det(mid_matrix)
        left_det = np.linalg.det(left_matrix)
        if(mid_det*left_det > 0):
            left = mid
        else:
            right = mid
    return (right + left)/2