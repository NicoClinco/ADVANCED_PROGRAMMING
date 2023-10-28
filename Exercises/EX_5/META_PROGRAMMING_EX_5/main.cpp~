//#include "newton.hpp"
#include <functional>
#include <iostream>
#include <limits>
#include <complex>
#include "newton_correct.hpp"

// In this case i don't know what class it is, right?
/*
template<template<class> class complex,class T>
complex<T> f(const complex<T>& x)
{
  return x*x;
}
*/

template <class T>
std::complex<T> f_(const std::complex<T>& x)
{
  return x*x+std::complex<T>(1.0);
}

template<class T>
std::complex<T> df_(const std::complex<T>& x)
{
  return std::complex<T>(2.0)*x;
}


template<class T>
T f(const T& x)
{
  return x*x + T(1.0);
}

template<class T>
T df(const T& x)
{
  return T(2.0)*x;
}


int main()
{
  typedef std::complex<double> complexDouble;
  typedef  std::complex<int> complexInt;
  
   complexDouble x0_(0.5,0.5);
  
   NewtonSolver<complexDouble> ns(f<complexDouble>,df<complexDouble>,x0_);
   complexDouble solution = ns.solve();
   std::cout << solution << std::endl;
     return 0;
}


/*
double df(const double& x)
{
  return 2*x;
}
*/
/*
int main() {
  // Function with real root: f(x) = x^2 - 1 = 0.
  {
    // Define function and its derivative.
    std::function<double(const double&)> fun = f;
    std::function<double(const double&)> dfun = df;

    // Create a NewtonSolver instance and find the root.
    const double x0 = 0.5;
    NewtonSolver solver(fun, dfun, x0);

    const double root = solver.solve();

    if (root != std::numeric_limits<double>::quiet_NaN()) {
      std::cout << "Approximate root: " << root << std::endl;
    } else {
      std::cout << "Failed to converge to a root." << std::endl;
    }
  }

  return 0;
}
*/
