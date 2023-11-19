#include <stdio.h>
#include <iostream>
#include <functional>
#include <string>
#include <fstream>
#include <sstream>
#include <variant>
#include "DATA_FRAME.hpp"

/*
template<class type>
type lookup(std::variant<double,std::string,int> v)
{
  type x = std::get<type>(v);
  return x;
}

*/



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

  //double std_dev = df.stdDev(2);
  //std::cout << std_dev << "\n";
  //std::cout << df.countWord(3,"papera")<<"\n";

   for(auto itrow = df.rowIterbegin();itrow!=df.rowIterEnd();itrow++)
    {
      int col=0;
      
      for(auto itc = df.colIterbegin(itrow,0);itc!=df.colIterEnd(itrow,3);itc++)
	{
	 
	  if(col==0){
	     std::cout << std::get<int>(*itc) << " ";
	     *itc = int(4);
	     //  std::cout << std::get<int>(*itc)<<" ";
	       }
	  if(col==1)
	    std::cout << std::get<double>(*itc) <<" ";
	  if(col==2)
	    std::cout << std::get<std::string>(*itc) <<" ";
	  col++;
	}
      std::cout<<std::endl;
    }
  



  
  return 0;

  
 
}
