import numpy as np;
def GaussWithMainElemInCol(A1: np.ndarray, b1:np.ndarray) ->np.ndarray:
    mA = A1.copy()
    b = b1.copy()
    shape = mA.shape
    for i in range(0, shape[0]):
        #Find max element in the current column
        maxa: float = mA[i][i]
        posOfMaxa: int = i
        for j in range(i+1, shape[0]):
            if (abs(maxa) < abs(mA[j][i])) & (mA[j][i] != 0):
                maxa = mA[j][i]
                posOfMaxa = j
        #Swap vectors 
        mA[[i, posOfMaxa]] = mA[[posOfMaxa, i]]
        b[i], b[posOfMaxa] = b[posOfMaxa], b[i]
        #Remove element in the cur col in other rows
        aii = mA[i][i]
        for j in range(i+1, shape[0]):    
            qji = mA[j][i]/aii
            arri = mA[i]*qji
            mA[j]= mA[j] - arri
            b[j] = b[j] - b[i]*qji

    #Backtracking
    x = np.ndarray(b.shape)
    for i in reversed(range(shape[0])):
        t: float = 0
        for j in range(shape[0] - 1, i, -1):
            t += mA[i][j]*x[j]
        x[i] = (b[i]-t)/mA[i][i]
    return x