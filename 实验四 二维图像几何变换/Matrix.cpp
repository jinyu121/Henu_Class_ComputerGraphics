// Matrix.cpp: implementation of the Matrix class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "HaoYu.h"
#include "Matrix.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

inline Matrix operator*(const Matrix &lhs,const Matrix &rhs)
{

    //乘积矩阵
    Matrix ret(lhs.ROWS,rhs.COLS);

    //乘积操作
    for(int i=0;i<lhs.ROWS;i++)
    {
        for(int j=0;j<rhs.COLS;j++)
        {
            for(int k =0; k<lhs.COLS;k++)
            {
                ret.m_matrix[i][j] += lhs.m_matrix[i][k]*rhs.m_matrix[k][j]; 
            }
        }
    }

    //返回乘积(ret是堆栈对象，不能返回)
    return ret;
}

//矩阵构造函数，进行了动态内存分配
Matrix::Matrix(int rows, int cols, int& f):ROWS(rows),COLS(cols)
{
    m_matrix = new int*[ROWS];
    for(int i=0;i<ROWS;i++)
    {
        m_matrix[i] = new int[COLS];
        memset(m_matrix[i],0,sizeof(m_matrix[i]));
		for(int i=0;i<cols;i++){
			m_matrix[i][j]=f[i][j];
		}
    }
}

//矩阵析构函数，释放动态分配的内存
Matrix::~Matrix()
{
    for(int i=0;i<ROWS;i++)
    {   
        delete[] m_matrix[i];
    }
    delete[] m_matrix;
}
