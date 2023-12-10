/*

  Examples:
    Create classes and subclasses with factory methods:
    Refer to the book "Design Patterns" for references.
*/

#include <memory>
#include <optional>
#include <iostream>
#include <boost/optional.hpp>

class NumericalQuadrature
{
public:
  NumericalQuadrature(unsigned int n):
    n_(n){};
  virtual void Evaluate()=0;
protected:
  unsigned int n_;
};

class SimpsonQuadrature:
  public NumericalQuadrature
{
public:
  SimpsonQuadrature(unsigned int n):
    NumericalQuadrature(n){};

  void Evaluate() override
  {
    std::cout << "Evaluate SimpsonQuadrature\n"<<std::endl;
  }
};

class TrapzQuadrature:
  public NumericalQuadrature
{
public:
  TrapzQuadrature(unsigned int n):
    NumericalQuadrature(n){};
    void Evaluate() override
  {
    std::cout << "Evaluate TrapezoidalQuadrature\n";
  }
};

using UniqueQuad = std::unique_ptr<NumericalQuadrature>;
using OpUniqueQuad  = std::optional<UniqueQuad>;

enum class Quadrature_type
  {
    Simpson=0,
    Trapz=1
  };

// Virtual base class
class AbstractQuadratureFactory
{
 public:
  virtual OpUniqueQuad doMakeClass(Quadrature_type QT,unsigned int n)=0;
};

class SimpsonQuadratureFactory:
  public AbstractQuadratureFactory
{
public:
  OpUniqueQuad doMakeClass(Quadrature_type QT,unsigned int n) override
  {

    return (QT==Quadrature_type::Simpson) ?
      std::optional<UniqueQuad>(std::move(std::make_unique<SimpsonQuadrature>(n))) : std::nullopt;
    
  }
};

class TrapzQuadratureFactory:
  public AbstractQuadratureFactory
{
public:
  OpUniqueQuad doMakeClass(Quadrature_type QT,unsigned int n) override
  {
    return (QT==Quadrature_type::Trapz) ?
      std::optional<UniqueQuad>(std::move(std::make_unique<TrapzQuadrature>(n))) : std::nullopt;
  }
};

/*

class AbstractQuadratureFactory
{
 public:
  AbstractQuadratureFactory(Quadrature_type QT,n):QT_{QT}
  {
   if(QT==Quadrature_type::Trapz)
     pQuad = std::make_unique<TrapezoidalQuadrature>(n);
   if(QT==Quadrature_type::Simpson)
     pQuad = std::make_unique<SimpsonQuadrature>(n);
  };

protected:
  Quadrature_type QT_;
  UniqueQuad pQuad;
};

class SimpsonQuadratureFactory:
  public AbstractQuadratureFactory
{
public:
  OpUniqueQuad doMakeClass(Quadrature_type QT,unsigned int n) override
  {
    if(QT==Quadrature_type::Simpson)
      {
        UniqueQuad pQuad = std::make_unique<SimpsonQuadrature>(n); 
	return std::optional<UniqueQuad>(std::move(pQuad));
      }
    return {};
    
  }
};

class TrapzQuadratureFactory:
  public AbstractQuadratureFactory
{
public:
  OpUniqueQuad doMakeClass(Quadrature_type QT,unsigned int n) override
  {
    return (QT==Quadrature_type::Trapz) ?
      std::optional<UniqueQuad>(std::move(std::make_unique<TrapzQuadrature>(n))) : std::nullopt;
  }
};
*/

// If we want to extend the hierarchy for other numerical formulas,
// we must extend both the factory and also the quadrature.



// Function to create a pointer to the base abstract-factory:
boost::optional<std::unique_ptr<AbstractQuadratureFactory>> createAF(Quadrature_type QT) noexcept
{
  if(QT == Quadrature_type::Trapz){
    std::unique_ptr<TrapzQuadratureFactory> pSF = std::make_unique<TrapzQuadratureFactory>();
    return boost::optional<std::unique_ptr<AbstractQuadratureFactory>>(std::move(pSF)); }
  else if(QT== Quadrature_type::Simpson){
    std::unique_ptr<SimpsonQuadratureFactory> pTF = std::make_unique<SimpsonQuadratureFactory>();
    return boost::optional<std::unique_ptr<AbstractQuadratureFactory>>(std::move(pTF));
    }
  else
    return boost::none;
}


int main()
{
  TrapzQuadratureFactory SQF;
  OpUniqueQuad pQuad = SQF.doMakeClass(Quadrature_type::Trapz,5);
  std::cout << pQuad.has_value() << std::endl;
  if(pQuad){
    pQuad.value()->Evaluate();
  }

  // Alternative manner:
  std::unique_ptr<AbstractQuadratureFactory> pFact = *createAF(Quadrature_type::Trapz);

  OpUniqueQuad pQuad_ = pFact->doMakeClass(Quadrature_type::Trapz,10);
  if(pQuad_)
    pQuad_.value()->Evaluate();


  std::unique_ptr<AbstractQuadratureFactory> f;
  std::unique_ptr<TrapzQuadratureFactory> g(new TrapzQuadratureFactory());

  f = std::move(g);

  if(!g && !f){
    std::cout << "I've moved the ownership\n"<<std::endl;
  }
 
  
  return 0;
}
