from solvetask import solvetask
from conf import tests_count
import numpy as np

def main():
    np.set_printoptions(suppress=True, precision=4, floatmode="fixed")
    for i in range(tests_count):
        solvetask(i)

if __name__ == '__main__':
    main()