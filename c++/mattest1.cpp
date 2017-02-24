/************************************************************************\

    matmul.cpp
    Matrix multiplication demo

    A demo HPC program

\************************************************************************/

#include <iostream>
// #include <complex>
#include <Matrix.hpp>

void test1()
//  test1: Generates a simple matrix and prints it to stdout
{
    //using std::complex;
    
    std::cout << "## test1 ##" << std::endl;
    
    Matrix<double> A(3,5);
    //Matrix< std::complex<double> > A(3,5);
    for (int c = 0; c < A.numcols(); ++c)
        for (int r = 0; r < A.numrows(); ++r)
            A(r,c) = c * 10 + r;

    printmatrix1(A, std::cout);
}


int main(int argc, const char **argv)
{
    test1();
    return 0;
}
