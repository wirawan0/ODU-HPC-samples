#!/usr/bin/env python
#
# Created: 20170227

# Note: In a python program or function, if the first statement
# encountered is a string literal like this, it will be taken as the
# documentation (__doc__) of the program/function.

"""
matmul1.py

Demo program to read two matrices, performs multiplication, and prints
the output to standard output.

This program has some pedagogical value in demonstrating the effect of
hand-crafting loops in python as opposed to using
matrix-multiplication kernel (canned routine).

"""

from __future__ import print_function
import sys
import numpy
from np_helper import loadmatrix1, printmatrix1

def matmul_manual(A, B):
    """Performs manual matrix multiplication with python.
    Avoid doing this in python because of low performance!
    """
    from numpy import asarray, sum
    A = asarray(A)
    B = asarray(B)
    M, K = A.shape
    N = B.shape[1]
    assert A.shape[1] == B.shape[0]
    # Caveat: works only if A & B dtypes are the same:
    C = numpy.zeros((M,N), dtype=A.dtype)
    for i in range(M):
        for j in range(N):
            Cij = 0
            for k in range(K):
                Cij += A[i,k] * B[k,j]
            C[i,j] = Cij
    return C


def matmul_vecdot(A, B):
    """Performs semi-manual matrix multiplication with python,
    using dot product in the innnermost loop.
    """
    from numpy import asarray, sum
    A = asarray(A)
    B = asarray(B)
    M, K = A.shape
    N = B.shape[1]
    assert A.shape[1] == B.shape[0]
    # Caveat: works only if A & B dtypes are the same:
    C = numpy.zeros((M,N), dtype=A.dtype)
    for i in range(M):
        for j in range(N):
            C[i,j] = sum(A[i,:] * B[:,j])
    return C



def matmul_matdot(A, B):
    """Performs matrix multiplication with python using numpy.dot.

    Note that numpy.dot is equivalent to matrix-matrix multiplication
    for 2-D arrays; we explot this fact here!
    """
    from numpy import asarray, sum
    A = asarray(A)
    B = asarray(B)
    M, K = A.shape
    N = B.shape[1]
    assert A.shape[1] == B.shape[0]
    C = numpy.dot(A, B)
    return C



def matmul1(argv):
    if len(argv) < 3:
        print("Needs an input file name on arg1", file=sys.stderr)
        sys.exit(1)

    matfile1 = argv[1]
    matfile2 = argv[2]
    A = loadmatrix1(matfile1)
    B = loadmatrix1(matfile2)
    C = matmul_matdot(A,B)
    printmatrix1(C, float_fmt=" %12.6f")
    #printmatrix1(C)

if __name__ == "__main__":
    matmul1(sys.argv)
