#include <stdio.h>
#include <iostream>
#include <functional>
#include <string>
#include <variant>
#include <optional>
#include <cassert>

#include "DATA_FRAME.hpp"

// BOOST LIBRARY:
#include <boost/program_options.hpp>
#include <boost/histogram.hpp>
#include <boost/format.hpp>

namespace po = boost::program_options;

int main(int ac,const char* av[])
{

  
  // Specify the files with boost:
  po::options_description desc{"Please, specify the config file and the .csv file:"};

  desc.add_options()
    ("help,h","helper function")
    ("config-file,c",po::value<std::string>(),"Configuration file for row-structure")
    ("input-file,f",po::value<std::string>(),"path/to/input.csv file where the csv file is stored")
    ("output-file,o",po::value<std::string>(),"path/to/output.txt file where various operations are saved");

  po::variables_map MAP;
  po::store(po::parse_command_line(ac,av,desc),MAP);
  po::notify(MAP);

  // HELPER FOR PARSING STUFFS:
  if(MAP.count("help"))
    {
      std::cout << desc <<std::endl;
      return 0;
    }

  assert(MAP.count("config-file") && MAP.count("input-file"));
    
  if(MAP.count("config-file"))
    {
      std::cout << "CONFIGURATION-FILE SELECTED: ";
      std::cout << MAP["config-file"].as<std::string>() <<" \n";
    }

  if(MAP.count("input-file"))
    {
      std::cout << "INPUT .CSV FILE SELECTED: ";
      std::cout << MAP["input-file"].as<std::string>() <<" \n";
    }

  if(MAP.count("output-file"))
    {
      std::cout << "OUTPUT FILE SELECTED:  ";
      std::cout << MAP["output-file"].as<std::string>() <<" \n";
    }
  

  using namespace CSV_READER;
  //********* FOLLOW THIS PIECE OF CODE TO UNDERSTAND ****** 

  //Step-1: Creating the object data-frame from the config-file:
  DATA_FRAME df(MAP["config-file"].as<std::string>());

  
  //Step-2: Reading the .csv file in input, specify if it has an header
  // which is used as "title"
  df.read(MAP["input-file"].as<std::string>(),true);


  //We can perform the average or the standard deviation
  //of a column : e.g. 
   double mean = df.mean(6);
   double std_dev = df.stdDev(6);

   std::cout << "AVERAGE OF THE MEAN TEMPERATURE: "<< mean <<std::endl;
   std::cout<< "STANDARD DEVIATION OF THE MEAN TEMPERATURE: "<<std_dev <<std::endl;


   // Max temperature for example: (See London.csv)
   std::vector<double> max_Temp = df.getCol<double>("max_temp");
   double avg_max_Temp = std::accumulate(max_Temp.begin(),max_Temp.end(),0.0);
   avg_max_Temp/=max_Temp.size();

   if(avg_max_Temp == df.mean(5))
     std::cout << " Equal-check passed\n";
   

   //Map used in the class for the variant:
   std::map<std::string,int> _map_ = df.map();

   // Row structure
   std::vector<std::string> row_structure =df.rowstructure();
   

   /* --------- ITERATOR -----------------*/
   // EXAMPLE : PRINT [1,5) COLUMNS:
   
   size_t col_begin=1;
   size_t col_end = 5;
   size_t col = 0;
   for(auto itrow = df.crowIterbegin()+30;itrow!=df.crowIterEnd()-15100;itrow++)
    {
      col=col_begin;
      
      for(auto itc = df.ccolIterbegin(itrow,col_begin);itc!=df.ccolIterEnd(itrow,col_end);itc++)
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
      
   
   // Perform a linear regression for the fourth and fifth column of the csv-file:
   auto [w,b] = df.LinearRegression<double,double>(4,5);
   std::cout << "weight :"<<w << " " << "bias: "<< b <<"\n";

   // WRITE in the output file as specified by the user:
   if(MAP.count("output-file"))
     {
       std::string outfile = MAP["output-file"].as<std::string>();
       df.setOutputfile(outfile); 
    

       df.write(" "); //Specify the separator between the entries, default tab
       
       // FROM HERE, THE MEAN, THE STD DEVIATION RESULTS WILL BE PUTTED INTO
       // THE FILE SPECIFIED IN OUTPUT:
       df.mean(6);
       df.stdDev(6);

      
       // Make the histogram, and report it into a file:
       df.makeHistogram<double>(6,"Mean temperature statistics",20);
   
       df.closeOutput();
     }
   
   // Move constructor-testing:
   DATA_FRAME df_II = std::move(df);
   std::cout << df_II.get_data().size() << std::endl;
   
  return 0;

  
 
}
