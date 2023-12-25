import numpy as np
def GaussWithElOnMatr(A1: np.ndarray, b1: np.ndarray) -> np.ndarray:
    A = A1.copy()
    b = b1.copy()
    shape = A.shape
    shiftX = np.eye(shape[0], dtype=float)
    for i in range(0, shape[0]):
        #Find max element in the current column
        maxEl: float = A[i][i]
        RowOfMax: int = i
        ColOfMax: int = i
        for j in range(i+1, shape[0]):
            for l in range(i+1, shape[1]):
                if (abs(maxEl) < abs(A[j][l])):
                    maxEl = A[j][l]
                    RowOfMax = j
                    ColOfMax = l
        #Swap raws 
        A[[i, RowOfMax]] = A[[RowOfMax, i]]
        b[i], b[RowOfMax] = b[RowOfMax], b[i]
        #Swap columns
        A[:, [i, ColOfMax]] = A[:, [ColOfMax, i]]
        shiftX[:, [i, ColOfMax]] = shiftX[:, [ColOfMax, i]]
        #Remove element in the cur col in other rows
        aii = A[i][i]
        for j in range(i+1, shape[0]):    
            qji = A[j][i]/aii
            arri = A[i]*qji
            A[j]= A[j] - arri
            b[j] = b[j] - b[i]*qji
    #Backtracking
    x = np.ndarray(b.shape)
    for i in reversed(range(shape[0])):
        t: float = 0
        for j in range(shape[0] - 1, i, -1):
            t += A[i][j]*x[j]
        x[i] = (b[i]-t)/A[i][i]
    return np.matmul(shiftX, x) #Multiply vector X by shift