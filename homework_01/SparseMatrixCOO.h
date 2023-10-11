#ifndef SparseMatrixCOO_H
#define SparseMatrixCOO_H


class SparseMatrixCOO:
  public SparseMatrix
{
  public:
  
  SparseMatrixCOO(int rows,int cols);
    
  virtual float Get(int row, int col) const;
  
  virtual void Set(int row, int col,float value);
  
  virtual float operator () (int row, int col) const;
  
  virtual float& operator () (int row, int col);
  
  
  protected:
  
   std::vector<int> rows{0,0,1,1,3,3};
  
}


#endif
