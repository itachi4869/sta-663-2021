import cppimport
import numpy as np

ex7 = cppimport.imp("ex7")

if __name__ == '__main__':
    xs = np.arange(12).reshape(3,4).astype('float')
    print(xs)
    print("np :", xs.sum())
    print("cpp:", ex7.sum(xs))

    print()
    ex7.twice(xs)
    print(xs)
