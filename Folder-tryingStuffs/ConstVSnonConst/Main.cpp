
#include <iostream>
#include <vector>
#include "header.hpp"
/*
class Array
{
 public:
  Array(const std::vector<float> &data) : data(data) {}

  // Writing operator:
   const float& operator() (unsigned int idx) const
  {
    
    std::cout<< "const version\n"<<std::endl;
    return data[idx];
  }
  // Reading operator:
  float& operator () (unsigned int idx)
  {
    std::cout<< "non-const version\n"<<std::endl;
    return data[idx];
  }

private:
  std::vector<float> data;
};
*/

int main()
{
  std::vector<double> vec{1.0,2.3,4.5,5.3};
  array<double> a(vec);
  a.getNum(2) = 35.5;
 return 0;
}
