#include <functional>
#include <iostream>

// META-PROGRAMMING //
template <int N>
class factorial
{
public:
  static constexpr int val = (factorial<N-1>::val)*N;
};

/* Specialization of the factorial*/
template <>
 class factorial<0>
{
public:
    static constexpr int val = 1;
};
  
  

int main()
{
  
  constexpr int fact_5 = factorial<5>::val;
  std::cout<< fact_5 << "\n"<<std::endl;
   return 0;
}
