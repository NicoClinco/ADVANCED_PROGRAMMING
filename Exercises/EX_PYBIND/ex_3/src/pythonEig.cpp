#include "eigen_op.hpp"
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/eigen/matrix.h>


/*
  Functions to convert
 
 */

namespace py = pybind11;

PYBIND11_MODULE(pythonEig,m)
{
  m.def("mat_mult",&mult_op,"Eigen-matrixes multiplication");
  m.def("mat_inv",&inv_op,"Eigen-matrix inverse function");
}
