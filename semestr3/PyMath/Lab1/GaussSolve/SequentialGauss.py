import numpy
def SeqGauss(A1: numpy.ndarray, b1: numpy.ndarray) -> numpy.ndarray:
    A = A1.copy()
    b = b1.copy()
    shape = A.shape

    #Simple diagonalizing
    for i in range(shape[0]):
        aii = A[i][i]
        for j in range(i+1, shape[0]):
            qji = A[j][i]/aii
            arri = A[i]*qji
            A[j]-=arri
            b[j]-= b[i]*qji
    #Backtracking
    x = numpy.ndarray(b.shape)
    for i in reversed(range(shape[0])):
        t: float = 0
        for j in range(shape[0] - 1, i, -1):
            t += A[i][j]*x[j]
        x[i] = (b[i]-t)/A[i][i]
    return x