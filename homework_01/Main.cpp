#include <iostream>
#include <vector>
#include "SparseMatrixCOO.h"


int main()
{
 std::vector<int> _rows_{0,0,1,1,3,3};
 std::vector<int> _cols_{2,4,2,4,1,3};
 std::vector<float> _vals_{3.1,4,5,7.4,2,6};
 
 int nrows = 4;
 int ncols = 5;


 /*
 SparseMatrixCOO A(_rows_,_cols_,_vals_,nrows,ncols);
 
 std::cout << "nRows, nCols, nNonZeros: "<< A.GetCols() << " "<< A.GetRows() << " "<<  A.NumnonZeros() << std::endl;
 
 std::cout << A.Get(2,3) << std::endl;
 
 A(2,3) = 4.5; 
 
 std::cout << A(2,3) << std::endl;
 */
 
 //SparseMatrix* A = new SparseMatrixCOO(_rows_,_cols_,_vals_,nrows,ncols);
 
 //SparseMatrix& Aref = *(A); // Tested by reference
 
 SparseMatrixCOO A(_rows_,_cols_,_vals_,nrows,ncols);
 
 float _n_ = A(2,2);
 
 std::cout << _n_ << std::endl;
 
 // ############################## //
 // Check on matrix multiplication //
 
 std::vector<float> y(ncols,1.0);
 
 std::vector<float> x = A*y;
 
 /*
 for (auto elem : x)
  std::cout << elem << std::endl;
 */
 // ############################## //
 






 /*
 int nRows = 4;int nCols = 5;
 int row = 3;
 int col = 4;
 float val = 0.5;
 int gIndx = (row-1)*nCols + (col-1); // global index
 for(unsigned int i=0;i<_rows_.size();i++)
 {
   int currgIndx = (_rows_[i])*nCols + (_cols_[i]);
   if( currgIndx == gIndx )
   {
      _vals_[i] = val;
      break;
   }
   else if( currgIndx > gIndx)
   {
      _vals_.insert(_vals_.begin()+i,val);
      _rows_.insert(_rows_.begin()+i,row-1);
      _cols_.insert(_cols_.begin()+i,col-1);
      break;
   }
  
}
*/
 
 


 
 return 0;
}
