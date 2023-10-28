#ifndef NEWTON_HPP__
#define NEWTON_HPP__

#include <functional>
#include <complex>


template<class T>
class NewtonSolver {
public:

  // define explicitly:
  typedef std::complex<T> complexT;
  
  NewtonSolver(const std::function<complexT (const complexT&)> &f, const std::function<complexT (const complexT&)> &df, const complexT &x0,
              const double &tolerance = 1e-12,
              const unsigned int &max_iterations = 100);

  complexT solve();

private:
  // declare the function wrapper
  const  std::function<complexT (const complexT&)> f;
  const std::function<complexT (const complexT&)>df;

  const complexT x0; //initial_condition
  const double tolerance;
  const unsigned int max_iterations;
};

#include "newton.tpl.hpp"

#endif /* NEWTON_HPP__ */
