#ifndef SparseMatrixCSR_H
#define SparseMatrixCSR_H

#include <iostream>
#include <stdexcept>
#include "SparseMatrix.h"

template<typename T>
class SparseMatrixCSR:
  public SparseMatrix<T>
{
  public:
  
  // Zeros matrix
  SparseMatrixCSR(int rows,int cols); 
  
  // Construct from vectors of rows, coloumns, values 
  SparseMatrixCSR
  (
  const std::vector<int>& r_idx,  
  const std::vector<int>& c,
  const std::vector<T>& val,
  int rows_, int cols_
  );
    
  virtual T Get(int row, int col) const;
    
  virtual T operator () (int row, int col) const;
  
  virtual T& operator () (int row, int col);
  
  virtual std::vector<float> operator * (const std::vector<T> & y) const;
  
  friend std::ostream& operator<<(std::ostream& os, const SparseMatrixCSR<T>& obj);
    
  protected:
  
   std::vector<int> row_idx;
  
};


#endif
