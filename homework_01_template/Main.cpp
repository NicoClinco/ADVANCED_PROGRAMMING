#include <iostream>
#include <vector>
#include "SparseMatrixCOO.h"
#include "SparseMatrixCSR.h"
#include "PostProc.h"


int main()
{
 std::vector<int> _rows_{0,0,1,1,3,3};
 std::vector<int> _cols_{2,4,2,3,1,3};
 std::vector<double> _vals_{3.1,4,5,7.4,2,6};
 std::vector<int> _rowI_{0, 2, 4, 4, 6};
 int nrows = 4;
 int ncols = 5;

 // Construction of the CSR-Matrix:
 // Construction of the COO-Matrix:
 
 SparseMatrixCSR<double> CSR_A(_rowI_,_cols_,_vals_,nrows,ncols);
 SparseMatrixCOO<double> COO_A(_rows_,_cols_,_vals_,nrows,ncols);
 std::vector<double> y(ncols,1.0);

 /*-------------- CSR FORMAT -------------------*/
 // You can change the values by:
 // Matrix(row,col):
 
 CSR_A(1,1) = 2.3;
 CSR_A(3,5) = 31.0;
 CSR_A(4,5) = 5.000;
 std::cout << CSR_A;
 
 // Matrix multiplication by ones:
 
 printVector<double>((CSR_A*y));

 /* ---------------END CSR FORMAT ------------*/

 /* ----------------- COO FORMAT ---------------*/
 COO_A(1,1) = 2.3;
 COO_A(3,5) = 31.0;
 COO_A(4,5) = 5.000;
 std::cout << COO_A;
 
 // Matrix multiplication by ones:
 printVector<double>((COO_A*y));
 /* -----------------END COO FORMAT ---------*/



// Check with an empty matrix the things work:
 SparseMatrixCOO<double> A_COO_ZERO(4,5);
 SparseMatrixCSR<double> A_CSR_ZERO(4,5);
 
 A_COO_ZERO(2,4) = 1.2;
 A_CSR_ZERO(2,4) = 1.2;
 std::cout << A_COO_ZERO<< std::endl;
 std::cout << A_CSR_ZERO<< std::endl;


 // Conversion from COO-format to CSR-format:
 SparseMatrix<double>& Sparse = COOtoCSR<double>(A_COO_ZERO);
 // Conversion needed for printing:
 SparseMatrixCSR<double> ConvertedtoCSR = dynamic_cast<SparseMatrixCSR<double>& >(Sparse);

 // Print the converted matrix:
 std::cout << " CONVERTED MATRIX: FROM COO TO CSR" << std::endl;
 std::cout << ConvertedtoCSR << std::endl;
 
 // Conversion from CSR-format to COO-format:
 
 SparseMatrix<double>& SparseI = CSRtoCOO<double>(A_CSR_ZERO);
SparseMatrixCOO<double> ConvertedtoCOO= dynamic_cast<SparseMatrixCOO<double>& >(SparseI);

 
 //Print the converted matrix:
 std::cout << " CONVERTED MATRIX FROM CSR TO COO"<< std::endl;
 std::cout << ConvertedtoCOO << std::endl;
 
 return 0;
}
