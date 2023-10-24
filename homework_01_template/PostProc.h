/*

 File that contains many functions for post-processing

*/

// Print a vector:
template<class type>
void printVector
(
 const std::vector<type>& vP
)
{
  for ( const type& elem : vP )
    std::cout << elem << " "; 
    
  std::cout  << "\n"<< std::endl;    
}

// CONVERSION: FROM COO TO CSR:
 template<class Y>
 SparseMatrixCSR<Y>& COOtoCSR( const SparseMatrixCOO<Y>& _COO_)
{
  unsigned int nRows = _COO_.GetRows();
  unsigned int nCols = _COO_.GetCols();

  std::vector<int> _rows_ = _COO_.rows;
  std::vector<int> _cols_ = _COO_.cols;
  std::vector<Y> _vals_ = _COO_.values;


  // Creating the new vector for row-indexing
  std::vector<int> rowI(nRows+1,0);


  // Convert the indexing COO->CSR:
  for(unsigned int i=0;i<_rows_.size();i++)
  {
    for(unsigned int j=_rows_[i]+1;j<rowI.size();j++)
      rowI[j]++;
  }

  // Creating a SparseMatrix:
  SparseMatrix<Y>* CSR_A =
    new SparseMatrixCSR<Y>(rowI,_cols_,_vals_,nRows,nCols);

  SparseMatrixCSR<Y>& CSR_A_CONV = dynamic_cast<SparseMatrixCSR<Y>&>(*CSR_A);

  return(CSR_A_CONV);
}

//CONVERSION FROM CSR TO COO:
template<class Y>
SparseMatrixCOO<Y>& CSRtoCOO( const SparseMatrixCSR<Y>& _CSR_)
{
  int nRows = _CSR_.GetRows();
  int nCols = _CSR_.GetCols();
  
  std::vector<int> _rowsIdx_ = _CSR_.row_idx;
  std::vector<int> _cols_ = _CSR_.cols;
  std::vector<Y> _vals_ = _CSR_.values;

  // Creating the rows:
  std::vector<int> rows;

 
  // Converting the indexing CSR->COO:
  for (unsigned int i=0;i<_rowsIdx_.size()-1;i++)
  {
    // num element per row:
    int num_elem = _rowsIdx_[i+1] - _rowsIdx_[i];
    for(int idx=0;idx<num_elem;idx++)
      rows.push_back(i); 
  }
  
  SparseMatrix<Y>* COO_A =
    new SparseMatrixCOO<Y>(rows,_cols_,_vals_,nRows,nCols);

  SparseMatrixCOO<Y>& COO_A_CONV = dynamic_cast<SparseMatrixCOO<Y>&>(*COO_A);
  
  return (COO_A_CONV);
}




