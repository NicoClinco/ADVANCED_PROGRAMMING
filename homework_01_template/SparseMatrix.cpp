#include "SparseMatrix.h"

template<typename T>
SparseMatrix<T>::SparseMatrix(int rows,int cols):nRows(rows),nCols(cols),nnz(0)		
{}

// Get the number of coloumns:
template<typename T>
int SparseMatrix<T>::GetCols() const
{
  return nCols;
}

// Get the number of rows:
template<typename T>
int SparseMatrix<T>::GetRows() const
{
  return nRows;
}

// Get the number of non-zeros:
template<typename T>
int SparseMatrix<T>::NumnonZeros() const
{
  return nnz;
}

// explicit instatation:

template class SparseMatrix<int>;

template class SparseMatrix<double>;
