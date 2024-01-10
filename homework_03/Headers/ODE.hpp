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
  
  TimeIntegrator(std::string filename,bool write)
     {
       m_time_scheme = TimeStepping<type>(filename,write);
     };

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

  EULER_FIRST_ORDER() = default;
  
  EULER_FIRST_ORDER(std::string filename,bool write);

  type solve(const double& tInit,const double& tFinal,std::function< type (double,type)> RHS,const type& x0,const unsigned int N);

protected:
  // Coefficient for temporal schemes:
  Eigen::MatrixXd m_aij;
  Eigen::VectorXd m_bj;
  Eigen::VectorXd m_ci;
  std::string filename_;
  bool write_;

};

template<class type>
class CLASSIC_RK4
{
public:
  CLASSIC_RK4() = default;
  
  CLASSIC_RK4(std::string filename,bool write);

  type solve(const double& tInit,const double& tFinal,std::function< type (double,type)> RHS,const type& x0,const unsigned int N);

protected:
  // Coefficient for temporal schemes:
  Eigen::MatrixXd m_aij;
  Eigen::VectorXd m_bj;
  Eigen::VectorXd m_ci;
  std::string filename_;
  bool write_;

};


// Template functions to write comma separated values to a file:
template<class solType>
void writeSolution(const double& time,const solType& sol,
	      std::ofstream& outs,std::string separator);


#endif


