#ifndef _QUADRATURE1DHPP_
#define _QUADRATURE1DHPP_

#include <boost/math/quadrature/gauss.hpp>
namespace Integrate_1D{


template<int N>
class SimpsonQuadrature
{
public:

  virtual std::vector<double> makeWeights(double a,double b)
  {
    double h = (b-a)/(2*N);
    std::vector<double> weighs(2*N+1,0.0);
    weighs[0] = h/3;
    weighs[2*N] = h/3;
    int count = 1;
    std::generate(weighs.begin()+1,weighs.end()-1,
		  [&count,h]{double _w_ = (count%2) == 0 ?  (2.0*h/3.0) :  (4.0*h/3.0); count++; return _w_;});
  
    return weighs;
  }
  virtual std::vector<double> makeQuadPnts(double a,double b)
  {
    double h = (b-a)/(2*N);
    std::vector<double> xp(2*N+1,0.0); // number of points equispaced
    double xi = a;
    std::generate(xp.begin()+1,xp.end(),[&xi,h](){return xi=xi+h;});
    return xp;
  }
  double operator()(std::function<double (double)> funToInt,double a,double b)
  {
    // Use the composite trapezoidal rule:
 
    // Divide the interval [a,b] in subintervals and obtain the quadrature points:
    std::vector<double> w_ = this->makeWeights(a,b);
    std::vector<double> qp_= this->makeQuadPnts(a,b);
    
    // Evaluate function in the quadrature points:
    std::vector<double> fxi(2*N+1);
    std::transform(qp_.begin(),qp_.end(),fxi.begin(),funToInt);

    // Return the inner product:
    return std::inner_product(w_.begin(),w_.end(),fxi.begin(),0.0);
  }
};


template<int N>
class TrapzQuadrature
{
public:

  virtual std::vector<double> makeWeights(double a,double b)
  {
    double h = (b-a)/N;
    std::vector<double> weighs(N+1,h);
    weighs[0] = h/2;
    weighs[N] = h/2;
    return weighs; 
  }
  virtual std::vector<double> makeQuadPnts(double a,double b)
  {  
    double h = (b-a)/N;
    std::vector<double> xp(N+1,0.0); // number of points equispaced
    double xi = a;
    std::generate(xp.begin()+1,xp.end(),[&xi,h](){return xi=xi+h;});
    return xp;
  }
  double operator()(std::function<double (double)> funToInt,double a,double b)
  {
    // Divide the interval [a,b] in subintervals and obtain the quadrature points:
    std::vector<double> w_ = this->makeWeights(a,b);
    std::vector<double> qp_    = this->makeQuadPnts(a,b);
    
    // Evaluate function in the quadrature points:
    std::vector<double> fxi(N+1);
    std::transform(qp_.begin(),qp_.end(),fxi.begin(),funToInt);

    // Return the inner product:
    return std::inner_product(w_.begin(),w_.end(),fxi.begin(),0.0);
  }
}; //END TRAPZ

  /*
template<int N>
class MidPointQuadrature
{
public:

  virtual std::vector<double> makeWeights(double a,double b)
  {
    
  }
  virtual std::vector<double> makeQuadPnts(double a,double b)
  {
    
  }
  double operator()(std::function<double (double)> funToInt,double a,double b)
  {
    
  }
};
  */

template<int N>
class GaussLegendreQuadrature
{
  // In this class we use boost to obtain the quadrature weights.
  public:
   
  virtual std::vector<double> makeWeights(double a,double b)
  {
    auto weights = this->GaussIntegrator.weights();
    return weights;
  }
  virtual std::vector<double> makeQuadPnts(double a,double b)
  {
    auto points_ = this->GaussIntegrator.abscissa();
    return points_;
  }
  double operator()(std::function<double (double)> funToInt,double a,double b)
  {
    // In this case we don't use the weights and the quadrature points
    // since boost have the functionality:
    return GaussIntegrator.integrate(funToInt,a,b);
  }
private:
  boost::math::quadrature::gauss<double,N> GaussIntegrator;
};
  

template<template <int> class QuadType,int N>
class NumericalIntegration:
  public QuadType<N>
{
public:
 
  double operator() (std::function<double (double)> funToInt,double a, double b)
  {
    return QuadType<N>::operator()(funToInt,a,b);
  }
};


  
  
} //END NAMESPACE

#endif
