#include <string>
#include <iostream>
#include <vector>
#include "ADCLASSES.h"


template<class type>
Sum<type>& operator +
(
 const ADexpression<type>& a,
 const ADexpression<type>& b
)
{
  Sum<type>* _sum_ = new Sum<type>(a,b);
  return (*_sum_);
}

template<class type>
Product<type>& operator *
(
 const ADexpression<type>& a,
 const ADexpression<type>& b
)
{
  Product<type>* _prod_ = new Product<type>(a,b);
  return (*_prod_);
}

  
int main()
{

  float x = 0.5;
  ADexpression<float>* _scalar_ = new Var<float>(x);

  ADexpression<float>* _scalarII_ =new Var<float>(x+0.5);

  std::cout << _scalar_->evaluate()<<"\n";
  
  std::cout << _scalarII_->evaluate()<<"\n";

  ADexpression<float>* _sum_ = new Sum<float>( *_scalar_,*_scalarII_);

  std::cout << _sum_->evaluate()<< "\n";
  
  ADexpression<float>* _prod_ = new Product<float>( *_scalar_,*_scalar_);

  std::cout <<"prod: "<<  _prod_->evaluate_der() << std::endl;


  ADexpression<float>& sumOP = (*_scalar_)+(*_scalarII_);
  
  std::cout<< sumOP.evaluate()<<"\n";

  ADexpression<float>& prodOP= (*_scalar_) * (*_scalar_);

  std::cout <<"prodOP: "<<  prodOP.evaluate_der()<<"\n";
  
  return 0;
}
