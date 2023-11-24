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
#include <boost/algorithm/string.hpp>
#include <boost/histogram.hpp>
#include <boost/format.hpp>

using namespace CSV_READER;

namespace po = boost::program_options;

int main(int ac,const char* av[])
{

  
  // Specify the files with boost:
  po::options_description desc{"options"};

  desc.add_options()
    ("help,h","helper function")
    ("config-file,c",po::value<std::string>(),"Configuration file for row-structure")
    ("input-file,f",po::value<std::string>(),"path/to/input.csv file where the csv file is stored");

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
      std::cout << "CONFIGURATION-FILE: ";
      std::cout << MAP["config-file"].as<std::string>() <<" \n";
    }

  if(MAP.count("input-file"))
    {
      std::cout << "INPUT .CSV FILE: ";
      std::cout << MAP["input-file"].as<std::string>() <<" \n";
    }
  
  //specified by the user: create a map that maps the values given by the user to the integers:
  std::vector<std::string> row_structure = {"int","double","string","int","double"};

  std::map<std::string,size_t> _map_ = {{"double",0},{"string",1},{"int",2}};
  
  // Construct from the row-structure:
  DATA_FRAME df(MAP["config-file"].as<std::string>());
  
  df.read(MAP["input-file"].as<std::string>());

  bool is_numeric = df.IsNumeric(1);
  if(!is_numeric)
    throw std::invalid_argument("cannot do the mean\n");

   double mean = df.mean(2);
   double std_dev = df.stdDev(2);
   std::cout << std_dev << "\n";
   std::cout << mean << "\n";

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

   
   
   /* PRINT THE FIRST TWO COLUMNS: JUST TO CHECK IF THE ITERATOR WORKS:
   
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
   
   */
   // Perform a linear regression for the fourth and fifth column of the csv-file:
   auto [w,b] = df.LinearRegression<double,double>(4,5);
 

   std::cout << "weight :"<<w << " " << "bias: "<< b <<"\n";


   
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
   
  return 0;

  
 
}
