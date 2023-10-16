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


SparseMatrix& CSRtoCOO( const SparseMatrixCSR& _CSR_)
{
  int nRows = _CSR_.GetRows();
  int nCols = _CSR_.GetCols();
  
  std::vector<int> _rowsIdx_ = _CSR_.row_idx;
  std::vector<int> _cols_ = _CSR_.cols;
  std::vector<float> _vals_ = _CSR_.values;
  
  SparseMatrix* COO_A = new SparseMatrixCOO(nRows,nCols);

  return (*COO_A);
}


SparseMatrix& COOtoCSR(const SparseMatrixCOO& _COO_)
{
  int nRows = _COO_.GetRows();
  int nCols = _COO_.GetCols();

  std::vector<int> _rows_ = _COO_.rows;
  std::vector<int> _cols_ = _COO_.cols;
  std::vector<float> _vals_ = _COO_.values;

  // Creating the new vector for row-indexing
  std::vector<int> rowI(nRows+1,0);

  
  for(unsigned int i=0;i<_rows_.size();i++)
  {
    for(unsigned int j=_rows_[i]+1;j<rowI.size();j++)
      rowI[j]++;
  }
  
  SparseMatrix* CSR_A =
    new SparseMatrixCSR(rowI,_cols_,_vals_,nRows,nCols);
  
  

  return(*CSR_A);
}
