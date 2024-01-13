#include <stdio.h>
#include <iostream>
#include <vector>
#include "interpolation.hpp"
#include <Eigen/Dense>

using namespace Eigen;
using namespace Interp;

int main(){

  //using vDouble = std::vector<double>;
  // Linear:
  LinearInterpolation LI({0.0,1.0,2.0,3.0},{0.0,1.0,2.0,3.0});

  std::cout << LI.interpolate(1.5) << "\n";

   
  //Polynomial:
  PolynomialInterpolation PI({0.0,1.0,2.0,3.0},{0.0,1.0,2.0,3.0});

  std::cout << PI.interpolate(1.5) << "\n";
  return 0;
}
