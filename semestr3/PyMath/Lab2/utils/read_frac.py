from fractions import Fraction
import csv
import numpy as np

def read_frac_matr(path: str):
    matrixD = np.ndarray(dtype=Fraction, shape=0)
    with open(path, 'r') as x:
        sample_data = list(csv.reader(x, delimiter=","))
        # print(sample_data)
    matrixD = np.empty(shape=[len(sample_data), len(sample_data)], dtype=Fraction)
    for i in range(0, len(sample_data)):
        for j in range(0, len(sample_data)): 
            matrixD[i][j] = Fraction(sample_data[i][j])
    return matrixD


def read_frac_vector(path: str):
    with open(path, 'r') as x:
        vect = np.empty(shape=0, dtype=Fraction)
        csvreader = csv.reader(x)
        for row in csvreader:
            for c in row:
                vect = np.append(vect, [Fraction(c)])
        return vect