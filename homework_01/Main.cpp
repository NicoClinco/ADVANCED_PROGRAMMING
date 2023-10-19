/*
  This file allows us to validate the classes:

    - It is instantiated CSR_A that is the matrix in CSR-FORMAT and
      COO_A that is the matrix in COO-FORMAT.

    - There are modified the entries to test the correctness and also both
      the matrix are multiplied by a vector=ones(ncols).

    - The file "PostProc.h" provide some useful functions for the test, e.g:
      conversion from the COO-format to the CSR-format
*/


#include <iostream>
#include <vector>
#include "SparseMatrixCOO.h"
#include "SparseMatrixCSR.h"
#include "PostProc.h"


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
 
 /* CSR FORMAT ####################################################### */
 
 std::cout << "########### CSR FORMAT ###################"<<std::endl;
 std::cout << CSR_A(1,3) << " " << CSR_A(1,5) << " " << CSR_A(2,3) << " ";
 std::cout << CSR_A(2,5) << " " << CSR_A(4,2) << " " << CSR_A(4,4) << "\n\n\n";

 
 CSR_A(1,1) = 2.3;
 CSR_A(3,5) = 31.0;
 CSR_A(3,4) = 23.35; 
 CSR_A(4,5) = 5.000;

 std::cout << CSR_A;
 
 printVector<float>((CSR_A*y));
 
 std::cout << "########### CSR FORMAT ###################"<<std::endl; 
 /*######################################################################*/
 
 std::cout << "\n\n"<<std::endl;

 /* COO FORMAT ####################################################### */
 
 std::cout << "########### COO FORMAT ###################"<<std::endl;
 
 std::cout << COO_A(1,3) << " " << COO_A(1,5) << " " << COO_A(2,3) << " ";
 std::cout << COO_A(2,5) << " " << COO_A(4,2) << " " << COO_A(4,4) << "\n\n\n";

 COO_A(1,1) = 2.3;
 COO_A(3,5) = 31.0;
 COO_A(3,4) = 23.35; 
 COO_A(4,1) = 5.000;

 std::cout << COO_A;
 printVector<float>((COO_A*y));

 std::cout << "########### COO FORMAT ###################"<<"\n\n\n"<< std::endl;

 std::cout << " TEST THE CONVERSION PROPERTIES" <<std::endl;


 /* TEST THE CONVERSION FROM COO TO CSR */ 
 
 SparseMatrixCSR& SM_CSR = COOtoCSR(COO_A);
 
 //SparseMatrixCSR& CSR_A_CONV = dynamic_cast<SparseMatrixCSR&>(SM_CSR);

 std::cout << "######### CONVERTED-CSR-MATRIX-#########" <<std::endl;
 
 std::cout << SM_CSR;

 std::cout << "######### CONVERTED-CSR-MATRIX-#########" <<"\n"<< std::endl;

 /*------------------------------------*/

 /*  TEST THE CONVERSION FROM CSR TO COO */

 SparseMatrixCOO& SM_COO = CSRtoCOO(SM_CSR);

 std::cout << "###### CONVERTED-COO-MATRIX-#########"<<std::endl;
 
 std::cout<< SM_COO;

 std::cout << "###### CONVERTED-COO-MATRIX-########"<<"\n"<< std::endl;

 /* -----------------------------------*/

 
 return 0;
}
