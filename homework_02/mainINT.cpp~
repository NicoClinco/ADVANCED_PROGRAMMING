#include <stdio.h>
#include <iostream>
#include <boost/math/quadrature/trapezoidal.hpp>
#include <functional>

/*
class Quadrature
{
public:

 // To implement in subclasses:
 virtual double evaluate() = 0;

protected:
  std::vector<double> weights_;
};


class TrapzQuad:
  public Quadrature
{
  public:
  TrapzQuad(...):Quadrature(),weights_{} {};

  virtual double evaluate()
  {
    
  }
  double operator()(std::function<double (double)> funToInt,double a,double b) const
  {}
};




*/


class TrapzQuadrature
{
  public:
  
  double operator()(std::function<double (double)> funToInt,double a,double b) const
  {
    return boost::math::quadrature::trapezoidal(funToInt,a,b);
  }
  
};

class MidPointQuadrature
{
public:

  double operator()((std::function<double (double)> funToInt,double a,double b) const
  {
    double midPnt = 0.5*(a+b);
    return 0.5*funToInt(midPnt)*(b-a);
  }
  
};

template<class QuadType>
class numericalIntegration
{
public:
  numericalIntegration(QuadType* qrule):
    qrule_(qrule){};
  double operator () (std::function<double (double)> funToInt,double a, double b) const
  {
    return  qrule_->operator()(funToInt,a,b);
  }

private:
  // Remember to use a shared pointer:
  QuadType* qrule_;
};

int main()
{
  using boost::math::quadrature::trapezoidal; 
  auto f = [](double x) { return x; }; // To integrate
  //double I = trapezoidal(f, 0.0, boost::math::constants::two_pi<double>());
  TrapzQuadrature trpQuad{};
  numericalIntegration Int{&trpQuad};
  
  std::cout << Int(f,0.0,1.0) << std::endl;
  return 0;

}
