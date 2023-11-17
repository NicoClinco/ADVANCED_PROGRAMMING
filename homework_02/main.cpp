#include <stdio.h>
#include <iostream>
#include <functional>
#include <string>
#include <fstream>
#include <sstream>
#include <variant>
#include "DATA_FRAME.hpp"


template<class type>
type lookup(std::variant<double,std::string,int> v)
{
  type x = std::get<type>(v);
  return x;
}



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
  std::variant<double,std::string,int> var{"lol"};
  std::string s = lookup<std::string>(var);

  //std::vector<std::string> thirdCol = df.getCol<std::string>(3);

  std::vector<int> thirdCol = df.getCol<int>(1);
  for (auto el : thirdCol )
	std::cout << el << std::endl;

  return 0;
 
}
