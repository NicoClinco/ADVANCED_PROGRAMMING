#include <stdio.h>
#include <iostream>
#include <boost/math/quadrature/trapezoidal.hpp>
#include <functional>
#include <numeric>
#include <cmath>
#include <stdio.h>


namespace Integrate_1D
{

  /*
     GENERIC-PATTERN FOR THE QUADRATURE RULE:
     
    class <TYPE>Quadrature
    {
     - makeQuadWeights(startfrom,end)
     - makeQuadPnts(startfrom,end)
     - operator()(fun,startfrom,end)
    }

  
  
   All the classes <TYPE>Quadrature
   have two methods:

   -makeQuadWeights()
   -makeQuadPnts()
  
    These two methods create the
    weights and the quadrature points
    in equispaced manner.

   The operator() is overloaded
   and is called in the interface class
   numericalIntegration.

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
  double operator()(std::function<double (double)> funToInt,double a,double b,int n)
  {
    // Use the composite trapezoidal rule:
 
    // Divide the interval [a,b] in subintervals and obtain the quadrature points:
    std::vector<double> w_ = makeQuadWeights(a,b,n);
    std::vector<double> qp_= makeQuadPnts(a,b,n);
    
    // Evaluate function in the quadrature points:
    std::vector<double> fxi(2*n+1);
    std::transform(qp_.begin(),qp_.end(),fxi.begin(),funToInt);

    // Return the inner product:
    return std::inner_product(w_.begin(),w_.end(),fxi.begin(),0.0);
  }
  
};
  
  
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
  
  double operator()(std::function<double (double)> funToInt,double a,double b,int n)
  {
    // Use the composite trapezoidal rule:
 
    // Divide the interval [a,b] in subintervals and obtain the quadrature points:
    std::vector<double> w_ = makeQuadWeights(a,b,n);
    std::vector<double> qp_    = makeQuadPnts(a,b,n);
    
    // Evaluate function in the quadrature points:
    std::vector<double> fxi(n+1);
    std::transform(qp_.begin(),qp_.end(),fxi.begin(),funToInt);

    // Return the inner product:
    return std::inner_product(w_.begin(),w_.end(),fxi.begin(),0.0);
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
    std::vector<double> pnts(n,0.0); pnts[0] = h/2;
    double xi = a+h/2;
    std::generate(pnts.begin()+1,pnts.end(),[&xi,h](){return xi=xi+h;});
    return pnts;
  }
  
  double operator()(std::function<double (double)> funToInt,double a,double b,int n) 
  {
    // Divide the interval [a,b] in n subintervals and obtain the quadrature points:
    std::vector<double> w_ = makeQuadWeights(a,b,n);
    std::vector<double> qp_    = makeQuadPnts(a,b,n);

    // Evaluate function in the quadrature points:
    std::vector<double> fxi(n);
    std::transform(qp_.begin(),qp_.end(),fxi.begin(),funToInt);

    // Return the inner product:
    return std::inner_product(w_.begin(),w_.end(),fxi.begin(),0.0);
  }
}; // end MidPointQuadrature
  
  
template<class QuadType>
class numericalIntegration:
  public QuadType
{
public:

  double operator () (std::function<double (double)> funToInt,double a, double b,int n) 
  {
    return  QuadType::operator()(funToInt,a,b,n);
  }
};

}//end namespace

// Function to integrate:
double ToIntegrate(double x)
{
  return -3*x*x;
}

int main()
{
  // The class numerical Integration inherits from
  // the specific-quadrature rule used.

  // With this design-pattern we can simply call
  // the operator () of the interface class and specify
  // the number of points required WITHOUT instanciate
  // any object for the specific quadrature rule.
  using namespace Integrate_1D;
  numericalIntegration<MidPointQuadrature> nIntegrationMID;

  double xSTART = 1.0;
  double xEND   = 3.0;
  double MID_RES = nIntegrationMID(ToIntegrate,xSTART,xEND,4);

  numericalIntegration<TrapzQuadrature> nIntegrationTR;
  double TRAPZ_RES = nIntegrationTR(ToIntegrate,xSTART,xEND,4);


  numericalIntegration<SimpsonQuadrature> nIntegrationSIMPS;

  double SIMPS_RES = nIntegrationSIMPS(ToIntegrate,xSTART,xEND,4);
 
   std::cout << "Exact-result, func: -3x^2 from 1 to 3 :"<< -26.0<<std::endl;
   std::cout << "Mid-point-result : "   <<   MID_RES << "\n";
   std::cout << "Trapezoidal-result : " << TRAPZ_RES << "\n";
   std::cout << "Simpson-result : " << SIMPS_RES << "\n";
  return 0;
}