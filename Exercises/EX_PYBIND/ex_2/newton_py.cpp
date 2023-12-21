// File used for converting the newton solver
// in python
#include "newton.hpp"
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/functional.h>
#include <sstream>
#include <cmath>

namespace py = pybind11;

using funDouble = std::function<double(const double&)>&;


PYBIND11_MODULE(newton_py,m)
{
  m.doc() = "pybind-11 newton converted";
  
  py::class_<NewtonSolver<double>>(m, "NewtonSolver")
    // Same number of arguments in pybind:
    .def(py::init<funDouble,funDouble,double&,double&,unsigned int&>(),
	 py::arg(),py::arg(),py::arg(),py::arg("tolerance") = float(1e-12),py::arg("max_iterations") = int(100))
  .def("solve",&NewtonSolver<double>::solve);
    
    
}
