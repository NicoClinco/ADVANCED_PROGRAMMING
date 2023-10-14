#include "SparseMatrixCSR.h"

SparseMatrixCSR::SparseMatrixCSR(int rows,int cols):
				  SparseMatrix(rows,cols)
{}

// Construct by giving the row_index, the column vector, the values
SparseMatrixCSR::SparseMatrixCSR
(
  const std::vector<int>& r_idx,  
  const std::vector<int>& c,
  const std::vector<float>& val,
  int rows_, int cols_
):SparseMatrix(rows_,cols_)
{
  row_idx = r_idx; cols = c; values = val;
  
  unsigned int rIdxSize = row_idx.size();
  unsigned int cSize = cols.size();
  unsigned int nnzSize = values.size();
  
  if((rIdxSize!=(unsigned int) nRows+1) || (cSize != nnzSize) )
    throw std::invalid_argument( "###Wrong dimensions for the entries###" );
  
  nnz = nnzSize;
  
}

float SparseMatrixCSR::Get(int row, int col) const
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
	return float(0.0);
    }
    else{
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
  	 return float(0.0); // In the row is not present a value != 0
  	}
  	return float(0.0);
      }// end else
  }
}


float SparseMatrixCSR::operator () (int row, int col) const 
{
   const float x = this->Get(row,col);
   return x;
}

float& SparseMatrixCSR::operator () (int row, int col)
{
  if(row>nRows || col >nCols || row < 1 || col < 1)
  {
   throw std::invalid_argument( "Insert a valid index for the rows or coloumns: " );
   
  }else
  {
   int deltarow = row_idx[row]-row_idx[row-1];
   
   if(deltarow>0)
   {
    // pos : global position index for values
    for(int pos=row_idx[row-1];pos<row_idx[row-1]+deltarow;pos++)
    {
     if( cols[pos] == col-1 )
       return values[pos];
    }//end loop for the columns
    
    // If here, we have not found the coloumn,
    // we must put it
    int startPos = row_idx[row-1];
    int stopPos;
    for(int pos=startPos;pos<startPos+deltarow;pos++)
    {
      int currColumn = cols[pos];
      if( (col-1)<currColumn )
      {
       stopPos = pos;
       //std::cout<< stopPos << "\n\n" <<std::endl;
       break;
      }
    }
    // Insert the value:
    cols.insert(cols.begin()+stopPos,col-1);
    values.insert(values.begin()+stopPos,0.0);
    row_idx[row]++;
    nnz++;
    
    return values[stopPos];
    
   }else{
   
      cols.insert(cols.begin()+row_idx[row-1],col-1);
      values.insert(values.begin()+row_idx[row-1],0.0);
      nnz++;
      row_idx[row]++; 
      return values[row_idx[row-1]];
   }
   
  }// end else
  
 
}


std::vector<float> SparseMatrixCSR::operator * (const std::vector<float>& y) const
{
  // Perform x = Ay as a matrix-multiplication
  if( y.size() != (unsigned int) nCols)
  {
    throw std::invalid_argument( "###Vector is not compatible with the matrix dimensions###" );
  }
  
  std::vector<float> x(nRows,0.0);
  
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
std::ostream& operator<<(std::ostream& os, const SparseMatrixCSR& obj)
{
  int posCol=0; // zero position
  for(int row=0;row<nRows;row++)
  {
   posCol = 0;
   for(int col=0;col<nCols;col++)
   {
     if(col == cols[row_idx[row]+posCol])
     {
      std::cout << values[row_idx[row]+posCol] << "  ";
      posCol++;
     }else{
      std::cout << "0.0" << "  ";
     }
   }
   
  }
  
}




