#cython: language_level=3

import cython
from cython.parallel import prange
from libcpp cimport bool

cdef extern from "math.h":
    double sqrt(double m) nogil

import numpy as np
cimport numpy as np

cdef bint is_prime(int n) nogil:
    cdef int i
    cdef int k = int(sqrt(n))

    if n <= 1:
        return 0
    
    for i in range(2, k + 1):
        if n % i == 0:
            return 0

    return 1


@cython.boundscheck(False)
def is_prime_between(int start, int stop):
    bool_map = list(map(is_prime, range(start, stop)))
    return np.arange(start, stop)[bool_map]

@cython.boundscheck(False)
def is_prime_between_parallel(int start, int stop):
    cdef int i
    cdef int [:] bool_map = np.zeros(stop - start, dtype=np.int32)
    for i in prange(start, stop, nogil=True):
        bool_map[i - start] = is_prime(i)
    return np.arange(start, stop)[bool_map]
