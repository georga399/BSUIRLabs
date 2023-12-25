import numpy as np
from fractions import Fraction
from conf import eps, variantk, count_of_tests
from algos.simple_iteration import simple_iteration
from algos.Seidel_method import Seidel_solve
from utils.correct_zeros import correct_zeros
from utils.check_col_dominance import check_col_dominance
from utils.check_line_dominance import check_line_dominance
from utils.check_sqrt import check_sqrt
from utils.spectrum_check import spectrum_check
from utils.convert_for_iterations import convert_for_iterations
from utils.read_frac import read_frac_matr, read_frac_vector
from algos.Gauss import GaussWithElOnMatr
from utils.validate_ans import validate_ans
from utils.check_max_col import check_max_col
from utils.check_max_line import check_max_line

def run_tests():
    for i in range(count_of_tests):
        print(f"...............Running test #{i+1}...............")
        matrixD = np.genfromtxt(f"datasets/test{i+1}/D.csv", delimiter=", ", dtype=float)
        matrixC = np.genfromtxt(f"datasets/test{i+1}/C.csv", delimiter=", ", dtype=float)
        vectorb = np.genfromtxt(f"datasets/test{i+1}/b.csv", delimiter=", ", dtype=float)
        print("Input data:")
        print("Matrix D:")
        print(matrixD)
        print("Matrix C:")
        print(matrixC)
        print("Vector b:")
        print(vectorb)
        matrixA: np.ndarray = variantk*matrixC + matrixD
        print(f"Matrix A = {variantk}*C + D:")
        print(matrixA)
        if not correct_zeros(matrixA, vectorb):
            print("STATUS: Cannot remove zeros from matrix A.")
            continue
        iterA, iterB = convert_for_iterations(matrixA, vectorb)
        if not check_max_line(iterA) and not check_max_col(iterA) and\
          not check_sqrt(iterA) and not spectrum_check(iterA):
            print("STATUS: Covergence conditions are not met") 
            continue
        print("X = (Method 1)")
        x1:np.ndarray = simple_iteration(iterA, iterB)
        print(x1)
        print("X = (Method 2 Seidel)")
        x2:np.ndarray = Seidel_solve(iterA, iterB)
        print(x2)
        print("Solving equations with fractions")
        fracD = read_frac_matr(f"datasets/test{i+1}/D.csv")
        fracC = read_frac_matr(f"datasets/test{i+1}/C.csv")
        fracb = read_frac_vector(f"datasets/test{i+1}/b.csv")
        fracA = variantk*fracC + fracD
        print("Matrix A in fractions:")
        for i in fracA:
            line: str = ""
            for j in i:
                line += str(j) + " "
            print(line)
        print("Vector b in fractions:")
        line: str = ""
        for j in fracb:
            line += str(j) + " "
        print(line)
        fracX = GaussWithElOnMatr(fracA, fracb)
        print("vector x in fractions:")
        line: str = ""
        for j in fracX:
            line += str(j) + " "
        print(line)
        if(validate_ans(fracX, x2)):
            print("STATUS: OK")
        else:
            print("STATUS: COMPULATION ERROR")
        
if __name__ == "__main__":
    run_tests()