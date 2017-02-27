/************************************************************************\

    matmul1.cpp
    A demo program to read two matrices, performs multiplication, and
    optionally saving it to a text file

    Created: 20170224

\************************************************************************/

#include <iostream>
#include <fstream>
#include <Matrix.hpp>

#include <cstdlib>

//  Performs C = A * B
//  Dimensions:
//    - A(M,K)
//    - B(K,N)
//    - C(M,N)
template <typename _number>
void matrix_multiply(const Matrix<_number> &A,
                     const Matrix<_number> &B,
                     Matrix<_number> &C)
{
    int M = A.numrows();
    int K = A.numcols();
    int N = C.numcols();
    assert(K == B.numrows());
    assert(N == B.numcols());
    int im,ik,in;

    for (im = 0; im < M; ++im)
    {
        for (in = 0; in < N; ++in)
        {
            _number Cmn = 0;
            for (ik = 0; ik < K; ++ik)
                Cmn += A(im,ik) * B(ik,in);
            C(im,in) = Cmn;
        }
    }
}

void matmul1(const char *infile1,
             const char *infile2,
             const char *outfile)
//  read1: Reads a matrix from a file and prints it to stdout
{
    using std::cout;
    using std::cerr;
    using std::endl;

    cout << "## matmul1 ## infile1=" << infile1
         << " infile2=" << infile2 << std::endl;
    std::ifstream inF;

    inF.open(infile1);
    Matrix<double> A(readmatrix1<double>(inF));
    inF.close();
    
    inF.open(infile2);
    Matrix<double> B(readmatrix1<double>(inF));
    inF.close();
    
    //auto A = readmatrix1<double>(inF);
    cout << "A dimensions = " <<  A.numrows() << " " << A.numcols() << endl;
    cout << "B dimensions = " <<  B.numrows() << " " << B.numcols() << endl;

    if (A.numcols() != B.numrows())
    {
        cerr << "Error: mismatched matrix dimensions for multiplication, bailed" << endl;
        abort();
    }

    Matrix<double> C(A.numrows(), B.numcols());

    matrix_multiply(A, B, C);

    if (outfile)
    {
        cout << "   matmul1 ## outfile=" << outfile << endl;
        std::ofstream outF(outfile);
        printmatrix1(C, outF);
    }
    else
    {
        printmatrix1(C, cout);
    }
}


int main(int argc, const char **argv)
{
    if (argc < 3)
    {
        std::cerr << "Needs two input matrix filenames" << std::endl;
        return 1;
    }
    matmul1(argv[1], argv[2], argc > 3 ? argv[3] : NULL);
    return 0;
}
