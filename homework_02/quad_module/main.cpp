#include <stdio.h>
#include <iostream>
 #include <boost/math/quadrature/gauss.hpp> 
#include <functional>
#include <numeric>
#include <cmath>
#include <stdio.h>
#include <Quadrature.hpp>

// Function to integrate:
double ToIntegrate(double x)
{
  return x*x*x;
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
  numericalIntegration<MidPointQuadrature> nIntegrationMID;
  numericalIntegration<GaussLegeandreQuadrature> nIntegrationGL;
  numericalIntegration<SimpsonQuadrature> nIntegrationSIMPS;
  numericalIntegration<TrapzQuadrature> nIntegrationTRAPZ;
  
  
  double xSTART = 1.0;
  double xEND   = 6.0;
  unsigned int N = 5;
  double MID_RES = nIntegrationMID(ToIntegrate,xSTART,xEND,N);
  double TRPZ_RES = nIntegrationTRAPZ(ToIntegrate,xSTART,xEND,N);
  double SIMPS_RES = nIntegrationSIMPS(ToIntegrate,xSTART,xEND,N);
  double GL_RES = nIntegrationGL(ToIntegrate,xSTART,xEND,N);

  std::cout <<"********************************************\n";
  std::cout<< "  TESTING OF THE QUADRATURE-POINTS CLASS  \n";
  std::cout<< "********************************************\n";
  
  std::cout << "********** TEST WITH N=5 **************\n";
  std::cout << "EXACT-RESULT of the integration: 323.75 \n";
  std::cout << "Mid-point-result : "   <<   MID_RES << "\n";
  std::cout << "Trapezoidal-result : " << TRPZ_RES << "\n";
  std::cout << "Simpson-result : " <<     SIMPS_RES << "\n";
  std::cout << "Gauss-Legeandre-result : "<< GL_RES << "\n";

  std::cout << "***************************************\n";
  N=10;
  MID_RES = nIntegrationMID(ToIntegrate,xSTART,xEND,N);
  TRPZ_RES = nIntegrationTRAPZ(ToIntegrate,xSTART,xEND,N);
  SIMPS_RES = nIntegrationSIMPS(ToIntegrate,xSTART,xEND,N);
  GL_RES = nIntegrationGL(ToIntegrate,xSTART,xEND,N);
  
  
  std::cout << "********** TEST WITH N=10 **************\n";
    std::cout << "EXACT-RESULT of the integration: 323.75 \n";
  std::cout << "Mid-point-result : "   <<   MID_RES << "\n";
  std::cout << "Trapezoidal-result : " << TRPZ_RES << "\n";
  std::cout << "Simpson-result : " <<     SIMPS_RES << "\n";
  std::cout << "Gauss-Legeandre-result : "<< GL_RES << "\n";

  std::cout << "***************************************\n";
  N=20;
  MID_RES = nIntegrationMID(ToIntegrate,xSTART,xEND,N);
  TRPZ_RES = nIntegrationTRAPZ(ToIntegrate,xSTART,xEND,N);
  SIMPS_RES = nIntegrationSIMPS(ToIntegrate,xSTART,xEND,N);
  GL_RES = nIntegrationGL(ToIntegrate,xSTART,xEND,N);
  
  
  std::cout << "********** TEST WITH N=20 **************\n";
  std::cout << "EXACT-RESULT of the integration: 323.75 \n";
  std::cout << "Mid-point-result : "   <<   MID_RES << "\n";
  std::cout << "Trapezoidal-result : " << TRPZ_RES << "\n";
  std::cout << "Simpson-result : " <<     SIMPS_RES << "\n";
  std::cout << "Gauss-Legeandre-result : "<< GL_RES << "\n";

  
  return 0;
}
