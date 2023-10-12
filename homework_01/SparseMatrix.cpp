#include "SparseMatrix.h"

SparseMatrix::SparseMatrix(int rows,int cols):nRows(rows),nCols(cols),nnz(0)		
{}


int SparseMatrix::GetCols() const
{
  return nCols;
}

int SparseMatrix::GetRows() const
{
  return nRows;
}

int SparseMatrix::NumnonZeros() const
{
  return nnz;
}


