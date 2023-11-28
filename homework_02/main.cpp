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
#include <matplot/matplot.h>


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
    

       df.write(" "); //Specify the separator between the entries, default tab
       
       // FROM HERE, THE MEAN, THE STD DEVIATION RESULTS WILL BE PUTTED INTO
       // THE FILE SPECIFIED IN OUTPUT:
       double mean6 = df.mean(6);
       double std_dev6 = df.stdDev(6);

      
       // Make the histogram, and report it into a file:
       df.makeHistogram<double>(6,"Mean temperature statistics",20);
   
       df.closeOutput();
     }


   /*--- MODULE FOR NUMERICAL INTEGRATION --TESTING------- */
   using namespace Integrate_1D;
   numericalIntegration<MidPointQuadrature> nIntegrationMID;
   numericalIntegration<GaussLegeandreQuadrature> nIntegrationGL;
   numericalIntegration<SimpsonQuadrature> nIntegrationSIMPS;
   numericalIntegration<TrapzQuadrature> nIntegrationTRAPZ;


   // Example : Integration of f(x) = x:

   // All the formulas has to be exact for this function:
   auto ToIntegrate0 = [](double x)
   {
     return x;
   };

   double xSTART = 0.0;
   double xEND   = 2.0;
   double EXACT_RES0 = 2.0;
   unsigned int N0;
   std::vector<double> degrees0;
   std::vector<std::vector<double>> errors0_(3,std::vector<double>(4));


   std::cout <<"********************************************\n";
   std::cout<< "  TESTING FOR f(x) =x                       \n";
   std::cout<< "********************************************\n";

   N0=2;
   double MID_RES0 = nIntegrationMID(ToIntegrate0,xSTART,xEND,N0);
   double TRPZ_RES0 = nIntegrationTRAPZ(ToIntegrate0,xSTART,xEND,N0);
   double SIMPS_RES0 = nIntegrationSIMPS(ToIntegrate0,xSTART,xEND,N0);
   double GL_RES0 = nIntegrationGL(ToIntegrate0,xSTART,xEND,N0);
   
   std::cout << "********** TEST WITH N="<<N0<<"**************\n";
   std::cout << "EXACT-RESULT of the integration: "<<EXACT_RES0 <<"\n";
   std::cout << "Mid-point-result : "   <<   MID_RES0 << "\n";
   std::cout << "Trapezoidal-result : " << TRPZ_RES0 << "\n";
   std::cout << "Simpson-result : " <<     SIMPS_RES0 << "\n";
   std::cout << "Gauss-Legeandre-result : "<< GL_RES0 << "\n";

   errors0_[0][0] = abs(MID_RES0-EXACT_RES0);
   errors0_[0][1]= abs(TRPZ_RES0-EXACT_RES0);
   errors0_[0][2] = abs(SIMPS_RES0-EXACT_RES0);
   errors0_[0][3] = abs(GL_RES0-EXACT_RES0);

   std::cout << "***************************************\n";

   N0=4;
   MID_RES0 = nIntegrationMID(ToIntegrate0,xSTART,xEND,N0);
   TRPZ_RES0 = nIntegrationTRAPZ(ToIntegrate0,xSTART,xEND,N0);
   SIMPS_RES0 = nIntegrationSIMPS(ToIntegrate0,xSTART,xEND,N0);
   GL_RES0 = nIntegrationGL(ToIntegrate0,xSTART,xEND,N0);
   
   std::cout << "********** TEST WITH N="<<N0<<"**************\n";
   std::cout << "EXACT-RESULT of the integration: "<<EXACT_RES0 <<"\n";
   std::cout << "Mid-point-result : "   <<   MID_RES0 << "\n";
   std::cout << "Trapezoidal-result : " << TRPZ_RES0 << "\n";
   std::cout << "Simpson-result : " <<     SIMPS_RES0 << "\n";
   std::cout << "Gauss-Legeandre-result : "<< GL_RES0 << "\n";

   // Fill the error vector:
   errors0_[1][0] = abs(MID_RES0-EXACT_RES0);
   errors0_[1][1] = abs(TRPZ_RES0-EXACT_RES0);
   errors0_[1][2] = abs(SIMPS_RES0-EXACT_RES0);
   errors0_[1][3] = abs(GL_RES0-EXACT_RES0);
   std::cout << "***************************************\n";

   N0=8;
   MID_RES0 = nIntegrationMID(ToIntegrate0,xSTART,xEND,N0);
   TRPZ_RES0 = nIntegrationTRAPZ(ToIntegrate0,xSTART,xEND,N0);
   SIMPS_RES0 = nIntegrationSIMPS(ToIntegrate0,xSTART,xEND,N0);
   GL_RES0 = nIntegrationGL(ToIntegrate0,xSTART,xEND,N0);
   
   std::cout << "********** TEST WITH N="<<N0<<"**************\n";
   std::cout << "EXACT-RESULT of the integration: "<<EXACT_RES0 <<"\n";
   std::cout << "Mid-point-result : "   <<   MID_RES0 << "\n";
   std::cout << "Trapezoidal-result : " << TRPZ_RES0 << "\n";
   std::cout << "Simpson-result : " <<     SIMPS_RES0 << "\n";
   std::cout << "Gauss-Legeandre-result : "<< GL_RES0 << "\n";

   std::cout << "ERROR FOR N=8 : f(x)=x" <<std::endl;
   std::cout << "trapz: " << TRPZ_RES0-EXACT_RES0<<std::endl;
   std::cout << "midpoint: " << MID_RES0-EXACT_RES0<<std::endl;
   std::cout << "simpson: " << SIMPS_RES0-EXACT_RES0<<std::endl;
   std::cout << "GaussLegeandre: " << GL_RES0-EXACT_RES0<<std::endl;
   std::cout << "******************************************\n";
   std::cout << "******************************************\n";
   std::cout << "*******END TEST FOR f(x) = x *********\n\n\n\n";
   
   // Example : Integration of f(x) = sin(x):
   auto ToIntegrate = [](double x)
   {
     return sin(x);
   };
  
   xSTART = 0.0;
   xEND   = M_PI;
   unsigned int N;
   std::vector<double> degrees;
   std::vector<std::vector<double>> errors_(4,std::vector<double>(4));
   std::vector<double> currErrors(4);
   
   double EXACT_RES = 2.0;
   std::cout <<"********************************************\n";
   std::cout<< "  TESTING FOR f(x) = sin(x)                 \n";
   std::cout<< "********************************************\n";

   N=2;
   degrees.push_back(double(N));
   double MID_RES = nIntegrationMID(ToIntegrate,xSTART,xEND,N);
   double TRPZ_RES = nIntegrationTRAPZ(ToIntegrate,xSTART,xEND,N);
   double SIMPS_RES = nIntegrationSIMPS(ToIntegrate,xSTART,xEND,N);
   double GL_RES = nIntegrationGL(ToIntegrate,xSTART,xEND,N);
   std::cout << "********** TEST WITH N="<<N<<"**************\n";
   std::cout << "EXACT-RESULT of the integration: "<<EXACT_RES <<"\n";
   std::cout << "Mid-point-result : "   <<   MID_RES << "\n";
   std::cout << "Trapezoidal-result : " << TRPZ_RES << "\n";
   std::cout << "Simpson-result : " <<     SIMPS_RES << "\n";
   std::cout << "Gauss-Legeandre-result : "<< GL_RES << "\n";

   errors_[0][0] = abs(MID_RES-EXACT_RES);
   errors_[0][1]= abs(TRPZ_RES-EXACT_RES);
   errors_[0][2] = abs(SIMPS_RES-EXACT_RES);
   errors_[0][3] = abs(GL_RES-EXACT_RES);
   std::cout << "***************************************\n";
   
   N=4;
   degrees.push_back(double(N));
   MID_RES = nIntegrationMID(ToIntegrate,xSTART,xEND,N);
   TRPZ_RES = nIntegrationTRAPZ(ToIntegrate,xSTART,xEND,N);
   SIMPS_RES = nIntegrationSIMPS(ToIntegrate,xSTART,xEND,N);
   GL_RES = nIntegrationGL(ToIntegrate,xSTART,xEND,N); 
   std::cout << "********** TEST WITH N="<<N<<"**************\n";
   std::cout << "EXACT-RESULT of the integration: "<<EXACT_RES <<"\n";
   std::cout << "Mid-point-result : "   <<   MID_RES << "\n";
   std::cout << "Trapezoidal-result : " << TRPZ_RES << "\n";
   std::cout << "Simpson-result : " <<     SIMPS_RES << "\n";
   std::cout << "Gauss-Legeandre-result : "<< GL_RES << "\n";

   // Fill the error vector:
   errors_[1][0] = abs(MID_RES-EXACT_RES);
   errors_[1][1] = abs(TRPZ_RES-EXACT_RES);
   errors_[1][2] = abs(SIMPS_RES-EXACT_RES);
   errors_[1][3] = abs(GL_RES-EXACT_RES);
   std::cout << "***************************************\n";
   
   N=5;
   degrees.push_back(double(N));
 
   MID_RES = nIntegrationMID(ToIntegrate,xSTART,xEND,N);
   TRPZ_RES = nIntegrationTRAPZ(ToIntegrate,xSTART,xEND,N);
   SIMPS_RES = nIntegrationSIMPS(ToIntegrate,xSTART,xEND,N);
   GL_RES = nIntegrationGL(ToIntegrate,xSTART,xEND,N);
  
  
   std::cout << "********** TEST WITH N="<<N<<"**************\n";
   std::cout << "EXACT-RESULT of the integration: "<<EXACT_RES <<"\n";
   std::cout << "Mid-point-result : "   <<   MID_RES << "\n";
   std::cout << "Trapezoidal-result : " << TRPZ_RES << "\n";
   std::cout << "Simpson-result : " <<     SIMPS_RES << "\n";
   std::cout << "Gauss-Legeandre-result : "<< GL_RES << "\n";
   
   // Fill the error vector:
   errors_[2][0] = abs(MID_RES-EXACT_RES);
   errors_[2][1] = abs(TRPZ_RES-EXACT_RES);
   errors_[2][2] = abs(SIMPS_RES-EXACT_RES);
   errors_[2][3] = abs(GL_RES-EXACT_RES);
   std::cout << "***************************************\n";
   N=8;
   degrees.push_back(double(N));
 
   MID_RES = nIntegrationMID(ToIntegrate,xSTART,xEND,N);
   TRPZ_RES = nIntegrationTRAPZ(ToIntegrate,xSTART,xEND,N);
   SIMPS_RES = nIntegrationSIMPS(ToIntegrate,xSTART,xEND,N);
   GL_RES = nIntegrationGL(ToIntegrate,xSTART,xEND,N);
  
  
   std::cout << "********** TEST WITH N="<<N<<"**************\n";
   std::cout << "EXACT-RESULT of the integration: "<<EXACT_RES <<"\n";
   std::cout << "Mid-point-result : "   <<   MID_RES << "\n";
   std::cout << "Trapezoidal-result : " << TRPZ_RES << "\n";
   std::cout << "Simpson-result : " <<     SIMPS_RES << "\n";
   std::cout << "Gauss-Legeandre-result : "<< GL_RES << "\n";
   
   // Fill the error vector:
   errors_[3][0] = abs(MID_RES-EXACT_RES);
   errors_[3][1] = abs(TRPZ_RES-EXACT_RES);
   errors_[3][2] = abs(SIMPS_RES-EXACT_RES);
   errors_[3][3] = abs(GL_RES-EXACT_RES);
   std::cout << "***************************************\n";
   
   std::vector<double> mid_error = {errors_[0][0],errors_[1][0],errors_[2][0],errors_[3][0]};
   std::vector<double> trz_error = {errors_[0][1],errors_[1][1],errors_[2][1],errors_[3][1]};
   std::vector<double> simps_error = {errors_[0][2],errors_[1][2],errors_[2][2],errors_[3][2]};
   std::vector<double> gl_error = {errors_[0][3],errors_[1][3],errors_[2][3],errors_[3][3]};


   using namespace matplot;
   
   hold(on);
   
   semilogy(degrees,mid_error)->line_width(2);
   semilogy(degrees,trz_error)->line_width(2);
   semilogy(degrees,gl_error,"--")->line_width(2);
   semilogy(degrees,simps_error,"-")->line_width(2);
   xlabel("N");
   ylabel("absolute-error");
   title("Error analysis");
   ::matplot::legend({"midpoint", "trapz","gauss-legeandre","simpson"});
   
   show();


   
  return 0;

  
 
}
