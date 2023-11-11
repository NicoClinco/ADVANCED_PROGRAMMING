#include <stdio.h>
#include <iostream>
#include <boost/math/quadrature/trapezoidal.hpp>
#include <functional>

/*
class Quadrature
{
public:
  Quadrature(int N):
   N_{N};

   virtual std::vector<double> makeQuadWeights(double a,double b) = 0;
   virtual std::vector<double> makeQuadPnts(double a ,double b) = 0;
 protected:
  int N_;
*/

class TrapzQuadrature:
  public Quadrature
{
  public:

  TrapzQuadrature(int N):
    Quadrature(N)
  { /* REMEMBER TO ASSERT N!*/};

  virtual std::vector<double> makeQuadWeights(double a, double b)
  {
    // TO DO
  }
  virtual std::vector<double> makeQuadPnts(double a,double b)
  {
    // TO DO
  }
  
  double operator()(std::function<double (double)> funToInt,double a,double b) const
  {
    // Use the composite trapezoidal rule:
 
    // Divide the interval [a,b] in subintervals and obtain the quadrature points:
    std::vector<double> weights_ = makeQuadWeights(a,b);
    std::vector<double> qpnts_    = makeQuadPnts(a,b);

    // Perform the sum with a std library function
    // return the stuff;
  }

private:
  int N;
};

class MidPointQuadrature:
  public Quadrature
{
public:
  MidPointQuadrature(int N):
    Quadrature(N);

    virtual std::vector<double> makeQuadWeights(double a, double b)
  {
    // TO DO
  }
  virtual std::vector<double> makeQuadPnts(double a,double b)
  {
    // TO DO
  }
  
  double operator()((std::function<double (double)> funToInt,double a,double b) const
  {
    // Divide the interval [a,b] in subintervals and obtain the quadrature points:
    std::vector<double> weights_ = makeQuadWeights(a,b);
    std::vector<double> qpnts_    = makeQuadPnts(a,b);

    // Perform the summation:
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
