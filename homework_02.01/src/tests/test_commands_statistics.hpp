#include "DATA_FRAME.hpp"
#include "gtest/gtest.h"
#include <gmock/gmock.h>
#include <string>

using namespace CSV_READER;

/*
  File used for testing the statistics
  module
*/

using VectorDouble = std::vector<double>;


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
   std::cout << "#################################\n";
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

   std::cout << "#################################\n";
   
}

// Test if the date in the first column is valid "London_weather.csv"

TEST(Statistics_module_TYPE_CHECKING,ColsType)
{
  std::cout << "---####TESTING THE DATES #####---\n";
  std::string config_file("configCSV.txt");
  std::string filename("London_weather.csv");
  DATA_FRAME df(config_file);
  df.read(filename,true);
  

  std::vector<std::string> dates = df.getCol<std::string>("date");

  // Check if the year, the month and the day is in the right range:
  
  for(const auto& date : dates)
    {
      std::string year = date.substr(0,4);
      std::string month = date.substr(4,2);
      std::string day = date.substr(6,2);

      int year_ = std::stoi(year);
      int month_ = std::stoi(month);
      int day_ = std::stoi(day);

      using namespace ::testing;
      
      EXPECT_THAT(year_, AllOf(Ge(1979),Le(2020)));
      EXPECT_THAT(month_, AllOf(Ge(1),Le(12)));
      EXPECT_THAT(day_, AllOf(Ge(1),Le(31))); 
    }
  std::cout << "#################################\n";
}

