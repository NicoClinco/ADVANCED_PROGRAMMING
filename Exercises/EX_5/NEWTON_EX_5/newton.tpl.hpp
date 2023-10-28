#include "newton.hpp"
#include <cmath>


template<class T>
NewtonSolver<T>::NewtonSolver(const std::function<complexT (const complexT&)> &f, const std::function<complexT (const complexT&)>& df,
                           const complexT &x0, const double &tolerance,
                           const unsigned int &max_iterations)
  : f(f), df(df), x0(x0),tolerance(tolerance), max_iterations(max_iterations) {}

template<class T>
std::complex<T> NewtonSolver<T>::solve() {
  
  // Initial condition:
  complexT x = x0;

  unsigned int it = 0;

  while (it < max_iterations) {
    
    complexT x_old = x;
    x = x - f(x)/df(x);

    // solve the equation:
    if(std::abs(x-x_old)<tolerance)
      return x;
    
    ++it;
  }

  // Indicates failure to converge.
  return std::numeric_limits<double>::quiet_NaN();
}
