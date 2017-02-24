#ifndef _WP_Matrix_hpp_
#define _WP_Matrix_hpp_

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



//  Friend functions and other functions related to Matrix class ---------
//  - matrix displaying subroutines
//  - matrix multiplications

//.section printmatrix1

// temporary functions to print matrix
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

#endif
