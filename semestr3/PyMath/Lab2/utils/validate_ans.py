import numpy as np
from conf import eps

def validate_ans(x1:np.ndarray, x2:np.ndarray) -> bool:
    for i in range(x1.shape[0]):
        if(abs(x1[i] - x2[i]) > eps):
            return False
    return True