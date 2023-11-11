#include <algorithm>
#include <stdio.h>
#include <vector>
#include <random>
#include <iostream>

int main()
{
  std::default_random_engine rd{1};
  std::vector<int> random_numbers(100,0);
  
  std::uniform_int_distribution uniform(0,9);
  std::for_each(random_numbers.begin(),
		random_numbers.end(),
		[&uniform,rd](int& n){n = uniform(rd);});
  for(auto rn : random_numbers)
    std::cout << rn << " ";
}
