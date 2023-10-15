#include "SparseMatrixCSR.h"
#include <iomanip>

template<typename T>
SparseMatrixCSR<T>::SparseMatrixCSR(int rows,int cols):
				  SparseMatrix<T>(rows,cols)
{}

// Construct by giving the row_index, the column vector, the values
template<typename T>
SparseMatrixCSR<T>::SparseMatrixCSR
(
  const std::vector<int>& r_idx,  
  const std::vector<int>& c,
  const std::vector<T>& val,
  int rows_, int cols_
):SparseMatrix<T>(rows_,cols_)
{
  this.row_idx = r_idx; this.cols = c; this.values = val;
  
  unsigned int rIdxSize = row_idx.size();
  unsigned int cSize = cols.size();
  unsigned int nnzSize = values.size();
  
  if((rIdxSize!=(unsigned int) nRows+1) || (cSize != nnzSize) )
    throw std::invalid_argument( "###Wrong dimensions for the entries###" );
  
  nnz = nnzSize;
  
}

// Getter
template<typename T>
T SparseMatrixCSR<T>::Get(int row, int col) const
{
  if (row > nRows || col > nCols || row < 1 || col <1)
  {
    throw std::invalid_argument( "Insert a valid index for the rows or columns: " );
    return -1;
  }else if(nnz==0)
  {
    return T(0.0);
    	
  }else{
        // Check if there are non-zeros: row = i+1
  	int deltarow = row_idx[row]-row_idx[row-1];
  	if(deltarow>0)
  	{
  	// j: global position of the values array
  	
  	 for(int pos=row_idx[row-1];pos<row_idx[row-1]+deltarow;pos++)
  	 {
  	  
  	  if( cols[pos] == col-1)
  	    return values[pos];
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
  if(row>nRows || col >nCols || row < 1 || col < 1)
  {
   throw std::invalid_argument( "Insert a valid index for the rows or coloumns: " );
   
  }else{
   /* "Loop trough the values"
     pos: global-index to loop trough values, cols.
     
     Perform a loop trough the values: if we found the column,
     the entry is found, otherwise we must insert the value.
   
   */
   
   int deltarow = row_idx[row]-row_idx[row-1];
   int startPos = row_idx[row-1];
   int stopPos=startPos;int pos=0;
   
   for(pos=startPos;pos<startPos+deltarow;pos++)
    {
      if( (col-1)< cols[pos] )
      {
       stopPos = pos;
       break;
      }
      if ( (col-1) == cols[pos] )
         return values[pos];
    }
    if(pos == startPos + deltarow )
    	stopPos = pos;
    
    // Insert the value:
    cols.insert(cols.begin()+stopPos,col-1);
    values.insert(values.begin()+stopPos,0.0);
    
    //Increase the indexes for every row
    for(int rowI=row;rowI<nRows+1;rowI++)
      row_idx[rowI]++;
   
    nnz++; // Increase non-zeros
    
    return values[stopPos];
   
  }// end else
  
 
}

template<typename T>
std::vector<T> SparseMatrixCSR::operator * (const std::vector<T>& y) const
{
  // Perform x = Ay as a matrix-multiplication
  if( y.size() != (unsigned int) nCols)
  {
    throw std::invalid_argument( "###Vector is not compatible with the matrix dimensions###" );
  }
  
  std::vector<T> x(nRows,0.0);
  
  for(unsigned int i=0;i< row_idx.size()-1;i++)
  {
    int deltarow = row_idx[i+1]-row_idx[i];
     
    for(int pos=row_idx[i];pos<row_idx[i]+deltarow;pos++)
    {      
      x[i]+=(values[pos]*y[cols[pos]]);
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
      os << std::fixed << std::setprecision(1) << 0<<"  ";
     }
   }// end for cols
   os << "\n";
  }//end loop
  os<<"------------------"<<"\n";
  return os;
  
}




