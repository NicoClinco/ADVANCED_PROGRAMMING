#include <stdio.h>
#include <iostream>
#include <functional>
#include <fstream>
#include <algorithm>
#include <vector>
#include "ODE.hpp"

int main(){

  TimeIntegrator<EULER_FIRST_ORDER,double> tIntegrator;
  double tInit = 0.0;
  double tFin  = 0.1;
  double x0    = 0.5;

  double res = tIntegrator.solve(tInit,tFin,[](double t,double x){return x;},x0,50);
  std::cout << res << std::endl;


  // Ask if the user pass a function of double or a function of vector
  // Can i create a class that overload both scalar and vector, right?

  //std::ofstream of_("vector.txt");
 
   // std::for_each(v.begin(),v.end(),[&of_](double& _){of_<<_<<" ";});
   
   //of_.close();
   
  return 0;
}