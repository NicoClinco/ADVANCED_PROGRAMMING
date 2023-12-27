#include "eigen_op.hpp"


Eigen::MatrixXd mult_op(const Eigen::MatrixXd& a,const Eigen::MatrixXd& b)
{
  try{
    if(a.cols()!=b.rows()){
      throw std::runtime_error("Inconsistent rows and columns");
    }else{
    Eigen::MatrixXd m(a.rows(),b.cols());
    m = a*b; // Matrix multiplication in Eigen.
    return m;
    }
  }catch(std::runtime_error)
    {
      Eigen::MatrixXd m(a.rows(),b.cols());
      return m;
    }
}

Eigen::MatrixXd inv_op(const Eigen::MatrixXd& a)
{
  return a.inverse();
}
