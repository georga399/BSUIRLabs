import numpy as np
from GaussSolve.SequentialGauss import SeqGauss
from GaussSolve.GaussWithMainElemInCol import GaussWithMainElemInCol
from GaussSolve.GaussWithMainElemOnMatr import GaussWithElOnMatr
matrixD = np.genfromtxt("datasets/D.csv", delimiter=" ",dtype=float)
#matrixC = np.genfromtxt("datasets/C.csv", delimiter=", ", dtype=float)
vectorb = np.genfromtxt("datasets/b.csv", delimiter=" ", dtype=float)
variantk = 2
matrixA:np.ndarray = matrixD
print("..............Matix A..............")
print(matrixA)
print("..............Vector b..............")
print(vectorb)
vectorX1 = SeqGauss(matrixA, vectorb)
vectorX2 = GaussWithMainElemInCol(matrixA, vectorb)
vectorX3 = GaussWithElOnMatr(matrixA, vectorb)
print("..............Vector X1..............")
print(vectorX1)
print("..............Vector X2..............")
print(vectorX2)
print("..............Vector X3..............")
print(vectorX3)
vectorX4 = np.linalg.solve(matrixA, vectorb)
print("..............Vector X4..............")
print(vectorX4)