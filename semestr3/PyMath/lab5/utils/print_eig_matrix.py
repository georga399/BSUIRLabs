import numpy as np

def print_eig_matrix(matrix: np.ndarray):
    n = matrix.shape[0]
    for j in range(n):
        print(f"Eigenvector: {matrix[:, j]}")