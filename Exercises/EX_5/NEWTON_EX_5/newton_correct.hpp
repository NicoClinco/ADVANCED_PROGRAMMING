#ifndef NEWTON_HPP__
#define NEWTON_HPP__

#include <functional>
#include <complex>


template<class T>
class NewtonSolver {
public:

  NewtonSolver(const std::function<T(const T&)> &f, const std::function<T (const T&)> &df, const T &x0,
              const double &tolerance = 1e-12,
              const unsigned int &max_iterations = 100);

  T solve();

private:
  // declare the function wrapper
  const  std::function<T (const T&)> f;
  const std::function<T (const T&)>df;

  const T x0; //initial_condition
  const double tolerance;
  const unsigned int max_iterations;
};

#include "newton_correct.tpl.hpp"

#endif /* NEWTON_HPP__ */
