import numpy as np

def convert_for_iterations(matrixA: np.ndarray, vectorb:np.ndarray):
    shapeB = vectorb.shape
    shapeA = matrixA.shape
    B: np.ndarray = np.zeros(shapeB, dtype=float)
    A: np.ndarray = np.zeros(shapeA, dtype=float)
    for i in range(shapeB[0]):
        B[i] = vectorb[i]/matrixA[i][i]
    for i in range(shapeA[0]):
        aii = matrixA[i][i]
        for j in range(i):
            A[i][j] = -matrixA[i][j]/aii
        for j in range(i + 1, shapeA[1]):
            A[i][j] = -matrixA[i][j]/aii
    return (A, B)