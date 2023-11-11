#include <algorithm>
#include <stdio.h>
#include <vector>
#include <set>
#include <random>
#include <iostream>

int main()
{
  std::default_random_engine rd{1};
  std::vector<int> random_numbers(100,0);
  
  std::uniform_int_distribution uniform(0,9);
  std::for_each(random_numbers.begin(),
		random_numbers.end(),
		[&uniform,&rd](int& n){n = uniform(rd);});

  // Sort the element:
  std::vector<int> sorted_num(random_numbers);
  
  std::sort(sorted_num.begin(),
	    sorted_num.end(),std::greater<int>());
  
  
  for(auto rn : sorted_num)
    std::cout << rn << " ";


  // Remove duplicates and sort
  std::set<int> s(sorted_num.begin(),
		  sorted_num.end());
  
    std::cout << "\n ---- SORTED ----"<<std::endl;
   for(auto rn : random_numbers)
    std::cout << rn << " ";
}
