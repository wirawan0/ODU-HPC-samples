#
# module np_helper.py
# Convenience functions for the python HPC demo programs
#

import sys
import numpy
import contextlib

def loadmatrix1(filename):
    """Saves a 2-D numpy array to a text file.
    The output is written in the simple "MATRIX" format.
    """
    with open(filename, "r") as F:
        header = next(F).split()
        # The header should contain 3 elements:
        # "MATRIX", numrows, numcols
        assert header[0].upper() == "MATRIX"
        numrows, numcols = int(header[1]), int(header[2])
        M = numpy.loadtxt(F)
        assert M.shape == (numrows, numcols)
    return M


def savematrix1(M, filename, fmt="%.18e"):
    """Saves a 2-D numpy array to a text file.
    The output is written in the simple "MATRIX" format.

    By default, a full double precision format is used.
    If you know exactly the precision of your values, you can avoid
    printing so much by overriding the `fmt` field, e.g. to"%10.3f".
    """
    assert len(M.shape) == 2
    Rows, Cols = M.shape
    with open(filename, "w") as F:
        numpy.savetxt(F, M,
                      fmt=fmt,
                      header="MATRIX %d %d" % (Rows, Cols),
                      comments="")


def printmatrix0(M, outF=sys.stdout):
    """Prints matrix using Numpy's default matrix printing.

    This does not look good, generally, unless you already tweak the
    print options using `numpy.set_printoptions`.
    """
    outF.write(str(M))
    outF.write("\n")
    # In python 2, the above lines can be replaced by
    #     print >>outF, str(M)
    outF.flush()



@contextlib.contextmanager
def printoptions(*args, **kwargs):
    """Using the `with` context to temporarily set numpy's print
    options in python:
    
    http://stackoverflow.com/questions/2891790/how-to-pretty-printing-a-numpy-array-without-scientific-notation-and-with-given

    See also: numpy.set_printoptions help page.
    """
    original = numpy.get_printoptions()
    numpy.set_printoptions(*args, **kwargs)
    yield
    numpy.set_printoptions(**original)


def printmatrix1(M, outF=sys.stdout,
                 float_fmt=' %7.3f',
                 #float_fmt=None,
                 linewidth=99999,
                 **printopts):
    """Advanced matrix printing--allows locally setting the precision,
    formatting, etc.

    Note that some defaults have been altered here for my desired behavior.
    """
    formatter = printopts.get("formatter", None)
    def_dict = lambda f : f if (f is not None) else {}
    if float_fmt is not None:
        formatter = def_dict(formatter)
        if callable(float_fmt):
            proc_float_fmt = float_fmt
        else:
            proc_float_fmt = lambda x : float_fmt % x
        formatter['float'] = proc_float_fmt

    with printoptions(formatter=formatter,
                      linewidth=linewidth,
                      **printopts) as FF:
        outF.write(str(M))
        outF.write("\n")
    outF.flush()

