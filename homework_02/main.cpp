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
#include <gsl/gsl_math.h>
#include <gsl/gsl_integration.h>
#include <gsl/gsl_sf_gamma.h>
//#include "quad_module/Quadrature.hpp"
#include "quad_module/QuadratureV1.hpp"

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

   
   
   
  
   /*
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

   std::cout <<"********************************************\n";
   std::cout<< "  TESTING OF THE QUADRATURE-POINTS CLASS  \n";
   std::cout<< "********************************************\n";

   auto squareFun = [](double x){return x*x*x;};

   double xSTART = 1.0;
   double xEND   = 6.0;
   const unsigned int N_ =5;
   
   NumericalIntegration<MidPointQuadrature,N_> nIntegrationMID;
   double MID_RES = nIntegrationMID(squareFun,xSTART,xEND);

   NumericalIntegration<SimpsonQuadrature,N_> nIntegrationSIMPS;
   double SIMPS_RES = nIntegrationSIMPS(squareFun,xSTART,xEND);

   NumericalIntegration<GaussLegendreQuadrature,N_> nIntegrationGL;
   double GL_RES = nIntegrationGL(squareFun,xSTART,xEND);

   NumericalIntegration<TrapzQuadrature,N_> nIntegrationTR;
   double TRAPZ_RES = nIntegrationTR(squareFun,xSTART,xEND);

   std::cout << "********** TEST WITH N=5 **************\n";
   std::cout << "EXACT-RESULT of the integration: 323.75 \n";
   std::cout << "Mid-point-result : "   <<   MID_RES << "\n";
   std::cout << "Trapezoidal-result : " << TRAPZ_RES << "\n";
   std::cout << "Simpson-result : " <<     SIMPS_RES << "\n";
   std::cout << "Gauss-Legeandre-result : "<< GL_RES << "\n";


   const unsigned int N2=10;
   
   NumericalIntegration<MidPointQuadrature,N2> nIntegrationMID2;
   double MID_RES2 = nIntegrationMID2(squareFun,xSTART,xEND);
   
   NumericalIntegration<SimpsonQuadrature,N2> nIntegrationSIMPS2;
   double SIMPS_RES2 = nIntegrationSIMPS2(squareFun,xSTART,xEND);
   
   NumericalIntegration<TrapzQuadrature,N2> nIntegrationTR2;
   double TRAPZ_RES2 = nIntegrationTR2(squareFun,xSTART,xEND);
   
   //NumericalIntegration<GaussLegendreQuadrature,N2> nIntegrationGL2;
   //double GL_RES2 = nIntegrationGL2(squareFun,xSTART,xEND);
   
   std::cout << "********** TEST WITH N=5 **************\n";
   std::cout << "EXACT-RESULT of the integration: 323.75 \n";
   std::cout << "Mid-point-result : "   <<   MID_RES2 << "\n";
   std::cout << "Trapezoidal-result : " << TRAPZ_RES2 << "\n";
   std::cout << "Simpson-result : " <<     SIMPS_RES2 << "\n";
   //std::cout << "Gauss-Legeandre-result : "<< GL_RES2 << "\n";


   /*
   std::unique_ptr<gsl_integration_glfixed_table> gslft(gsl_integration_glfixed_table_alloc(10));// = std::make_unique<gsl_integration_glfixed_table>();
   
   std::vector<double> pnts(N2);
   std::vector<double> weights(N2);
   for (size_t i=0;i<N2;i++)
     {
       gsl_integration_glfixed_point(xSTART,xEND,i,&pnts[i],&weights[i],gslft.get());
       std::cout << pnts[i] << "\n" << weights[i] << "\n";
     }
   
   gsl_integration_glfixed_table_free(gslft.release());

   assert(gslft == nullptr);
   */
   
  return 0;

  
 
}
