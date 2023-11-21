#include <stdio.h>
#include <iostream>
#include <functional>
#include <string>
#include <fstream>
#include <sstream>
#include <variant>
#include <optional>
#include "DATA_FRAME.hpp"

#include <boost/program_options.hpp>
#include <boost/algorithm/string.hpp>

using namespace CSV_READER;

namespace po = boost::program_options;

int main(int ac,const char* av[])
{
  
  // Specify the files with boost:
  po::options_description desc{"options"};

  desc.add_options()
    ("help,h","helper function")
    ("config-file,c",po::value<std::string>(),"Configuration file for row-structure")
    ("input-file,f",po::value<std::string>(),"Input file where the data is stores");

  po::variables_map MAP;
  po::store(po::parse_command_line(ac,av,desc),MAP);
  po::notify(MAP);

  if(MAP.count("help"))
     std::cout << desc <<std::endl;

  if(MAP.count("config-file"))
    std::cout << MAP["config-file"].as<std::string>() <<" \n";

  if(MAP.count("input-file"))
    std::cout << MAP["input-file"].as<std::string>() <<" \n";
  
  
  //specified by the user: create a map that maps the values given by the user to the integers:
  std::vector<std::string> row_structure = {"int","double","string","int","double"};

  std::map<std::string,size_t> _map_ = {{"double",0},{"string",1},{"int",2}};
  // The user has to pass the data-structure:
  DATA_FRAME df(row_structure);
  df.read("input.txt");

  bool is_numeric = df.IsNumeric(1);
  if(!is_numeric)
    throw std::invalid_argument("cannot do the mean\n");

   double mean = df.mean(2);
   double std_dev = df.stdDev(2);
   std::cout << std_dev << "\n";
   std::cout << mean << "\n";
  std::cout << df.countWord(3,"papera")<<"\n\n\n";
  
   for(auto itrow = df.rowIterbegin();itrow!=df.rowIterEnd();itrow++)
    {
      size_t col=0;
      
      for(auto itc = df.colIterbegin(itrow,0);itc!=df.colIterEnd(itrow,2);itc++)
	{
	  size_t token = _map_[row_structure[col]];
	  auto value = *itc;
	  if(token==0){(value.has_value()) ? std::cout << std::get<double>(value.value()) : std::cout <<""; }
	    
	  if(token==1){(value.has_value()) ? std::cout << std::get<std::string>(value.value()) :std::cout <<""; }
	   
	  if(token==2){(value.has_value()) ? std::cout << std::get<int>(value.value()) :std::cout<<""; }
	  std::cout << " ";
	  col++;
	}
      std::cout<<std::endl;
	}
      std::cout<<std::endl;
   
  auto [w,b] = df.LinearRegression<int,double>(4,5);

  using split_vector_type = std::vector<std::string>;

  std::string stringa = "headers_cols = int,double,string,int,double";
  split_vector_type SplitVec;
  boost::split( SplitVec, stringa, boost::is_any_of("= , \t"), boost::token_compress_on );
  for(auto x : SplitVec)
    std::cout <<x << " "<< std::endl;
  
  

  
   std::cout << "weight :"<<w << " " << "bias: "<< b <<"\n";
 

  
  return 0;

  
 
}
