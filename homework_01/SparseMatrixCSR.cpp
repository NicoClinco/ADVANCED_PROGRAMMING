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
  	// Start looping from row
  	 for(int j=row_idx[row-1];j<row_idx[row-1]+deltarow;j++)
  	 {
  	  if( cols[j] == col-1)
  	    return values[j];
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
    for(int j=row_idx[row-1];j<row_idx[row-1]+deltarow;j++)
    {
     if( cols[j] == col-1 )
       return values[j];
    }//end loop for the columns
    // Insert the value for the columns and update the values
    cols.insert(cols.begin()+row_idx[row-1],col-1);
    values.insert(values.begin()+row_idx[row-1],0.0);
    row_idx[row]++;
    return values[row_idx[row-1]];
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
    for(int j=row_idx[i];j<row_idx[i]+deltarow;j++)
    {
      std::cout<< "i: "<< i << " " <<  values[j] <<  cols[j-1] << std::endl;
      //std::cout << j << std::endl;
      // j : position considered to go trough values: it tells the position of an index
      
      x[i]+=(values[j]*y[cols[j-1]]);
    }
    
  }// end for
  
  return x;
}




