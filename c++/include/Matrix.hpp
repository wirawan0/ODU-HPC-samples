#ifndef _WP_Matrix_hpp_
#define _WP_Matrix_hpp_

#include <algorithm>
#include <cassert> // TEMPORARY
#include <iostream>

//  A simple C++ class to represent a column major matrix for
//  compatibility with Fortran

template <typename _number>
class Matrix                                        // dense matrix object
{
public:
    typedef _number value_type;
protected:
    value_type *_M;
    int _rows, _cols;
public:
    inline Matrix(int _rows, int _cols)
    {
        this->_rows = _rows;
        this->_cols = _cols;
        if (_rows && _cols)
            _M = new value_type[_rows * _cols];
        else
            _M = NULL;
    }
    inline Matrix(const Matrix<_number> &src)
    {
        this->_rows = src._rows;
        this->_cols = src._cols;
        if (_rows && _cols)
        {
            _M = new value_type[_rows * _cols];
            std::copy(src._M, src._M + (_rows*_cols), _M);
        }
        else
            _M = NULL;
    }

    inline ~Matrix()
    {
        if (_M)
            delete [] _M;
    }
        
//  indices range from 0..max-1
    inline value_type& operator() (int _row, int _col)
    {
        return _M[_row + _col * _rows];     // column major
    }
    inline const value_type& operator() (int _row, int _col) const
    {
        return _M[_row + _col * _rows];     // column major
    }

    inline int numrows() const { return _rows; }
    inline int numcols() const { return _cols; }
};


// The following are BIG subroutines. Do not inline them at all!
template <typename _number>
void printmatrix1(const Matrix<_number> &M, std::ostream &F);

template <typename _number>
Matrix<_number> readmatrix1(std::istream &F);



// temporary functions to print a matrix
template <typename _number>
void printmatrix1(const Matrix<_number> &M, std::ostream &F)
{
    using std::endl;
    if (M.numrows() == 0 || M.numcols() == 0)
    {
        F << "NULL_matrix " << M.numrows() << " " << M.numcols() << endl;
    }
    else
    {
        for (int i = 0; i < M.numrows(); ++i)
        {
            for (int j = 0; j < M.numcols(); ++j)
            {
                F << " " << M(i,j);
            }
            F << endl;
        }
    }
}


// temporary functions to read a matrix
// WARNING: This is
template <typename _number>
Matrix<_number> readmatrix1(std::istream &F)
{
    std::string code1;
    int rows, cols;
    F >> code1 >> rows >> cols;

    assert(code1 == "MATRIX");
    assert(rows >= 0);
    assert(cols >= 0);

    Matrix<_number> M(rows, cols);

    if (M.numrows() > 0 && M.numcols() > 0)
    {
        for (int i = 0; i < M.numrows(); ++i)
        {
            for (int j = 0; j < M.numcols(); ++j)
            {
                F >> M(i,j);
                //std::cout << i << " " << j << " : " << M(i,j) << std::endl;
            }
        }
    }
    return M;
}

#endif
