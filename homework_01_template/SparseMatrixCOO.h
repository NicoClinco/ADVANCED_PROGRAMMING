#ifndef SparseMatrixCOO_H
#define SparseMatrixCOO_H

#include <iostream>
#include <stdexcept>
#include "SparseMatrix.h"

// forward declaration for friend function conversion:
template <class>
class SparseMatrixCSR;

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

  template<class Y>
  friend std::ostream& operator<<(std::ostream& os, const SparseMatrixCOO<Y>& obj);

  template<class Y>
  friend SparseMatrixCSR<Y>& COOtoCSR( const SparseMatrixCOO<Y>& _COO_);
  
  protected:
  
   std::vector<int> rows;
  
};


#endif
