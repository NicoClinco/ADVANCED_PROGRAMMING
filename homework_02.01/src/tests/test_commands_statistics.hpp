#include "DATA_FRAME.hpp"
#include "gtest/gtest.h"
#include <gmock/gmock.h>

using namespace CSV_READER;

/*
  File used for testing the statistics
  module
*/


/*
  Test how many elements are contained
  in a specified column.
  
*/

using VectorDouble = std::vector<double>;
/*
TEST(,)
{
  	     
  
  
}
*/

/*
  Test the mean, and the standard deviation for all the
   numeric columns (see wheater.csv)
  (The exact results are obtained by reading the file with pandas
   in python)
 */
TEST(Statistic_module_Results,Mean)
{
  std::cout << "---####TESTING THE MEAN FOR NUMERIC COLUMNS#####---\n";
  std::string config_file("configCSV.txt");
  std::string filename("London_weather.csv");
  DATA_FRAME df(config_file);
  df.read(filename,true);
  VectorDouble trueMeans = {5.26824,4.35024,118.757,
      15.388,11.4755,7.55987,
      1.66863,101536.605594,0.0344176};

    VectorDouble meanCols(trueMeans.size(),0.0);
  for(size_t col = 2;col<meanCols.size()+2;col++)
    {
      meanCols[col-2] = df.mean(col);
    }
  double max_abs_error = 1e-3;
  for(size_t i=0;i<meanCols.size();i++)
    EXPECT_THAT(meanCols[i],testing::DoubleNear(trueMeans[i], max_abs_error));

  // Does not work the following for the tolerance:
  //EXPECT_THAT(meanCols,testing::ElementsAreArray(trueMeans));
   
}

TEST(Statistic_module_Results,stdDev)
{
    std::cout << "---####TESTING THE STANDARD DEVIATION FOR NUMERIC COLUMNS#####---\n";
  std::string config_file("configCSV.txt");
  std::string filename("London_weather.csv");
  DATA_FRAME df(config_file);
  df.read(filename,true);
  VectorDouble trueStdDev = {2.07007,4.02834,88.8982,
      6.5547,5.7297,5.3267,
      3.7385,1049.7226,0.5194};

    VectorDouble stdDevCols(trueStdDev.size(),0.0);
  for(size_t col = 2;col<stdDevCols.size()+2;col++)
    {
      stdDevCols[col-2] = df.stdDev(col);
    }
  double max_abs_error = 1e-1; // higher tolerance with respect the mean
  for(size_t i=0;i<stdDevCols.size();i++)
  EXPECT_THAT(stdDevCols[i],testing::DoubleNear(trueStdDev[i], max_abs_error));

   
}

