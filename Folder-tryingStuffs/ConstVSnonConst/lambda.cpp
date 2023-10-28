#include <iostream>

//  Tutorial on functors:
template<class T>
class Calculator
{
public:
  
  template<class U>
  friend class Add;
  void PrintResult(){ std::cout << result << std::endl;}
 private:
  T result = 0;
};

template<class T>  
class Add
{
public:
  Add(Calculator<T>& _c):c(_c){};

  void operator ()(const T& x,const T& y){c.result = x + y;}
  
  Calculator<T>& c;
  
};

int main()
{
  Calculator<double> c1;
  Add<double> add(c1);
  add(3.4,2.2);
  c1.PrintResult();

  double r = 0.5;
  // Examples of lambda functions:
  auto fun = [&] (double x) 
  {
    r++;
    return x;
  };

  float z = fun(r);

  std::cout << r << std::endl;
  
  return 0;


  
}
