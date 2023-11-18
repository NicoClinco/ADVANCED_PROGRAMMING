#include <stdio.h>
#include <iostream>
 #include <boost/math/quadrature/gauss.hpp> 
#include <functional>
#include <numeric>
#include <cmath>
#include <stdio.h>
#include <QuadratureV1.hpp>

// Function to integrate:
constexpr double ToIntegrate(double x)
{
  return -3*x*x;
}

template<int n>
double integrator_(double a,double b,std::function<double(double)> f)
{

  boost::math::quadrature::gauss<double,n> integrator;
  return integrator.integrate(f,a,b);
}


int main()
{
  // The class numerical Integration inherits from
  // the specific-quadrature rule used.

  // With this design-pattern we can simply call
  // the operator () of the interface class and specify
  // the number of points required WITHOUT instanciate
  // any object for the specific quadrature rule.
  using namespace Integrate_1D;
  //numericalIntegration<MidPointQuadrature> nIntegrationMID;

  double xSTART = 1.0;
  double xEND   = 3.0;
  //double MID_RES = nIntegrationMID(ToIntegrate,xSTART,xEND,4);
  
  const int N =4;
  NumericalIntegration<TrapzQuadrature,4> nIntegrationTR;
  double TRAPZ_RES = nIntegrationTR(ToIntegrate,xSTART,xEND);


  NumericalIntegration<SimpsonQuadrature,N> nIntegrationSIMPS;
  double SIMPS_RES = nIntegrationSIMPS(ToIntegrate,xSTART,xEND);

  NumericalIntegration<GaussLegendreQuadrature,N> nIntegrationGL;
  double GL_RES = nIntegrationGL(ToIntegrate,xSTART,xEND);
  // Gauss quadrature:
  const int nPoints = 4;
  boost::math::quadrature::gauss<double,nPoints> integrator;
  
  /*
  auto weights = integrator.weights();
  auto points_ = integrator.abscissa();
  int i = 0;
  for(auto it = weights.begin();it!=weights.end();++it)
    {
      std::cout << *it << " "<<points_[i] <<std::endl; i++; 
    }
  */
  //double SIMPS_RES = nIntegrationSIMPS(ToIntegrate,xSTART,xEND,4);
   
   std::cout << "Exact-result, func: -3x^2 from 1 to 3 :"<< -26.0<<std::endl;
   //std::cout << "Mid-point-result : "   <<   MID_RES << "\n";
   std::cout << "Trapezoidal-result : " << TRAPZ_RES << "\n";
   std::cout << "Simpson-result : " << SIMPS_RES << "\n";
   std::cout << "Gauss-result : "<< integrator.integrate(ToIntegrate,xSTART,xEND) << "\n";
   std::cout << "Gauss-result-myfun : "<<GL_RES << "\n";
  return 0;
}
