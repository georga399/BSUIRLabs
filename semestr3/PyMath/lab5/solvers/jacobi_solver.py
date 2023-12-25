from utils.sum_non_diag import sum_non_diag
from utils.max_without_diag import max_without_diag
from conf import eps
import numpy as np

def jacobi_solver(A: np.ndarray):
    n = A.shape[0]
    steps = 0
    V = np.eye(n)
    eig_vec = np.eye(n)
    while sum_non_diag(A) > eps:
        max_aij, max_i, max_j = max_without_diag(A)
        if A[max_i, max_i] == A[max_j, max_j]:
            phi = np.pi / 4
        else:
            phi = np.arctan((2 * max_aij) / (2*(A[max_i, max_i] - A[max_j, max_j]))) 
        cos_phi = np.cos(phi)
        sin_phi = np.sin(phi)
        V = np.eye(n)
        V[max_i, max_i] = cos_phi
        V[max_j, max_j] = cos_phi
        V[max_j, max_i] = sin_phi
        V[max_i, max_j] = -sin_phi
        A = V.T @ A @ V
        eig_vec = eig_vec @ V
        steps += 1
    eig_vals = []
    for i in range(n):
        eig_vals.append(A[i, i]) 
    return eig_vals, eig_vec
