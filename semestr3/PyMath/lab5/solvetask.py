import numpy as np
from conf import eps, variantk
from utils.print_eig_matrix import print_eig_matrix
from utils.print_eig_vals import print_eig_vals
from solvers.jacobi_solver import jacobi_solver
from solvers.bin_solver import bin_solver

def solvetask(test_id):
    print(f'Processing test {test_id}..............')
    matrixC = np.genfromtxt(f'data/test{test_id}/C.csv', delimiter=', ', dtype=float)
    matrixD = np.genfromtxt(f'data/test{test_id}/D.csv', delimiter=', ', dtype=float)
    matrixA = variantk*matrixC + matrixD
    eig_vals, eig_vects = jacobi_solver(matrixA)
    print("Matrix A:")
    print(matrixA)
    print("Jacobi method:")
    print_eig_vals(eig_vals)
    print_eig_matrix(eig_vects)
    print("Bisection method:")
    for v in eig_vals:
        print(f"Eigen val: {round(bin_solver(matrixA, v-0.5, v+0.5), 4)}")
    print("Numpy method:")
    eig_vals, eig_vects = np.linalg.eig(matrixA)
    print_eig_vals(eig_vals)
    print_eig_matrix(eig_vects)