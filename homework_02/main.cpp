#include <stdio.h>
#include <iostream>
#include <functional>
#include <string>
#include <fstream>
#include <sstream>
#include <variant>
#include "DATA_FRAME.hpp"

struct MyVisitor
{
  // A callable object used for access variant:

    int operator()(int i) const { 
      return i; 
    }
    double operator()(double f) const { 
      return f; 
    }
  std::string operator()( std::string s) const { 
	return s; 
    }

};


int main()
{
  // every row

  //specified by the user: create a map that maps the values given by the user to the integers:
  std::vector<std::string> row_structure = {"int","double","string","int","double"};

  // The user has to pass the data-structure:
  DATA_FRAME df(row_structure);
  df.read("input.txt");

  bool is_numeric = df.IsNumeric(1);
  if(!is_numeric)
    throw std::invalid_argument("cannot do the mean\n");

  double std_dev = df.stdDev(2);
  std::cout << std_dev << "\n";
  std::cout << df.countWord(3,"papera")<<"\n";
  /*
  std::variant<double,std::string,int> _var_ = {double(3.54)};
  double num = 0.0;
  std::visit([&num] (const auto& k) { num=k; },_var_);
  std::cout<<num<<std::endl;
  */
  return 0;
 
}
