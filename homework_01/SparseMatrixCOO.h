#ifndef SparseMatrixCOO_H
#define SparseMatrixCOO_H

#include <iostream>
#include <stdexcept>
#include "SparseMatrix.h"


class SparseMatrixCOO:
  public SparseMatrix
{
  public:
  
  // Zeros matrix
  SparseMatrixCOO(int rows,int cols); 
  
  // Construct from vectors of rows, coloumns, values 
  SparseMatrixCOO
  (
  const std::vector<int>& r,  
  const std::vector<int>& c,
  const std::vector<float>& val,
  int rows_, int cols_
  );
    
  virtual float Get(int row, int col) const;
  
  //virtual void Set(int row, int col,float value);
  
  virtual float operator () (int row, int col) const;
  
  virtual float& operator () (int row, int col);
  
  virtual std::vector<float> operator * (const std::vector<float> & y) const;
  
  friend std::ostream& operator<<(std::ostream& os, const SparseMatrixCOO& obj);
    
  protected:
  
   std::vector<int> rows;
  
};


#endif
