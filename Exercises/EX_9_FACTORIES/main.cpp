/*

  Examples:
    Create classes and subclasses with factory methods:
    Refer to the book "Design Patterns" for references.
*/

#include <memory>
#include <optional>
#include <iostream>

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
    std::cout << "Simpson-evaluating\n";
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
    std::cout << "Trapz-evaluating\n";
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

// If we want to extend the hierarchy for other numerical formulas,
// we must extend both the factory and also the quadrature.

int main()
{
  TrapzQuadratureFactory SQF;
  OpUniqueQuad pQuad = SQF.doMakeClass(Quadrature_type::Trapz,5);
  std::cout << pQuad.has_value() << std::endl;
  if(pQuad){
    std::cout << "ok\n";
    pQuad.value()->Evaluate();
  }
 
  
  return 0;
}
