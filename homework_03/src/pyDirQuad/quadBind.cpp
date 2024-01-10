#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/functional.h>
#include "Quadrature.hpp"

using namespace Integrate_1D;

namespace py = pybind11;

PYBIND11_MODULE(quadBind, m) {
  m.doc() = "Python module for quadrature formulas"; // optional module docstring

  py::class_<SimpsonQuadrature> pySimp(m,"pySimps");
  pySimp.def(py::init<>());
  pySimp.def("makeQuadWeights",&SimpsonQuadrature::makeQuadWeights);
  pySimp.def("makeQuadPnts",&SimpsonQuadrature::makeQuadPnts);
  pySimp.def("__repr__",
	   [](const SimpsonQuadrature &sq) {
	     // TO FIX the output:
	     return "Simpson quadrature class";
	   });
  
  py::class_<TrapzQuadrature> pyTrapz(m,"pyTrapz");
  pyTrapz.def(py::init<>());
  pyTrapz.def("makeQuadWeights",&TrapzQuadrature::makeQuadWeights);
  pyTrapz.def("makeQuadPnts",&TrapzQuadrature::makeQuadPnts);
  pyTrapz.def("__repr__",
	   [](const TrapzQuadrature &sq) {
	     // TO FIX the output:
	     return "Trapezoidal quadrature class";
	   });
  
  py::class_<MidPointQuadrature> pyMidPoint(m,"pyMidPoint");
  pyMidPoint.def(py::init<>());
  pyMidPoint.def("makeQuadWeights",&MidPointQuadrature::makeQuadWeights);
  pyMidPoint.def("makeQuadPnts",&MidPointQuadrature::makeQuadPnts);
  pyMidPoint.def("__repr__",
	   [](const MidPointQuadrature &sq) {
	     // TO FIX the output:
	     return "MidPoint quadrature class";
	   });

  py::class_<GaussLegeandreQuadrature> pyGaussLegeandre(m,"pyGaussLegeandre");
  pyGaussLegeandre.def(py::init<>());
  pyGaussLegeandre.def("makeQuadWeights",&GaussLegeandreQuadrature::makeQuadWeights);
  pyGaussLegeandre.def("makeQuadPnts",&GaussLegeandreQuadrature::makeQuadPnts);
  pyGaussLegeandre.def("__repr__",
		 [](const GaussLegeandreQuadrature &sq) {
		   // TO FIX the output:
		   return "GaussLegeandre quadrature class";
		 });
  
  py::class_<NUMERICAL_INTEGRATION<SimpsonQuadrature>> pyNumSimp(m,"pyNumSimp");
  pyNumSimp.def(py::init<>());
  pyNumSimp.def("__call__",&NUMERICAL_INTEGRATION<SimpsonQuadrature>::operator());

  py::class_<NUMERICAL_INTEGRATION<TrapzQuadrature>> pyNumTrapz(m,"pyNumTrapz");
  pyNumTrapz.def(py::init<>());
  pyNumTrapz.def("__call__",&NUMERICAL_INTEGRATION<TrapzQuadrature>::operator());

  py::class_<NUMERICAL_INTEGRATION<MidPointQuadrature>> pyNumMid(m,"pyNumMid");
  pyNumMid.def(py::init<>());
  pyNumMid.def("__call__",&NUMERICAL_INTEGRATION<MidPointQuadrature>::operator());

  py::class_<NUMERICAL_INTEGRATION<GaussLegeandreQuadrature>> pyNumGaussLegeandre(m,"pyNumGaussLeg");
  pyNumGaussLegeandre.def(py::init<>());
  pyNumGaussLegeandre.def("__call__",&NUMERICAL_INTEGRATION<GaussLegeandreQuadrature>::operator());
}
