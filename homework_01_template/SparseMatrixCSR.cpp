#include "SparseMatrixCSR.h"
#include <iomanip>

// construct a zero matrix:
template<typename T>
SparseMatrixCSR<T>::SparseMatrixCSR(int rows,int cols):
				  SparseMatrix<T>(rows,cols)
{
  // resize the row_idx vector:
  this->row_idx.resize(rows+1,0);
}

// Construct by giving the row_index, the column vector and the values
template<typename T>
SparseMatrixCSR<T>::SparseMatrixCSR
(
  const std::vector<int>& r_idx,  
  const std::vector<int>& c,
  const std::vector<T>& val,
  int rows_, int cols_
):SparseMatrix<T>(rows_,cols_)
{
  this->row_idx = r_idx; this->cols = c; this->values = val;
  
  unsigned int rIdxSize = this->row_idx.size();
  unsigned int cSize = this->cols.size();
  unsigned int nnzSize = this->values.size();
  
  if((rIdxSize!=(unsigned int) this->nRows+1) || (cSize != nnzSize) )
    throw std::invalid_argument( "###Wrong dimensions for the entries###" );
  
  this->nnz = nnzSize;
  
}

// Getter
template<typename T>
T SparseMatrixCSR<T>::Get(int row, int col) const
{
  if (row > this->nRows || col > this->nCols || row < 1 || col <1)
  {
    throw std::invalid_argument( "Insert a valid index for the rows or columns: " );
    return -1;
  }else if(this->nnz==0)
  {
    return T(0.0);
    	
  }else{
        // Check if there are non-zeros: row = i+1
  	int deltarow = this->row_idx[row]-this->row_idx[row-1];
  	if(deltarow>0)
  	{
  	// j: global position of the values array
  	
  	 for(int pos=this->row_idx[row-1];pos<this->row_idx[row-1]+deltarow;pos++)
  	 {
  	  
  	  if( this->cols[pos] == col-1)
  	    return this->values[pos];
  	 }//end loop for the columns
  	 return T(0.0); // In the row is not present a value != 0
  	}
  	return T(0.0);
      }// end else
}


// Operator for for get the values:
template<typename T>
T SparseMatrixCSR<T>::operator () (int row, int col) const 
{
   T x = this->Get(row,col);
   return x;
}

// Operator for changing the entry in the matrix:
template<typename T>
T& SparseMatrixCSR<T>::operator () (int row, int col)
{
  if(row> this->nRows || col >this->nCols || row < 1 || col < 1)
  {
   throw std::invalid_argument( "Insert a valid index for the rows or coloumns: " );
   
  }else{
   /* "Loop trough the values"
     pos: global-index to loop trough values, cols.
     
     Perform a loop trough the values: if we found the column,
     the entry is found, otherwise we must insert the value.
   */

    // If it is the first time, update the cols and the values:
    if (this->nnz == 0){
      for(unsigned int i=row;i< row_idx.size();i++)
	(this->row_idx[i])++;
      this->cols.push_back(col-1);
      this->values.push_back(0);
      (this->nnz)++;
      return (this->values[0]);
    }
   
   int deltarow = this->row_idx[row]-this->row_idx[row-1];
   int startPos = this->row_idx[row-1];
   int stopPos=startPos;int pos=0;
   
   for(pos=startPos;pos<startPos+deltarow;pos++)
    {
      if( (col-1)< this->cols[pos] )
      {
       stopPos = pos;
       break;
      }
      if ( (col-1) == this->cols[pos] )
         return this->values[pos];
    }
    if(pos == startPos + deltarow )
    	stopPos = pos;
    
    // Insert the value:
    this->cols.insert(this->cols.begin()+stopPos,col-1);
    this->values.insert(this->values.begin()+stopPos,0.0);
    
    //Increase the indexes for every row
    for(int rowI=row;rowI<this->nRows+1;rowI++)
      this->row_idx[rowI]++;
   
    (this->nnz)++; // Increase non-zeros
    
    return this->values[stopPos];
   
  }// end else
  
 
}

template<typename T>
std::vector<T> SparseMatrixCSR<T>::operator * (const std::vector<T>& y) const
{
  // Perform x = Ay as a matrix-multiplication
  if( y.size() != (unsigned int) this->nCols)
  {
    throw std::invalid_argument( "###Vector is not compatible with the matrix dimensions###" );
  }
  std::vector<T> x(this->nRows,0.0);

  //if the matrix is void, skip the computation:
  if( (this->nnz) == 0)
    return x;
  
  for(unsigned int i=0;i< this->row_idx.size()-1;i++)
  {
    // how many entries are present in the row i: 
    int deltarow = this->row_idx[i+1]-this->row_idx[i];
     
    for(int pos=this->row_idx[i];pos<this->row_idx[i]+deltarow;pos++)
    {      
      x[i]+=(this->values[pos]*y[this->cols[pos]]);
    }
   
 }// end for
  return x;
}  

// Stream operator-overloading:
template<typename T>
std::ostream& operator<<(std::ostream& os, const SparseMatrixCSR<T>& obj)
{
  
  os<< "----CSR-MATRIX----" << "\n";
  
  int posCol=0; // zero position
  int nnzRow = 0; // number of non-zeros in the row considered
  
  /* "Perform a classic double for loop"
     For every row, obtain the number of entries nnzRow
     and perform a cycle trough the coloumn: if we found an
     entry, print that else print 0.0;
  */

  //if empty, print only zeros:
  if (obj.nnz == 0){
     for(int row=0;row<obj.nRows;row++)
     {
       for(int col=0;col<obj.nCols;col++)
	 {
	   os << std::fixed << std::setprecision(1) << T(0)<<"  ";
	 }
        os << "\n";
     }
     os<<"------------------"<<"\n";
     return os;
  }
  
  // print the matrix if not zero:
  for(int row=0;row<obj.nRows;row++)
  {
   posCol = 0;
   nnzRow = obj.row_idx[row+1]-obj.row_idx[row];
   int nRemanent = nnzRow;
   
   for(int col=0;col<obj.nCols;col++)
   {
     if(col == obj.cols[obj.row_idx[row]+posCol] && nRemanent>0)
     {
      //std::cout <<  "\n" << col << "\n";
      os << std::fixed << std::setprecision(1) << obj.values[obj.row_idx[row]+posCol] << "  ";
      posCol++;
      nRemanent--;
     }else{
       os << std::fixed << std::setprecision(1) << T(0)<<"  ";
     }
   }// end for cols
   os << "\n";
  }//end loop
  os<<"------------------"<<"\n";
  return os;
  
}


// Explicit instatation for classes:

template class SparseMatrixCSR<int>;
template class SparseMatrixCSR<double>;

// Explicit instantation of the friend function:
template std::ostream& operator<<(std::ostream &os,const SparseMatrixCSR<double>& obj);
template std::ostream& operator<<(std::ostream &os,const SparseMatrixCSR<int>& obj);

