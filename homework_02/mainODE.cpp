#include <stdio.h>
#include <iostream>
#include <functional>
#include <fstream>
#include <algorithm>
#include <vector>
#include <boost/numeric/ublas/vector.hpp>
#include <boost/numeric/ublas/io.hpp>
#include <boost/qvm/scalar_traits.hpp>

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
  // TO DO: give the possibility for the time-step
  unsigned int Nstep = 1000;
  unsigned int counter = 0;
  const double& dt = (tFinal-tInit)/Nstep;

  
  
  double xFinal{x0};
  while(counter<Nstep)
    {
      xFinal+=dt*RHS(xFinal);
      counter++;
    }
  
  return xFinal;
}


// Specialization for vector:
template<>
std::vector<double>
EULER_FIRST_ORDER<std::vector<double> >::solve
(const double& tInit,const double& tFinal,
 std::function< std::vector<double> (std::vector<double>)> RHS,const std::vector<double>& x0)
{
  unsigned int Nstep = 1000;
  unsigned int counter = 0;
  const double& dt = (tFinal-tInit)/Nstep;

  std::vector<double> xFinal{x0};
  while(counter<Nstep)
  {
    //xFinal+=dt*RHS(xFinal);
  }
  
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
    //remember to put write_every
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
 using namespace boost::numeric::ublas;
 
 vector<double> v(3,0.5);

  // Ask if the user pass a function of double or a function of vector
  // Can i create a class that overload both scalar and vector, right?

 std::ofstream of_("vector.txt");
 
   std::for_each(v.begin(),v.end(),[&of_](double& _){of_<<_<<" ";});
   
   of_.close();
   
  return 0;
}
