#include <stdio.h>
#include <iostream>
#include <functional>
#include <string>
#include <fstream>
#include <sstream>
#include <variant>
#include <optional>
#include <cassert>

#include "DATA_FRAME.hpp"
#include "quad_module/Quadrature.hpp"

#include <cassert>

// BOOST LIBRARY:
#include <boost/program_options.hpp>
#include <boost/histogram.hpp>
#include <boost/format.hpp>
#include "matplotlibcpp.h"


using namespace CSV_READER;

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
  
  //specified by the user: create a map that maps the values given by the user to the integers:
  //std::vector<std::string> row_structure = {"int","double","string","int","double"};

  //********* FOLLOW THIS PIECE OF CODE TO UNDERSTAND ****** 

  //Step-1: Creating the object data-frame from the config-file:
  DATA_FRAME df(MAP["config-file"].as<std::string>());

  
  //Step-2: Reading the .csv file in input:
  df.read(MAP["input-file"].as<std::string>());


  //We can perform the average or the standard deviation
  //of a column : e.g. for the column in the CSV:

  // Suppose to take the sixth-column
  // which is the mean temperature in a whole day:
  
   double mean = df.mean(6);
   double std_dev = df.stdDev(6);

   std::cout << "AVERAGE OF THE MEAN TEMPERATURE: "<< mean <<std::endl;
   std::cout<< "STANDARD DEVIATION OF THE MEAN TEMPERATURE: "<<std_dev <<std::endl;
   
   

   // PLOT HISTOGRAM of the temperature:
   using namespace boost::histogram;

   // Generate an histogram for radiation:
   auto hRad = make_histogram(axis::regular<>(21,10,200, "solar-radiation"));

   auto RadiationData = df.getCol<double>(4);
   std::for_each(RadiationData.begin(), RadiationData.end(), std::ref(hRad));

   std::ostringstream os;
   
   for (auto&& x : indexed(hRad, coverage::all)) {
     os << boost::format("bin %2i [%4.1f, %4.1f): %i\n")
       % x.index() % x.bin().lower() % x.bin().upper() % *x;
   }
   
   std::cout << os.str() << "\n\n";


   // EXAMPLE for using the iterator:
   /* PRINT THE FIRST TWO COLUMNS: JUST TO CHECK IF THE ITERATOR WORKS:*/

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
     }

   // FROM HERE, THE MEAN, THE STD DEVIATION RESULTS WILL BE PUTTED INTO
   // THE FILE SPECIFIED IN OUTPUT:
   df.write(" "); //Specify the separator between the entries, default tab

   double mean6 = df.mean(6);
   double std_dev6 = df.stdDev(6);

   // Make the histogram, and report it into a file:
   df.makeHistogram<double>(6,"Mean temperature statistics",20);
   
   df.closeOutput();
   
   double mean5 = df.mean(5);

   
   /*
   if(MAP.count("output-file"))
     {
       std::string outfile = MAP["output-file"].as<std::string>();
       std::string separator=" ";
       CSV_WRITER writer(outfile,separator);

       // The user must specify where starting write.
       writer.write();

       writer<<"AVERAGE OF THE MEAN TEMPERATURE: "<< mean;
       writer.endrow();
       writer<<"STANDARD-DEVIATION OF THE MEAN TEMPERATURE: " << std_dev;
       writer.endrow();
       
       // The user must specify where the file can be closed.
       writer.close();
     }

   */
   using namespace Integrate_1D;
   numericalIntegration<MidPointQuadrature> nIntegrationMID;
   numericalIntegration<GaussLegeandreQuadrature> nIntegrationGL;
   numericalIntegration<SimpsonQuadrature> nIntegrationSIMPS;
   numericalIntegration<TrapzQuadrature> nIntegrationTRAPZ;


   // Example : Integration of f(x) = x^3:

   auto ToIntegrate = [](double x)
   {
     return x*x*x;
   };
  
   double xSTART = 1.0;
   double xEND   = 6.0;
   unsigned int N = 5;
   double MID_RES = nIntegrationMID(ToIntegrate,xSTART,xEND,N);
   double TRPZ_RES = nIntegrationTRAPZ(ToIntegrate,xSTART,xEND,N);
   double SIMPS_RES = nIntegrationSIMPS(ToIntegrate,xSTART,xEND,N);
   double GL_RES = nIntegrationGL(ToIntegrate,xSTART,xEND,N);

   std::cout <<"********************************************\n";
   std::cout<< "  TESTING OF THE QUADRATURE-POINTS CLASS  \n";
   std::cout<< "********************************************\n";
  
   std::cout << "********** TEST WITH N=5 **************\n";
   std::cout << "EXACT-RESULT of the integration: 323.75 \n";
   std::cout << "Mid-point-result : "   <<   MID_RES << "\n";
   std::cout << "Trapezoidal-result : " << TRPZ_RES << "\n";
   std::cout << "Simpson-result : " <<     SIMPS_RES << "\n";
   std::cout << "Gauss-Legeandre-result : "<< GL_RES << "\n";

   std::cout << "***************************************\n";
   N=10;
   MID_RES = nIntegrationMID(ToIntegrate,xSTART,xEND,N);
   TRPZ_RES = nIntegrationTRAPZ(ToIntegrate,xSTART,xEND,N);
   SIMPS_RES = nIntegrationSIMPS(ToIntegrate,xSTART,xEND,N);
   GL_RES = nIntegrationGL(ToIntegrate,xSTART,xEND,N);
  
  
   std::cout << "********** TEST WITH N=10 **************\n";
   std::cout << "EXACT-RESULT of the integration: 323.75 \n";
   std::cout << "Mid-point-result : "   <<   MID_RES << "\n";
   std::cout << "Trapezoidal-result : " << TRPZ_RES << "\n";
   std::cout << "Simpson-result : " <<     SIMPS_RES << "\n";
   std::cout << "Gauss-Legeandre-result : "<< GL_RES << "\n";

   std::cout << "***************************************\n";
   N=50;
   MID_RES = nIntegrationMID(ToIntegrate,xSTART,xEND,N);
   TRPZ_RES = nIntegrationTRAPZ(ToIntegrate,xSTART,xEND,N);
   SIMPS_RES = nIntegrationSIMPS(ToIntegrate,xSTART,xEND,N);
   GL_RES = nIntegrationGL(ToIntegrate,xSTART,xEND,N);
  
  
   std::cout << "********** TEST WITH N=50 **************\n";
   std::cout << "EXACT-RESULT of the integration: 323.75 \n";
   std::cout << "Mid-point-result : "   <<   MID_RES << "\n";
   std::cout << "Trapezoidal-result : " << TRPZ_RES << "\n";
   std::cout << "Simpson-result : " <<     SIMPS_RES << "\n";
   std::cout << "Gauss-Legeandre-result : "<< GL_RES << "\n";
   

   namespace plt = matplotlibcpp;

   plt::plot({1,3,2,4});
   plt::show();
   
  return 0;

  
 
}
