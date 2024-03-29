#include "SparseMatrixCOO.h"
#include <iomanip>

SparseMatrixCOO::SparseMatrixCOO(int rows,int cols):
				  SparseMatrix(rows,cols)
{}

// Construct by giving the rows, the columns, and the values
SparseMatrixCOO::SparseMatrixCOO
(
  const std::vector<int>& r,  
  const std::vector<int>& c,
  const std::vector<float>& val,
  int rows_, int cols_
): SparseMatrix(rows_,cols_)
{
  rows = r; cols = c; values = val;
  
  unsigned int rSize = rows.size();
  unsigned int cSize = cols.size();
  unsigned int nnzSize = values.size();
  
  // Check if the dimensions are compatible:
  if((rSize != cSize) || (rSize != nnzSize) || (cSize != nnzSize))
    throw std::invalid_argument( "###Wrong dimensions for the entries###" );
  
  nnz = nnzSize;
  
  // Check if the rows are compatible with the indexes in the vectors: to-do
  //nRows = rows_;
  //nCols = cols_;
  
  
}

float SparseMatrixCOO::Get(int row, int col) const
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
     return float(0.0);
    }
  }
}

/*
virtual void SparseMatrixCOO::Set(int row,int col,float value)
{
    
    if(row>=nRows || col >=nCols || row < 1 || col < 1)
    {
     throw std::invalid_argument( "Insert a valid index for the rows or coloumns: " );
     return;
    }
    
    
    if(value!=0.0)
    {
      // global Index of (row,col)
      int gIndx = (row-1)*nCols + (col-1); // global index
            
      for(int i=0;i<rows.size();i++)
      {
        int currgIndx = (rows[i])*nCols + (cols[i]);
        if( currgIndx == gIndx )
        {
          values[i] = value;
          return;
        }
        else if( currgIndx > gIndx )
        {
          values.insert(values.begin()+i,value);
          rows.insert(rows.begin()+i,row-1);
          cols.insert(cols.begin()+i,col-1);
          nnz++;
        }
      }// end for  
    }// end if
       
}// end set operation

*/

float SparseMatrixCOO::operator () (int row, int col) const 
{
   float x = this->Get(row,col);

   return x;
}
/*
float& SparseMatrixCOO::operator () (int row, int col)
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
*/

float& SparseMatrixCOO::operator () (int row, int col)
{
  if(row>nRows || col >nCols || row < 1 || col < 1)
   throw std::invalid_argument( "Insert a valid index for the rows or coloumns: " );

  // Use the global-global indexing to enumerate the positions:
  // The index goes from 0 to Nelem-1 and increments for every column in a row.
  
  int gIndx = (row-1)*nCols + (col-1);
  unsigned int i = 0;
  for(i=0;i<rows.size();i++)
  {
    int currgIndx = (rows[i])*nCols + (cols[i]);
    if( currgIndx == gIndx )
      return this->values[i];
    
    else if( currgIndx > gIndx )
      break;
  }
  // If here, insert the value in the position:
  rows.insert(rows.begin()+i,row-1);
  cols.insert(cols.begin()+i,col-1);
  values.insert(values.begin()+i,0.0); // It will be overwritten
  nnz++;
  return this->values[i];
  
}




// Matrix multiplication by a vector:
std::vector<float> SparseMatrixCOO::operator * (const std::vector<float>& y) const
{
  // Perform x = Ay as a matrix-multiplication
  if( y.size() != (unsigned int) nCols)
  {
    throw std::invalid_argument( "Vector is not compatible with the matrix dimensions" );
  }
  
  std::vector<float> x(nRows,0.0);

  for(int i=0;i<nnz;i++)
  {
   x[rows[i]]+=(values[i]*y[cols[i]]);
  }
  return x;
}


//Operator overloading
std::ostream& operator<<(std::ostream& os, const SparseMatrixCOO& obj)
{
  
  os<< "----COO-MATRIX----" << "\n";
  unsigned int pos = 0;
  
  for(int row=0;row<obj.nRows;row++)
  {
    for(int col=0;col<obj.nCols;col++)
    {
     if(row == obj.rows[pos] && col == obj.cols[pos])
        {os << std::fixed << std::setprecision(1) << float(obj.values[pos])<< "  "; pos++;}
     else{
     os << std::fixed << std::setprecision(1) << float(0.0)<<"  ";
     }  
    }
    os<<"\n";
  }
  os<<"------------------"<<"\n";
  return os;
  
}

// Copy the vector of the stored row-indexes
std::vector<int> SparseMatrixCOO::Get_vecRows() const
{
  return (*this).rows;
}




