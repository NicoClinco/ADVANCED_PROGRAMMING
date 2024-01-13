#ifndef __INTERP_HPP__
#define __INTERP_HPP__

#include <cmath>
#include <Eigen/Dense>
#include <Eigen/Core>
/*
  Creating a template class
  int: Number of nodes found at
  compilation-time
 */

namespace Interp
{

class Interpolation
{
public:
  // Note: the values must be ordered when passed to the function:
  Interpolation(const std::vector<double>& xnodes,const std::vector<double>& ynodes);
  // Declare the call operator as virtual here:
protected:
  size_t nnodes_;
  std::vector<double> xnodes_;
  std::vector<double> ynodes_;
};

class LinearInterpolation:
  public Interpolation
{
public:

  LinearInterpolation(const std::vector<double>& xnodes,const std::vector<double>& ynodes);
  
  //Interpolate the value at a specific point:
  double interpolate(double value) const;

  double operator()(double value) 
  {
    return this->interpolate(value);
  }
  
};

  class PolynomialInterpolation:
    public Interpolation
{
public:

  PolynomialInterpolation(const std::vector<double>& xnodes,const std::vector<double>& ynodes);

  
  double interpolate(double value) const;
  
    double operator()(double value)
    {
      return this->interpolate(value);
    }
  private:
  
  Eigen::MatrixXd createVanderMondeMatrix() const;
 
  };
  
}//end namespace
  

#endif
