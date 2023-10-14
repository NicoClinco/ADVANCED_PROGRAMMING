#ifndef SparseMatrixCSR_H
#define SparseMatrixCSR_H

#include <iostream>
#include <stdexcept>
#include "SparseMatrix.h"


class SparseMatrixCSR:
  public SparseMatrix
{
  public:
  
  // Zeros matrix
  SparseMatrixCSR(int rows,int cols); 
  
  // Construct from vectors of rows, coloumns, values 
  SparseMatrixCSR
  (
  const std::vector<int>& r_idx,  
  const std::vector<int>& c,
  const std::vector<float>& val,
  int rows_, int cols_
  );
    
  virtual float Get(int row, int col) const;
    
  virtual float operator () (int row, int col) const;
  
  virtual float& operator () (int row, int col);
  
  virtual std::vector<float> operator * (const std::vector<float> & y) const;
  
  friend std::ostream& operator<<(std::ostream& os, const SparseMatrixCSR& obj);
    
  protected:
  
   std::vector<int> row_idx;
  
};


#endif
