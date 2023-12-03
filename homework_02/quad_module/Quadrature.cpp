#include "Quadrature.hpp"

// EXPLICIT-INSTATION of the templates:


template class 
Integrate_1D::NUMERICAL_INTEGRATION<Integrate_1D::MidPointQuadrature>;

template class
Integrate_1D::NUMERICAL_INTEGRATION<Integrate_1D::TrapzQuadrature>;

template class
Integrate_1D::NUMERICAL_INTEGRATION<Integrate_1D::SimpsonQuadrature>;

template class
Integrate_1D::NUMERICAL_INTEGRATION<Integrate_1D::GaussLegeandreQuadrature>;
