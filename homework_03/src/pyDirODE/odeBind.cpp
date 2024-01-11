#include <pybind11/pybind11.h>

#include <pybind11/stl.h>

#include <pybind11/functional.h>

#include "ODE.hpp"



namespace py = pybind11;



PYBIND11_MODULE(odeBind,m)

{

  m.doc() = "Python module for conversion of the time-integration module";


  py::class_<TimeIntegrator<EULER_FIRST_ORDER,double>>
    pyTimeIntegratorEulerDouble(m,"pyTimeIntegratorDouble");

  pyTimeIntegratorEulerDouble.def(py::init<std::string,bool>());

  pyTimeIntegratorEulerDouble.def("solve",&TimeIntegrator<EULER_FIRST_ORDER,double>::solve);





  py::class_<TimeIntegrator<EULER_FIRST_ORDER,Eigen::VectorXd>>
    pyTimeIntegratorEulerEigen(m,"pyTimeIntegratorEulerEigen");

  pyTimeIntegratorEulerEigen.def(py::init<std::string,bool>());

  pyTimeIntegratorEulerEigen.def("solve",&TimeIntegrator<EULER_FIRST_ORDER,Eigen::VectorXd>::solve);





  py::class_<TimeIntegrator<CLASSIC_RK4,double>>
    pyTimeIntegratorRKDouble(m,"pyTimeIntegratorRKdouble");

  pyTimeIntegratorRKDouble.def(py::init<std::string,bool>());

  pyTimeIntegratorRKDouble.def("solve",&TimeIntegrator<CLASSIC_RK4,double>::solve);



  py::class_<TimeIntegrator<CLASSIC_RK4,Eigen::VectorXd>>
    pyTimeIntegratorRKEigen(m,"pyTimeIntegratorRKEigen");

  pyTimeIntegratorRKEigen.def(py::init<std::string,bool>());

  pyTimeIntegratorRKEigen.def("solve",&TimeIntegrator<CLASSIC_RK4,Eigen::VectorXd>::solve);

    



  py::class_<EULER_FIRST_ORDER<double>> pyEULERDouble(m,"pyEulerDouble");
  
  pyEULERDouble.def(py::init<>());

  pyEULERDouble.def(py::init<std::string,bool>());

  pyEULERDouble.def("solve",&EULER_FIRST_ORDER<double>::solve);



  py::class_<EULER_FIRST_ORDER<Eigen::VectorXd>> pyEULEREigen(m,"pyEulerEigen");

  pyEULEREigen.def(py::init<>());

  pyEULEREigen.def(py::init<std::string,bool>());

  pyEULEREigen.def("solve",&EULER_FIRST_ORDER<Eigen::VectorXd>::solve);



  py::class_<CLASSIC_RK4<double>> pyRKDouble(m,"pyEulerDouble");

  pyEULERDouble.def(py::init<>());

  pyEULERDouble.def(py::init<std::string,bool>());

  pyEULERDouble.def("solve",&EULER_FIRST_ORDER<double>::solve);



  py::class_<CLASSIC_RK4<Eigen::VectorXd>> pyRKEigen(m,"pyEulerEigen");

  pyEULEREigen.def(py::init<>());

  pyEULEREigen.def(py::init<std::string,bool>());

  pyEULEREigen.def("solve",&EULER_FIRST_ORDER<Eigen::VectorXd>::solve);

}
