#include <stdio.h>
#include <iostream>
#include <functional>
#include <cassert>
#include <string>
#include <variant>

int main()
{
  // every row 
  std::vector<std::variant<double,std::string,int> > vec;
  // Create an enumeration in the class

  enum types{
    categorical_string,
    numerical_int,
    numerical_double
  };

  std::vector<std::string> types = {"string","int","double"};
  // For every row, we have a counter that convert the data:
  counter = 0 ;
  // for loop
  if(counter == 0){
    vec.push_back(std::string("palazzo"));}
    else if( counter == 1)
      {
	vec.push_back(int(2));
      }
  

      
  
  
  
  /*
  vec.push_back(double(0.5));
  vec.push_back(std::string("palazzo"));
  vec.push_back(int(3));
  std::cout << std::get<1>(vec[1]) << std::endl;
  std::cout << std::get<2>(vec[2]) << std::endl;
  */
  //  std::cout << std::get<numerical_double>(vec[0]) << std::endl;
  return 0;
 
}
