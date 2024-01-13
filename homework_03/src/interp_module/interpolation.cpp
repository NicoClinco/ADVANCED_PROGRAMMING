#include "interpolation.hpp"
#include <iostream>

using namespace Interp;

/* Base class */

Interpolation::Interpolation(const std::vector<double>& xnodes,const std::vector<double>& ynodes):
  xnodes_(xnodes),
  ynodes_(ynodes)
{
  if(nnodes_<=0 || xnodes_.size() != ynodes_.size())
    throw std::invalid_argument("Error, you must instert a positive number of nodes\n");
  nnodes_ = xnodes_.size();
}

/* Derived classes */

LinearInterpolation::LinearInterpolation(const std::vector<double>& xnodes,const std::vector<double>& ynodes):
  Interpolation(xnodes,ynodes)
{}

double LinearInterpolation::interpolate(double value) const
{
  size_t n = xnodes_.size();
	
  // Check if x is within the range of the data
  if (value < xnodes_.front() || value > xnodes_.back()) {
    throw std::out_of_range("Interpolation point is outside the range of provided data.\n");
  }

  // Find the index  containing the value to be interpolated:
  size_t i = 0;
  while (i<n - 1 && ( value > xnodes_[i + 1])){
    i++;
  }

  // Perform linear interpolation within the interval [x_i, x_i+1]
  double x1 = xnodes_[i];
  double x2 = xnodes_[i + 1];
  double y1 = ynodes_[i];
  double y2 = ynodes_[i + 1];

  // Linear interpolation formula: y = y1 + (x - x1) * (y2 - y1) / (x2 - x1)
  return y1 + (value - x1) * (y2 - y1) / (x2 - x1);
  
}

PolynomialInterpolation::PolynomialInterpolation(const std::vector<double>& xnodes,const std::vector<double>& ynodes):
  Interpolation(xnodes,ynodes)
{}

double PolynomialInterpolation::interpolate(double value) const
{
  using namespace Eigen;
  // Construct the Vandermonde Matrix:
  MatrixXd Vmonde = this->createVanderMondeMatrix();

  // Creating an Eigen-Vector for the y-data  
  const VectorXd y = Map<const VectorXd>(ynodes_.data(),ynodes_.size());

  //Solving the associated system with Eigen:
  VectorXd coeffs= Vmonde.colPivHouseholderQr().solve(y); //coefficients.
  //Here, we return the interpolated value:

  //Step 1: Elevate the values to a power:
  VectorXd xPow(xnodes_.size());

  for(unsigned int i =0;i<xPow.size();++i)
    {
      xPow(i) = pow(value,i);
    }
  //Step 2: sum and interpolate:
  return coeffs.dot(xPow);  
}

Eigen::MatrixXd PolynomialInterpolation::createVanderMondeMatrix() const
{
  Eigen::MatrixXd m(nnodes_,nnodes_);

  //Fill the Vandermonde matrix:
  for(unsigned int r =0;r<m.rows();++r)
    {
      for(unsigned int c=0;c<m.cols();++c)
	{
	  m(r,c) = pow(xnodes_[r],c);
	}
    }
  //Return the vandermonde matrix:
  return m;  
}




