#!/usr/bin/env python

import sys
import random

def write_matrix(M, F):
    Rows = len(M)
    Cols = len(M[0])
    if isinstance(F, basestring):
        with open(F, "w") as FF:
            write_matrix(M, FF)
    else:
        F.write("MATRIX %d %d\n" % (Rows, Cols))
        F.write("\n".join(" ".join("%6.2f" % c for c in r) for r in M))
        F.write("\n")


def generate_matrix02():
    from random import seed, randint
    Rows = 5
    Cols = 3
    MaxRange = 9999
    StartSeed = 872641
    MatFilename = "matrix02.in"
    # List comprehension makes the expression really short.
    seed(StartSeed)
    rmat = [
             [ randint(-MaxRange,MaxRange)*0.01 for c in xrange(Cols) ]
             for r in xrange(Rows)
           ]
    print(rmat)

    # Without list comprehension, the expression below would equal
    # a double loop like this:
    seed(StartSeed)
    rmat2 = []
    for r in xrange(Rows):
        rowvec = []
        # build up a row at a time:
        for c in xrange(Cols):
            rowvec += [ randint(-MaxRange,MaxRange)*0.01 ]
        rmat2 += [rowvec]

    print("rmat:")
    write_matrix(rmat, MatFilename)
    write_matrix(rmat, sys.stdout)
    print("")
    print("rmat2: (cross-check)")
    write_matrix(rmat2, sys.stdout)
    

if __name__ == "__main__":
    generate_matrix02()
