#include "SparseMatrixCOO.h"
#include <iomanip>

// Construct zeros matrix:
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
  this->rows = r; this->cols = c; this->values = val;
  
  unsigned int rSize = this->rows.size();
  unsigned int cSize = this->cols.size();
  unsigned int nnzSize = this->values.size();
  
  // Check if the dimensions are compatible:
  if((rSize != cSize) || (rSize != nnzSize) || (cSize != nnzSize))
    throw std::invalid_argument( "###Wrong dimensions for the entries###" );
  
  this->nnz = nnzSize;
   
}

// Getter method:
template<typename T>
T SparseMatrixCOO<T>::Get(int row, int col) const
{
  if (row > this->nRows || col > this->nCols || row < 1 || col <1)
  {
    throw std::invalid_argument( "Insert a valid index for the rows or columns: " );
    return -1;
  }
  else
  {
    if(this->nnz==0)
    {
      return T(0.0);
    }
    else{
    
     for(int i=0;i<this->nnz;i++)
     {
       if(this->rows[i] == (row-1) && this->cols[i] == (col-1))
	 return this->values[i];
     }
     return T(0.0);
    }
  }
}


template<typename T>
T SparseMatrixCOO<T>::operator () (int row, int col) const 
{
   T x = this->Get(row,col);
   return x;
}
template<typename T>
T& SparseMatrixCOO<T>::operator () (int row, int col)
{
  if(row>this->nRows || col >this->nCols || row < 1 || col < 1)
   throw std::invalid_argument( "Insert a valid index for the rows or coloumns: " );

  //If the matrix is empty:
  if(this->nnz==0){
    this->rows.push_back(row-1);
    this->cols.push_back(col-1);
    this->values.push_back(0.0);
    (this->nnz)++;
    return (this->values[0]);
  }

  // global indexing for storing the entries:
  int gIndx = (row-1)*( this->nCols) + (col-1);
  
  unsigned int i = 0;
  for(i=0;i<this->rows.size();i++)
  {
    int currgIndx = (this->rows[i])*( this->nCols ) + (this->cols[i]);
    if( currgIndx == gIndx )
    {
      return (this->values[i]);
    }
    else if( currgIndx > gIndx )
    {
      break;
    }
  }
     this->rows.insert(this->rows.begin()+i,row-1);
     this->cols.insert(this->cols.begin()+i,col-1);
     this->values.insert(this->values.begin()+i,0.0); // It will be overwritten at the return.
     (this->nnz)++;
     return (this->values[i]);
}

// Matrix multiplication by a vector:
template<typename T>
std::vector<T> SparseMatrixCOO<T>::operator * (const std::vector<T>& y) const
{
  // Perform x = Ay as a matrix-multiplication
  if( y.size() != (unsigned int) (this->nCols))
  {
    throw std::invalid_argument( "Vector is not compatible with the matrix dimensions" );
  }
  
  std::vector<T> x(this->nRows,0.0);

  for(int i=0;i<this->nnz;i++)
  {
   x[this->rows[i]]+=(this->values[i]*y[this->cols[i]]);
  }
  return x;
}


//Operator overloading for printing the matrix:
template<typename T>
std::ostream& operator<<(std::ostream& os, const SparseMatrixCOO<T>& obj)
{
  
  os<< "----COO-MATRIX----" << "\n";

  //Print zeros matrix:
  if(obj.nnz==0){
    for(int row=0;row<obj.nRows;row++)
    {
      for(int col=0;col<obj.nCols;col++)
      {
	 os << std::fixed << std::setprecision(1) << T(0.0) <<"  ";
      }
       os<<"\n";
      }
    os<<"------------------"<<"\n";
    return os;
    }

  //print full-matrix:
  unsigned int pos = 0;
  for(int row=0;row<obj.nRows;row++)
  {
    for(int col=0;col<obj.nCols;col++)
    {
     if(row == obj.rows[pos] && col == obj.cols[pos])
        {os << std::fixed << std::setprecision(1) << obj.values[pos]<< "  "; pos++;}
     else{
       os << std::fixed << std::setprecision(1) << T(0.0) <<"  ";
     }  
    }
    os<<"\n";
  }
  os<<"------------------"<<"\n";
  return os;
}// end function

// explicit instatation:

template class SparseMatrixCOO<int>;
template class SparseMatrixCOO<double>;

template std::ostream& operator<<(std::ostream &os,const SparseMatrixCOO<double>& obj);
template std::ostream& operator<<(std::ostream &os,const SparseMatrixCOO<int>& obj);







