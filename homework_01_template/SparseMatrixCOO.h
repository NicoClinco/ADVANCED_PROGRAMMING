#ifndef SparseMatrixCOO_H
#define SparseMatrixCOO_H

#include <iostream>
#include <stdexcept>
#include "SparseMatrix.h"

template<typename T>
class SparseMatrixCOO:
  public SparseMatrix<T>
{
  public:
  
  // Zeros matrix
  SparseMatrixCOO(int rows,int cols); 
  
  // Construct from vectors of rows, coloumns, values 
  SparseMatrixCOO
  (
  const std::vector<int>& r,  
  const std::vector<int>& c,
  const std::vector<T>& val,
  int rows_, int cols_
  );
    
  virtual T Get(int row, int col) const;
  
  //virtual void Set(int row, int col,float value);
  
  virtual T operator () (int row, int col) const;
  
  virtual T& operator () (int row, int col);
  
  virtual std::vector<T> operator * (const std::vector<T> & y) const;
  
  friend std::ostream& operator<<(std::ostream& os, const SparseMatrixCOO<T>& obj);
    
  protected:
  
   std::vector<int> rows;
  
};


#endif
