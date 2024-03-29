#include <stdio.h>
#include <iostream>
#include <functional>
#include <fstream>
#include <algorithm>
#include <vector>
#include "ODE.hpp"
#include <Eigen/Dense>

using namespace Eigen;

int main(){

  std::string filenameRK4 = "outputRK4.txt";

  std::string filenameEU = "outputEU.txt";
  
    // TimeIntegrator<EULER_FIRST_ORDER,double> tIntegratorEU();
  TimeIntegrator<EULER_FIRST_ORDER,VectorXd> tIntegratorEU_(filenameEU,true);
  
  //TimeIntegrator<CLASSIC_RK4,double> tIntegratorRK4;
  TimeIntegrator<CLASSIC_RK4,VectorXd> tIntegratorRK4_(filenameRK4,true);
  
  double tInit = 0.0;
  double tFin  = 0.1;
  double x0    = 0.5;
  VectorXd x0_(5);
  x0_ << x0,x0,x0,x0,x0;

  
  
  //double res_EU_1 = tIntegratorEU.solve(tInit,tFin,[](double t,double x){return x;},x0,50);

  VectorXd res_EU_1_v = tIntegratorEU_.solve(tInit,tFin,[](double t,VectorXd x){return x;},x0_,20);
  VectorXd res_RK_4_v = tIntegratorRK4_.solve(tInit,tFin,[](double t,VectorXd x){return x;},x0_,20);
  
  //double res_RK_4 = tIntegratorRK4.solve(tInit,tFin,[](double t,double x){return x;},x0,50);

  
  
  //std::cout << res_EU_1 << std::endl;
  std::cout << res_EU_1_v << std::endl;


  std::cout << res_RK_4_v << std::endl;
  //std::cout << res_RK_4 << std::endl;
   
  return 0;
}
