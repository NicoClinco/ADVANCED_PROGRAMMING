#ifndef _QUADRATURE_HPP_
#define _QUADRATURE_HPP_


#include <iostream>
#include <functional>
#include <numeric>
#include <cmath>
#include <gsl/gsl_math.h>
#include <gsl/gsl_integration.h>
#include <gsl/gsl_sf_gamma.h>
#include <cassert>
#include <memory>


namespace Integrate_1D
{

  /*
     GENERIC-PATTERN FOR THE QUADRATURE RULE:
     
    class <TYPE>Quadrature
    {
     - makeQuadWeights(startfrom,end)
     - makeQuadPnts(startfrom,end)
    }

  
  
   All the classes <TYPE>Quadrature
   have two methods:

   -makeQuadWeights()
   -makeQuadPnts()
  
    These two methods create the
    weights and the quadrature points
    in equispaced manner.

   The operator() of numericalIntegration
   is responsable for calculating the integral.

   Thus, if one wants to implement a specific quadrature rule,
   one has only to implement the weights and the points.

  */
  
class SimpsonQuadrature
{
public:

 virtual std::vector<double> makeQuadWeights(double a, double b,int n)
  {
    double h = (b-a)/(2*n);
    std::vector<double> weighs(2*n+1,0.0);
    weighs[0] = h/3;
    weighs[2*n] = h/3;
    int count = 1;
    std::generate(weighs.begin()+1,weighs.end()-1,
		  [&count,h]{double _w_ = (count%2) == 0 ?  (2.0*h/3.0) :  (4.0*h/3.0); count++; return _w_;});
  
    return weighs;
  };
  virtual std::vector<double> makeQuadPnts(double a, double b,int n)
  {
    double h = (b-a)/(2*n);
    std::vector<double> xp(2*n+1,0.0); // number of points equispaced
    double xi = a;
    std::generate(xp.begin()+1,xp.end(),[&xi,h](){return xi=xi+h;});
    return xp;
  };
}; // END SIMPSON-RULE
  
  
class TrapzQuadrature
{
  public:

  /* QUADRATURE-RULE:
    \int_{a}^{b} f(x) = \sum_{i} w_i f(xi)
                      = h/2*f(x0)+h*f(x1)+h*f(x2)+...+h/2*f(xN)
		      
     weights = [h/2,h,...,h/2]; quad_points =[a=x0,x1,...,xN=b];
  */
  virtual std::vector<double> makeQuadWeights(double a, double b,int n)
  {
    double h = (b-a)/n;
    std::vector<double> weighs(n+1,h);
    weighs[0] = h/2;
    weighs[n] = h/2;
    return weighs; 
  }
  virtual std::vector<double> makeQuadPnts(double a,double b,int n)
  {
  
    double h = (b-a)/n;
    std::vector<double> xp(n+1,0.0); // number of points equispaced
    double xi = a;
    std::generate(xp.begin()+1,xp.end(),[&xi,h](){return xi=xi+h;});

    return xp;
  }

}; // end TrapzQuadrature



class MidPointQuadrature
{
public:

  virtual std::vector<double> makeQuadWeights(double a, double b,int n)
  {
    // Equispaced interval:
    double h = (b-a)/n;
    return std::vector<double>(n,h); 
  }
  virtual std::vector<double> makeQuadPnts(double a,double b,int n)
  {
    // Equispaced interval
    double h = (b-a)/n;
    std::vector<double> pnts(n,0.0); pnts[0] = a+h/2;
    double xi = a+h/2;
    std::generate(pnts.begin()+1,pnts.end(),[&xi,h](){return xi=xi+h;});
    return pnts;
  }

}; // end MidPointQuadrature
  
  
class GaussLegeandreQuadrature
{
public:

  virtual std::vector<double> makeQuadWeights(double a, double b,unsigned int n)
  {
    std::unique_ptr<gsl_integration_glfixed_table> gslft(gsl_integration_glfixed_table_alloc(n));
    std::vector<double> weights(n);
    std::vector<double> pnts(n);
    //fill weights:
    for (unsigned int i =0;i<n;i++)
      gsl_integration_glfixed_point(a,b,i,&pnts[i],&weights[i],gslft.get());

    gsl_integration_glfixed_table_free(gslft.release()); // free memory
    assert(gslft==nullptr);
    
    return weights;
  }
  virtual std::vector<double> makeQuadPnts(double a,double b,unsigned int n)
  {
    std::vector<double> weights(n);
    std::vector<double> pnts(n);
    std::unique_ptr<gsl_integration_glfixed_table> gslft(gsl_integration_glfixed_table_alloc(n));
    for (unsigned int i =0;i<n;i++)
      gsl_integration_glfixed_point(a,b,i,&pnts[i],&weights[i],gslft.get());
    
    gsl_integration_glfixed_table_free(gslft.release()); // free memory
    
    assert(gslft==nullptr); 
    
    return pnts;
  }
 
}; // END GAUSS-LEGEANDRE INTEGRATION.
 
  
template<class QuadType>
class NUMERICAL_INTEGRATION:
  public QuadType
{
public:

  double operator () (std::function<double (double)> funToInt,double a, double b,int n) 
  {
    using vectorD = std::vector<double>;
    vectorD w_  = QuadType::makeQuadWeights(a,b,n);
    vectorD qp_ = QuadType::makeQuadPnts(a,b,n);
    assert(w_.size()==qp_.size());
    vectorD fxi(w_.size());
    std::transform(qp_.begin(),qp_.end(),fxi.begin(),funToInt);
    return std::inner_product(w_.begin(),w_.end(),fxi.begin(),0.0);
  }
};

}//end namespace

#endif
