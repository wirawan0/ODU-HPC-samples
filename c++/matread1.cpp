/************************************************************************\

    matread1.cpp
    A demo program to read a matrix from a text file

    Created: 20170224

\************************************************************************/

#include <iostream>
#include <fstream>
#include <Matrix.hpp>

void read1(const char *infile)
//  read1: Reads a matrix from a file and prints it to stdout
{
    //using std::complex;

    std::cout << "## read1 ## infile=" <<  infile <<std::endl;
    std::ifstream inF(infile);

    Matrix<double> A(readmatrix1<double>(inF));
    //auto A = readmatrix1<double>(inF);
    std::cout << "dimensions = " <<  A.numrows() << " " << A.numcols() <<std::endl;

    printmatrix1(A, std::cout);
}


int main(int argc, const char **argv)
{
    if (argc < 2)
    {
        std::cerr << "Needs an input file name on arg1" << std::endl;
        return 1;
    }
    read1(argv[1]);
    return 0;
}
