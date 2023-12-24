
// Intereface class:
// type: could be a Eigen::vectorXd or double
// Timestepping is the specified numerical method
// which i have implemented

template<template<class> class TimeStepping, class type>
class TimeIntegrator:
  public TimeStepping<type>
{
public:
  
  TimeIntegrator():
    m_time_scheme{TimeStepping<type>()} {};

  type solve(const double& tInit,const double& tFinal,std::function<type(double,type)> RHS,const type& x0)
  {
    return m_time_scheme.solve(tInit,tFinal,RHS,x0);
  }

protected:

  Timestepping<type> m_time_scheme;
  
};

template<class type>
class EULER_FIRST_ORDER
{
public:
  
  EULER_FIRST_ORDER();

  type solve(const double& tInit,const double& tFinal,std::function< type (double,type)> RHS,const type& x0){};

protected:
  // Coefficient for temporal schemes:
  Eigen::MatrixXd m_aij(1,1);
  Eigen::VectorXd m_bj(1);
  Eigen::VectorXd m_ci(1);

};

template<class type>
class CLASSIC_RK4
{
public:
  CLASSIC_RK4();

  type solve(const double& tInit,const double& tFinal,std::function< type (double,type)> RHS,const type& x0){};

protected:
  // Coefficient for temporal schemes:
  Eigen::MatrixXd m_aij(4,4);
  Eigen::VectorXd m_bj(4);
  Eigen::VectorXd m_ci(4);

}





