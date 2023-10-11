#include "../include/calculator.hpp"
#include <iostream>

int main()
{
  float a{5.5};
  float b{4.5};

  std::cout << Add(a,b) << std::endl;
  std::cout << Sub(a,b) << std::endl; 
  return 0;
}
