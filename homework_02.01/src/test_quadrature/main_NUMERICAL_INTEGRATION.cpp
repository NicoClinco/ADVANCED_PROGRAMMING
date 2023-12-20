#include <stdio.h>
#include <iostream>
#include <functional>

#include "Quadrature.hpp"
//#include <matplot/matplot.h>




int main()
{



   /*--- MODULE FOR NUMERICAL INTEGRATION --TESTING------- */
   using namespace Integrate_1D;
   NUMERICAL_INTEGRATION<MidPointQuadrature> nIntegrationMID;
   NUMERICAL_INTEGRATION<GaussLegeandreQuadrature> nIntegrationGL;
   NUMERICAL_INTEGRATION<SimpsonQuadrature> nIntegrationSIMPS;
   NUMERICAL_INTEGRATION<TrapzQuadrature> nIntegrationTRAPZ;


   // Example : Integration of f(x) = x:

   // All the formulas has to be exact for this function:
   auto ToIntegrate0 = [](double x)
   {
     return x;
   };

   double xSTART = 0.0;
   double xEND   = 2.0;
   double EXACT_RES0 = 2.0;
   unsigned int N0;
   std::vector<double> degrees0;
   std::vector<std::vector<double>> errors0_(3,std::vector<double>(4));


   std::cout <<"********************************************\n";
   std::cout<< "  TESTING FOR f(x) =x                       \n";
   std::cout<< "********************************************\n";

   N0=2;
   double MID_RES0 = nIntegrationMID(ToIntegrate0,xSTART,xEND,N0);
   double TRPZ_RES0 = nIntegrationTRAPZ(ToIntegrate0,xSTART,xEND,N0);
   double SIMPS_RES0 = nIntegrationSIMPS(ToIntegrate0,xSTART,xEND,N0);
   double GL_RES0 = nIntegrationGL(ToIntegrate0,xSTART,xEND,N0);
   
   std::cout << "********** TEST WITH N="<<N0<<"**************\n";
   std::cout << "EXACT-RESULT of the integration: "<<EXACT_RES0 <<"\n";
   std::cout << "Mid-point-result : "   <<   MID_RES0 << "\n";
   std::cout << "Trapezoidal-result : " << TRPZ_RES0 << "\n";
   std::cout << "Simpson-result : " <<     SIMPS_RES0 << "\n";
   std::cout << "Gauss-Legendre-result : "<< GL_RES0 << "\n";

   errors0_[0][0] = abs(MID_RES0-EXACT_RES0);
   errors0_[0][1]= abs(TRPZ_RES0-EXACT_RES0);
   errors0_[0][2] = abs(SIMPS_RES0-EXACT_RES0);
   errors0_[0][3] = abs(GL_RES0-EXACT_RES0);

   std::cout << "***************************************\n";

   N0=4;
   MID_RES0 = nIntegrationMID(ToIntegrate0,xSTART,xEND,N0);
   TRPZ_RES0 = nIntegrationTRAPZ(ToIntegrate0,xSTART,xEND,N0);
   SIMPS_RES0 = nIntegrationSIMPS(ToIntegrate0,xSTART,xEND,N0);
   GL_RES0 = nIntegrationGL(ToIntegrate0,xSTART,xEND,N0);
   
   std::cout << "********** TEST WITH N="<<N0<<"**************\n";
   std::cout << "EXACT-RESULT of the integration: "<<EXACT_RES0 <<"\n";
   std::cout << "Mid-point-result : "   <<   MID_RES0 << "\n";
   std::cout << "Trapezoidal-result : " << TRPZ_RES0 << "\n";
   std::cout << "Simpson-result : " <<     SIMPS_RES0 << "\n";
   std::cout << "Gauss-Legendre-result : "<< GL_RES0 << "\n";

   // Fill the error vector:
   errors0_[1][0] = abs(MID_RES0-EXACT_RES0);
   errors0_[1][1] = abs(TRPZ_RES0-EXACT_RES0);
   errors0_[1][2] = abs(SIMPS_RES0-EXACT_RES0);
   errors0_[1][3] = abs(GL_RES0-EXACT_RES0);
   std::cout << "***************************************\n";

   N0=8;
   MID_RES0 = nIntegrationMID(ToIntegrate0,xSTART,xEND,N0);
   TRPZ_RES0 = nIntegrationTRAPZ(ToIntegrate0,xSTART,xEND,N0);
   SIMPS_RES0 = nIntegrationSIMPS(ToIntegrate0,xSTART,xEND,N0);
   GL_RES0 = nIntegrationGL(ToIntegrate0,xSTART,xEND,N0);
   
   std::cout << "********** TEST WITH N="<<N0<<"**************\n";
   std::cout << "EXACT-RESULT of the integration: "<<EXACT_RES0 <<"\n";
   std::cout << "Mid-point-result : "   <<   MID_RES0 << "\n";
   std::cout << "Trapezoidal-result : " << TRPZ_RES0 << "\n";
   std::cout << "Simpson-result : " <<     SIMPS_RES0 << "\n";
   std::cout << "Gauss-Legendre-result : "<< GL_RES0 << "\n";

   std::cout << "ERROR FOR N=8 : f(x)=x" <<std::endl;
   std::cout << "trapz: " << TRPZ_RES0-EXACT_RES0<<std::endl;
   std::cout << "midpoint: " << MID_RES0-EXACT_RES0<<std::endl;
   std::cout << "simpson: " << SIMPS_RES0-EXACT_RES0<<std::endl;
   std::cout << "GaussLegendre: " << GL_RES0-EXACT_RES0<<std::endl;
   std::cout << "******************************************\n";
   std::cout << "******************************************\n";
   std::cout << "*******END TEST FOR f(x) = x *********\n\n\n\n";
   
   // Example : Integration of f(x) = sin(x):
   auto ToIntegrate = [](double x)
   {
     return sin(x);
   };
  
   xSTART = 0.0;
   xEND   = M_PI;
   unsigned int N;
   std::vector<double> degrees;
   std::vector<std::vector<double>> errors_(4,std::vector<double>(4));
   std::vector<double> currErrors(4);
   
   double EXACT_RES = 2.0;
   std::cout <<"********************************************\n";
   std::cout<< "  TESTING FOR f(x) = sin(x)                 \n";
   std::cout<< "********************************************\n";

   N=2;
   degrees.push_back(double(N));
   double MID_RES = nIntegrationMID(ToIntegrate,xSTART,xEND,N);
   double TRPZ_RES = nIntegrationTRAPZ(ToIntegrate,xSTART,xEND,N);
   double SIMPS_RES = nIntegrationSIMPS(ToIntegrate,xSTART,xEND,N);
   double GL_RES = nIntegrationGL(ToIntegrate,xSTART,xEND,N);
   std::cout << "********** TEST WITH N="<<N<<"**************\n";
   std::cout << "EXACT-RESULT of the integration: "<<EXACT_RES <<"\n";
   std::cout << "Mid-point-result : "   <<   MID_RES << "\n";
   std::cout << "Trapezoidal-result : " << TRPZ_RES << "\n";
   std::cout << "Simpson-result : " <<     SIMPS_RES << "\n";
   std::cout << "Gauss-Legendre-result : "<< GL_RES << "\n";

   errors_[0][0] = abs(MID_RES-EXACT_RES);
   errors_[0][1]= abs(TRPZ_RES-EXACT_RES);
   errors_[0][2] = abs(SIMPS_RES-EXACT_RES);
   errors_[0][3] = abs(GL_RES-EXACT_RES);
   std::cout << "***************************************\n";
   
   N=4;
   degrees.push_back(double(N));
   MID_RES = nIntegrationMID(ToIntegrate,xSTART,xEND,N);
   TRPZ_RES = nIntegrationTRAPZ(ToIntegrate,xSTART,xEND,N);
   SIMPS_RES = nIntegrationSIMPS(ToIntegrate,xSTART,xEND,N);
   GL_RES = nIntegrationGL(ToIntegrate,xSTART,xEND,N); 
   std::cout << "********** TEST WITH N="<<N<<"**************\n";
   std::cout << "EXACT-RESULT of the integration: "<<EXACT_RES <<"\n";
   std::cout << "Mid-point-result : "   <<   MID_RES << "\n";
   std::cout << "Trapezoidal-result : " << TRPZ_RES << "\n";
   std::cout << "Simpson-result : " <<     SIMPS_RES << "\n";
   std::cout << "Gauss-Legendre-result : "<< GL_RES << "\n";

   // Fill the error vector:
   errors_[1][0] = abs(MID_RES-EXACT_RES);
   errors_[1][1] = abs(TRPZ_RES-EXACT_RES);
   errors_[1][2] = abs(SIMPS_RES-EXACT_RES);
   errors_[1][3] = abs(GL_RES-EXACT_RES);
   std::cout << "***************************************\n";
   
   N=5;
   degrees.push_back(double(N));
 
   MID_RES = nIntegrationMID(ToIntegrate,xSTART,xEND,N);
   TRPZ_RES = nIntegrationTRAPZ(ToIntegrate,xSTART,xEND,N);
   SIMPS_RES = nIntegrationSIMPS(ToIntegrate,xSTART,xEND,N);
   GL_RES = nIntegrationGL(ToIntegrate,xSTART,xEND,N);
  
  
   std::cout << "********** TEST WITH N="<<N<<"**************\n";
   std::cout << "EXACT-RESULT of the integration: "<<EXACT_RES <<"\n";
   std::cout << "Mid-point-result : "   <<   MID_RES << "\n";
   std::cout << "Trapezoidal-result : " << TRPZ_RES << "\n";
   std::cout << "Simpson-result : " <<     SIMPS_RES << "\n";
   std::cout << "Gauss-Legendre-result : "<< GL_RES << "\n";
   
   // Fill the error vector:
   errors_[2][0] = abs(MID_RES-EXACT_RES);
   errors_[2][1] = abs(TRPZ_RES-EXACT_RES);
   errors_[2][2] = abs(SIMPS_RES-EXACT_RES);
   errors_[2][3] = abs(GL_RES-EXACT_RES);
   std::cout << "***************************************\n";
   N=8;
   degrees.push_back(double(N));
 
   MID_RES = nIntegrationMID(ToIntegrate,xSTART,xEND,N);
   TRPZ_RES = nIntegrationTRAPZ(ToIntegrate,xSTART,xEND,N);
   SIMPS_RES = nIntegrationSIMPS(ToIntegrate,xSTART,xEND,N);
   GL_RES = nIntegrationGL(ToIntegrate,xSTART,xEND,N);
  
  
   std::cout << "********** TEST WITH N="<<N<<"**************\n";
   std::cout << "EXACT-RESULT of the integration: "<<EXACT_RES <<"\n";
   std::cout << "Mid-point-result : "   <<   MID_RES << "\n";
   std::cout << "Trapezoidal-result : " << TRPZ_RES << "\n";
   std::cout << "Simpson-result : " <<     SIMPS_RES << "\n";
   std::cout << "Gauss-Legendre-result : "<< GL_RES << "\n";
   
   // Fill the error vector:
   errors_[3][0] = abs(MID_RES-EXACT_RES);
   errors_[3][1] = abs(TRPZ_RES-EXACT_RES);
   errors_[3][2] = abs(SIMPS_RES-EXACT_RES);
   errors_[3][3] = abs(GL_RES-EXACT_RES);
   std::cout << "***************************************\n";
   
   std::vector<double> mid_error = {errors_[0][0],errors_[1][0],errors_[2][0],errors_[3][0]};
   std::vector<double> trz_error = {errors_[0][1],errors_[1][1],errors_[2][1],errors_[3][1]};
   std::vector<double> simps_error = {errors_[0][2],errors_[1][2],errors_[2][2],errors_[3][2]};
   std::vector<double> gl_error = {errors_[0][3],errors_[1][3],errors_[2][3],errors_[3][3]};

   /*
   using namespace matplot;
   
   hold(on);
   
   semilogy(degrees,mid_error)->line_width(2);
   semilogy(degrees,trz_error)->line_width(2);
   semilogy(degrees,gl_error,"--")->line_width(2);
   semilogy(degrees,simps_error,"-")->line_width(2);
   xlabel("N");
   ylabel("absolute-error");
   title("Error analysis");
   ::matplot::legend({"midpoint", "trapz","gauss-legendre","simpson"});
   
   show();
   */

   
  return 0;

  
 
}
