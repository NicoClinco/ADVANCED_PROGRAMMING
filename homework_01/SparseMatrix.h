#ifndef SPARSEMATRIX_H_
#define SPARSEMATRIX_H_

#include <vector>

class SparseMatrix
{
  
  public:
  
   // Constructor
   SparseMatrix(int rows,int cols);
   
   

   
   // Getter-Setter
   int GetCols() const;
   int GetRows() const;
   int NumnonZeros() const;
   
   
   virtual float Get(int row, int col) const = 0;
   //virtual void Set(int row,int col,float value) = 0;
  
  
   // Access values
   virtual float operator () (int row, int col) const = 0;
   virtual float& operator () (int row, int col) = 0;
   
   // Multiplication
   virtual std::vector<float> operator * (const std::vector<float> & y) const = 0;
   
   // Condition number
   
   
  protected:
   
   int nRows, nCols, nnz;  
   std::vector<float> values;   // values different from zero.
   std::vector<int> cols;           // cols where there are non zero-values.
   
  
};
#endif
