#ifndef ODE_INT_HPP
#define ODE_INT_HPP

#include <Eigen/Dense>

/*
Intereface class:
  type: could be a Eigen::vectorXd or double
  Timestepping is the specified numerical method
  that could be for vectors or for scalars.
*/
template<template<class> class TimeStepping, class type>
class TimeIntegrator:
  public TimeStepping<type>
{
public:
  
  TimeIntegrator():
    m_time_scheme{TimeStepping<type>()} {};

  type solve(const double& tInit,const double& tFinal,std::function<type(double,type)> RHS,const type& x0,const unsigned int N)
  {
    return m_time_scheme.solve(tInit,tFinal,RHS,x0,N);
  }

protected:

  TimeStepping<type> m_time_scheme;
  
};

template<class type>
class EULER_FIRST_ORDER
{
public:
  
  EULER_FIRST_ORDER();

  type solve(const double& tInit,const double& tFinal,std::function< type (double,type)> RHS,const type& x0,const unsigned int N);

protected:
  // Coefficient for temporal schemes:
  Eigen::MatrixXd m_aij;
  Eigen::VectorXd m_bj;
  Eigen::VectorXd m_ci;

};

template<class type>
class CLASSIC_RK4
{
public:
  CLASSIC_RK4();

  type solve(const double& tInit,const double& tFinal,std::function< type (double,type)> RHS,const type& x0,const unsigned int N);

protected:
  // Coefficient for temporal schemes:
  Eigen::MatrixXd m_aij;
  Eigen::VectorXd m_bj;
  Eigen::VectorXd m_ci;

};


#endif


