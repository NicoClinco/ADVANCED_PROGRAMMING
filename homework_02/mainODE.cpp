#include <stdio.h>
#include <iostream>
#include <functional>
#include <typeinfo>

/*
template<class type>
class VectorField
{
public:
  VectorField(const type& value):
    value_{value}{};
  // Read:
    std::vector<type> operator()() const{
    return value_;
  }
  // Write:
  std::vector<type>& operator()(){
    return value_;
      }
private:
  std::vector<type> value_;
};
*/


template<class type>
class EULER_FIRST_ORDER
{
public:
  
  EULER_FIRST_ORDER(){}

  type solve(const double& tInit,const double& tFinal,std::function< type (type)> RHS,const type& x0){}
};

// Specialization for double:
template<>
double EULER_FIRST_ORDER<double>::solve(const double& tInit,const double& tFinal,std::function< double (double)> RHS,const double& x0)
{
  unsigned int Nstep = 1000;
  unsigned int counter = 0;
  const double& dt = (tFinal-tInit)/Nstep;

  double xFinal = x0;
  while(counter<Nstep)
    {
      xFinal+=dt*RHS(xFinal);
      counter++;
    }
  
  return xFinal;
}


// Specialization for vector:
template<>
std::vector<double> Euler_FIRST_ORDER<double>::solve(const double& tInit,const double& tFinal,std::function< std::vector<double> (std::vector<double>)> RHS,const std::vector<double>& x0)
{
  return x0;
}



template<template<class> class TimeStepping, class type>
class TimeIntegrator:
  public TimeStepping<type>
{
public:
  TimeIntegrator():
    TimeStepping<type>{} {};

  type solve(const double& tInit,const double& tFinal,std::function<type(type)> RHS,const type& x0)
  {
    return TimeStepping<type>::solve(tInit,tFinal,RHS,x0);
  }
};


int main(){

  TimeIntegrator<EULER_FIRST_ORDER,double> tIntegrator;
  double tInit = 0.0;
  double tFin  = 0.1;
  double x0    = 0.5;

  double res = tIntegrator.solve(tInit,tFin,[](double x){return x;},x0);
  std::cout << res << std::endl;
  // Maybe do a new datastructure?
  

  // Ask if the user pass a function of double or a function of vector
  // Can i create a class that overload both scalar and vector, right?
  
  return 0;
}
