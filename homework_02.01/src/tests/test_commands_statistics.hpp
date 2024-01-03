#include "DATA_FRAME.hpp"
#include "gtest/gtest.h"
#include <gmock/gmock.h>

using namespace CSV_READER;

/*
  File used for testing the statistics
  module
*/

// Object used by the various tests:
static std::string config_file("configCSV.txt");
static std::string filename("wheater_data.csv");
static DATA_FRAME df(config_file);



/*
  Test how many elements are contained
  in a specified column.
  
*/


using VectorDouble = std::vector<double>;

TEST(,)
{
  	     
  
  
}


/*
  Test the mean, and the standard deviation for all the columns
  (The exact results are obtained by reading the file with pandas
   in python)
 */
TEST(Results,Mean)
{
  
  for(auto header : )
  
   
}

TEST(Results,stdDev)
{
  
}

/*
  Test 

