#include <stdio.h>
#include <iostream>
#include <functional>
#include <string>
#include <fstream>
#include <sstream>
#include <variant>
#include "DATA_FRAME.hpp"


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

  DATA_FRAME::RowIterator row_iter = df.rowIterbegin();
  int countRow = 0;
  for(row_iter;row_iter!=df.rowIterEnd();row_iter++)
    {
    auto& bho = *(row_iter);
    bho[0] = int(3);
    }

  for(row_iter=df.rowIterbegin();row_iter!=df.rowIterEnd();row_iter++)
    {
    auto& bho = *(row_iter);
    std::cout<<std::get<int>(bho[0]);
    }

 
  return 0;
 
}
