#include <string>
#include <iostream>
#include <vector>


/*
  Store a function pointer into a class.
 */

template<class type>
class ADdouble
{
  
  public:

  ADdouble(type (*fToStore)(const type&)):
    _func_(fToStore)
  {
  }
  
  virtual type evaluate(const type& num){
    return _func_(num);};

  virtual type evaluate_derivative(){return type(0);};

 private:

  type (*_func_)(const type&); 
  //Pointer to a function:
  
};


float Monomial(const float& x)
{
  return 3.0*x + 2.0;
}

  
int main()
{
  ADdouble<float> Amonomial(Monomial);
  std::cout<<Amonomial.evaluate(0.5);
}
