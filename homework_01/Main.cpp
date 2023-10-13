#include <iostream>
#include <vector>
#include "SparseMatrixCOO.h"
#include "SparseMatrixCSR.h"

int main()
{
 std::vector<int> _rows_{0,0,1,1,3,3};
 std::vector<int> _cols_{2,4,2,4,1,3};
 std::vector<float> _vals_{3.1,4,5,7.4,2,6};
 std::vector<int> _rowI_{0, 2, 4, 4, 6};
 int nrows = 4;
 int ncols = 5;

 
 SparseMatrixCSR CSR_A(_rowI_,_cols_,_vals_,nrows,ncols);
 SparseMatrixCOO COO_A(_rows_,_cols_,_vals_,nrows,ncols);
 
 
 std::vector<float> y(ncols,1.0);
 
 std::vector<float> x_csr = CSR_A*y;
 
 std::vector<float> x_coo = COO_A*y;
 
 std::cout << " Multiplication for CSR-FORMAT " << std::endl;
 
 for(auto e_csr : x_csr )
   std::cout << e_csr << " ";
 
 std::cout << "\n\n"<<std::endl;
 std::cout << " Multiplication for COO-FORMAT " << std::endl;

 for(auto e_coo : x_coo )
   std::cout << e_coo << " ";
 
 
 
 /*
 SparseMatrixCOO A(_rows_,_cols_,_vals_,nrows,ncols);
 
 std::cout << "nRows, nCols, nNonZeros: "<< A.GetCols() << " "<< A.GetRows() << " "<<  A.NumnonZeros() << std::endl;
 
 std::cout << A.Get(2,3) << std::endl;
 
 A(2,3) = 4.5; 
 
 std::cout << A(2,3) << std::endl;
 
 SparseMatrix* A = new SparseMatrixCOO(_rows_,_cols_,_vals_,nrows,ncols);
 
 SparseMatrix& Aref = *(A); // Tested by reference
 
 SparseMatrixCOO A(_rows_,_cols_,_vals_,nrows,ncols);
 
 float _n_ = A(2,2);
 
 std::cout << _n_ << std::endl;
 
 // ############################## //
 // Check on matrix multiplication //
 
 std::vector<float> y(ncols,1.0);
 
 std::vector<float> x = A*y;
 
 
 for (auto elem : x)
  std::cout << elem << std::endl;
 
 // ############################## //
 

*/
 
 


 
 return 0;
}
