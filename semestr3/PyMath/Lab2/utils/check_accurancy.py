import numpy as np
from conf import eps

def check_accur(vectorA: np.ndarray, vectorB: np.ndarray) -> bool:
    shapeA = vectorA.shape
    shapeB = vectorB.shape
    if(shapeA[0] is not shapeB[0] and shapeA[1] is not shapeB[1]):
        raise f"{vectorA}, {vectorB} is not compatible"
    for i in range(shapeA[0]):
        # for j in range(shapeA[0]):
        if(abs(vectorA[i] - vectorB[i]) > eps):
            return False
    return True