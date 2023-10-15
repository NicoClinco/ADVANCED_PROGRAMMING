#include "SparseMatrixCOO.h"
#include <iomanip>

template<typename T>
SparseMatrixCOO<T>::SparseMatrixCOO(int rows,int cols):
				  SparseMatrix<T>(rows,cols)
{}

// Construct by giving the rows, the columns, and the values
template<typename T>
SparseMatrixCOO<T>::SparseMatrixCOO
(
  const std::vector<int>& r,  
  const std::vector<int>& c,
  const std::vector<T>& val,
  int rows_, int cols_
):SparseMatrix<T>(rows_,cols_)
{
  this.rows = r; this.cols = c; this.values = val;
  
  unsigned int rSize = rows.size();
  unsigned int cSize = cols.size();
  unsigned int nnzSize = values.size();
  
  // Check if the dimensions are compatible:
  if((rSize != cSize) || (rSize != nnzSize) || (cSize != nnzSize))
    throw std::invalid_argument( "###Wrong dimensions for the entries###" );
  
  nnz = nnzSize;
   
}

template<typename T>
T SparseMatrixCOO<T>::Get(int row, int col) const
{
  if (row > nRows || col > nCols || row < 1 || col <1)
  {
    throw std::invalid_argument( "Insert a valid index for the rows or columns: " );
    return -1;
  }
  else
  {
    if(nnz==0)
    {
	return 0.0;
    }
    else{
    
     for(int i=0;i<nnz;i++)
     {
       if(rows[i] == (row-1) && cols[i] == (col-1))
	 return values[i];
     }
     return 0.0;
    }
  }
}


template<typename T>
T SparseMatrixCOO<T>::operator () (int row, int col) const 
{
   T x = this->Get(row,col);

   return x;
}

T& SparseMatrixCOO<T>::operator () (int row, int col)
{
  if(row>nRows || col >nCols || row < 1 || col < 1)
   throw std::invalid_argument( "Insert a valid index for the rows or coloumns: " );
  
  int gIndx = (row-1)*nCols + (col-1);
  
  for(unsigned int i=0;i<rows.size();i++)
  {
    int currgIndx = (rows[i])*nCols + (cols[i]);
    if( currgIndx == gIndx )
    {
      return this->values[i];
    }
    else if( currgIndx > gIndx )
    {
     rows.insert(rows.begin()+i,row-1);
     cols.insert(cols.begin()+i,col-1);
     values.insert(values.begin()+i,0.0); // It will be overwritten
     nnz++;
     return this->values[i];
    }
  }
}

// Matrix multiplication by a vector:
template<typename T>
std::vector<T> SparseMatrixCOO<T>::operator * (const std::vector<T>& y) const
{
  // Perform x = Ay as a matrix-multiplication
  if( y.size() != (unsigned int) nCols)
  {
    throw std::invalid_argument( "Vector is not compatible with the matrix dimensions" );
  }
  
  std::vector<T> x(nRows,0.0);

  for(int i=0;i<nnz;i++)
  {
   x[rows[i]]+=(values[i]*y[cols[i]]);
  }
  return x;
}


//Operator overloading
template<typename T>
std::ostream& operator<<(std::ostream& os, const SparseMatrixCOO<T>& obj)
{
  
  os<< "----COO-MATRIX----" << "\n";
  unsigned int pos = 0;
  
  for(int row=0;row<obj.nRows;row++)
  {
    for(int col=0;col<obj.nCols;col++)
    {
     if(row == obj.rows[pos] && col == obj.cols[pos])
        {os << std::fixed << std::setprecision(1) << obj.values[pos]<< "  "; pos++;}
     else{
     os << std::fixed << std::setprecision(1) << 0 <<"  ";
     }  
    }
    os<<"\n";
  }
  os<<"------------------"<<"\n";
  return os;
  
}






