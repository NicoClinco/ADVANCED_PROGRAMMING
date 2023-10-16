#include "SparseMatrix.h"

template<typename T>
SparseMatrix<T>::SparseMatrix(int rows,int cols):nRows(rows),nCols(cols),nnz(0)		
{}

template<typename T>
int SparseMatrix<T>::GetCols() const
{
  return nCols;
}

template<typename T>
int SparseMatrix<T>::GetRows() const
{
  return nRows;
}

template<typename T>
int SparseMatrix<T>::NumnonZeros() const
{
  return nnz;
}


template class SparseMatrix<int>;

template class SparseMatrix<float>;
