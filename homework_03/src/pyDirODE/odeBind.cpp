#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/functional.h>
#include "ODE.hpp"

namespace py = pybind11;

PYBIND11_MODULE(odeBind,m)
{
  m.doc() = "Python module for time-integration module";

  py::class_<EULER_FIRST_ORDER<double>> pyEULERDouble(m,"pyEulerDouble");
  pyEULERDouble.def(py::init<>());
  pyEULERDouble.def(py::init<std::string,bool>());
  pyEULERDouble.def("solve",&EULER_FIRST_ORDER<double>::solve);


  py::class_<TimeIntegrator<EULER_FIRST_ORDER,double>>
    pyTimeIntegratorEulerDouble(m,"pyTimeIntegratorDouble");
  pyTimeIntegratorEulerDouble.def(py::init<std::string,bool>());
  pyTimeIntegratorEulerDouble.def("solve",&TimeIntegrator<EULER_FIRST_ORDER,double>::solve);
  
}
