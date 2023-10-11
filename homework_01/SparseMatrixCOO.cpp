#include "SparseMatrixCOO.h"

SparseMatrixCOO::SparseMatrixCOO(int rows,int cols):
				  SparseMatrix(rows,cols)
{};

virtual float SparseMatrixCOO::Get(int row, int col) const
{
  if (row > nRows || col > nCols || row < 1 || col <1)
  {
    std::cout << "Insert a valid index for the rows or coloumns: " << std::endl;
    return;
  }
  else
  {
    if(nonZeros==0)
    {
	return 0.0;
    }
    else{
     for(int i=0;i<nonZeros;i++)
     {
       if(rows[i] == (row-1) && cols[i] == (col-1))
		return values[i];
     }
    }
  }
}

virtual void SparseMatrixCOO::Set(int row,int col,float value)
{
    if(row>=nRows || col >=nCols)
    {
      
    }else
    {
    if(value!=0.0)
    {
    
    
     for(int i=0;i<this->rows.size();i++)
     {
      if(this->rows[i] == row && this->cols[i]==col)
      	 
      	 this->values[i] = value;
     }
    
      
     }// end check value
    }
}



