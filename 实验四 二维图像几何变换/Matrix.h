// Matrix.h: interface for the Matrix class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MATRIX_H__F0D4975B_9501_47B4_BCA0_14133BADC724__INCLUDED_)
#define AFX_MATRIX_H__F0D4975B_9501_47B4_BCA0_14133BADC724__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class Matrix
{
private: 
    const int ROWS,COLS;
    int **m_matrix;
public:
    Matrix& operator*=(Matrix &mat);
    Matrix(int rows,int cols);
    ~Matrix();

    friend inline Matrix operator*(const Matrix &lhs,const Matrix &rhs);
};

#endif // !defined(AFX_MATRIX_H__F0D4975B_9501_47B4_BCA0_14133BADC724__INCLUDED_)
