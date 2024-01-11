#include "Quadrature.hpp"
#include "gtest/gtest.h"
#include <gmock/gmock.h>
#include <cmath>

/*
  Test the quadrature weights for
  the fixed quadrature formulas:
*/

using VectorDouble = std::vector<double>;

TEST(ElementsTest,HasSameElements)
{
  std::cout << "###Testing the weights for the quadrature formulas###\n";
  double xMin = 0.0;
  double xMax = 1.0;
  int    N = 50;
  double h = (xMax-xMin)/N;


  using namespace Integrate_1D;
  MidPointQuadrature IntegrationMID;
  SimpsonQuadrature IntegrationSIMPS;
  TrapzQuadrature IntegrationTRAPZ;

  using testing::ElementsAreArray;
  
  // MID-POINT:
  VectorDouble wMID(N,h);
  VectorDouble wMID_ = IntegrationMID.makeQuadWeights(xMin,xMax,N);
  EXPECT_THAT(wMID_,ElementsAreArray(wMID));

  // TRAPEZOIDAL:
  VectorDouble wTRPZ(N+1,h);
  VectorDouble wTRPZ_ = IntegrationTRAPZ.makeQuadWeights(xMin,xMax,N);
  wTRPZ[0] = h/2;
  wTRPZ[N] = h/2;
  EXPECT_THAT(wTRPZ_,ElementsAreArray(wTRPZ));
   
     
  // SIMPSON:
  h = (xMax-xMin)/(2*N);
  VectorDouble wSIMPS(2*N+1,0.0);
  VectorDouble wSIMPS_ = IntegrationSIMPS.makeQuadWeights(xMin,xMax,N);
  
  wSIMPS[0] = h/3;
  wSIMPS[2*N] = h/3;
  for(size_t i = 1;i<wSIMPS.size()-1;i++)
    {
     ((i%2) == 0 ?  (wSIMPS[i] = 2.0*h/3.0) :  (wSIMPS[i] = 4.0*h/3.0));
    }
  EXPECT_THAT(wSIMPS,ElementsAreArray(wSIMPS_));
  std::cout << "##############################\n";
}





/*
  First degree polynomial integration:
  
  The quadrature formula has to be exact
  (up to machine precision)
 */
TEST(ResultTest,HasExactSolution)
{
  std::cout << "###Testing the goodness of a first order quadrature formula####\n";
  using namespace Integrate_1D;
  NUMERICAL_INTEGRATION<MidPointQuadrature> nIntegrationMID;
  NUMERICAL_INTEGRATION<GaussLegeandreQuadrature> nIntegrationGL;
  NUMERICAL_INTEGRATION<SimpsonQuadrature> nIntegrationSIMPS;
  NUMERICAL_INTEGRATION<TrapzQuadrature> nIntegrationTRAPZ;

  // Test for N=20:
  auto ToIntegrate0 = [](double x)
   {
     return x;
   };
  
   double xSTART = 0.0;
   double xEND   = 1.0;
   double EXACT_RES0 = 0.5;
   unsigned int N0 = 20;
   
   // Testing the code for N = 20: The results need to be exact:
   
   double MID_RES0 = nIntegrationMID(ToIntegrate0,xSTART,xEND,N0);
   double TRPZ_RES0 = nIntegrationTRAPZ(ToIntegrate0,xSTART,xEND,N0);
   double SIMPS_RES0 = nIntegrationSIMPS(ToIntegrate0,xSTART,xEND,N0);
   double GL_RES0 = nIntegrationGL(ToIntegrate0,xSTART,xEND,N0);

   double abs_error =1e-14;
   
   EXPECT_NEAR(MID_RES0,EXACT_RES0,abs_error);
   EXPECT_NEAR(TRPZ_RES0,EXACT_RES0,abs_error);
   EXPECT_NEAR(SIMPS_RES0,EXACT_RES0,abs_error);
   EXPECT_NEAR(GL_RES0,EXACT_RES0,abs_error);

    std::cout << "##############################\n";
}


/*
 Testing the Gauss-Legeandre quadrature formula:
 The formula must be exact to order 2*n-1
*/
TEST(ResultTest,GaussLegeandre)
{
  std::cout << "###Testing the goodness of a first order quadrature formula####\n";
  using namespace Integrate_1D;
  NUMERICAL_INTEGRATION<GaussLegeandreQuadrature> nIntegrationGL;

  double xSTART = 0.0;
  double xEND   = 1.0;
  double EXACT_RES0 = 0.20; //Exact result (1/5)
  unsigned int N0 = 3;
  
  auto ToIntegrate0 = [](double x)
  {
    return std::pow(x,4);
  };
  
  
  double GL_RES0 = nIntegrationGL(ToIntegrate0,xSTART,xEND,N0);

  double abs_error =1e-14;
  EXPECT_NEAR(GL_RES0,EXACT_RES0,abs_error);
  

  std::cout << "##############################\n";
  
}
