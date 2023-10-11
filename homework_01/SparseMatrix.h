#ifndef SPARSEMATRIX_H_
#define SPARSEMATRIX_H_

class SparseMatrix
{
  
  public:
  
   // Constructor
   SparseMatrix(int rows,int cols);
   SparseMatrix(const SparseMatrix & mat)= default;              // copy constructor
   //SparseMatrix & operator = (const SparseMatrix& mat);

   ~SparseMatrix(void);
   
   // Getter-Setter
   int GetCols() const;
   int GetRows() const;
   int nonZeros() const;
   
   virtual float Get(int row, int col) const = 0;
   virtual void Set(int row,int col,float value)  = 0;
  
   // Set values
  
  
   // Operators
  
   // Multiplication
   virtual std::vector<float> operator * (const std::vector<float> & y) const = 0;
  
   // Access values
   virtual float operator () (int row, int col) const = 0;
   
   virtual float& operator () (int row, int col) = 0;
  
  protected:
   
   int nRows, nCols, nonZeros;  
   std::vector<float> values{3.1,4,5,7.4,2,6};   // values different from zero.
   std::vector<int> cols{2,4,2,4,1,3};       // cols where there are non zero-values.
  


#endif
  
  
  
   
   
}
