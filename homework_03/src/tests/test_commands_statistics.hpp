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
  double max_abs_error = 1e-3; //tolerance chosen for the test
  for(size_t i=0;i<meanCols.size();i++)
    EXPECT_THAT(meanCols[i],testing::DoubleNear(trueMeans[i], max_abs_error));

  // Does not work the following for the strict tolerance:
  //EXPECT_THAT(meanCols,testing::ElementsAreArray(trueMeans));
   std::cout << "#################################\n\n";
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

   std::cout << "#################################\n\n";
   
}

/*
// Test the functions for missing values: #opFunctions
TEST(Statistics_module_BEHAVIOUR,ConversionFunctions)
{
  std::cout << "---####TESTING THE Conversion functions Op<> #####---\n";
  CSV_READER::OpVariant Value;

  std::string StringValue = "Word";
  std::string IntValue = "10";
  std::string DoubleValue = "13.5";

  // Base-constructor:
  CSV_READER::DATA_FRAME df();
  

  std::cout << "#################################\n";
}
*/


// Test the type of the columns readed IsNumeric or IsCategorical:
TEST(Statistics_module_BEHAVIOUR,IsAtype)
{

  std::cout << "---####TESTING THE Conversion-functions Is<> #####---\n";
  // First dataframe:
  std::string config_file("configCSV.txt");
  std::string filename("London_weather.csv");
  DATA_FRAME df(config_file);
  df.read(filename,true);
  
  //date:
  EXPECT_FALSE(df.IsNumeric(1));
  EXPECT_TRUE(df.IsCategorical(1));
    
  for(size_t col=1;col<10;++col)
    {
      EXPECT_TRUE(df.IsNumeric(col+1));
      EXPECT_FALSE(df.IsCategorical(col+1));
    }
  std::cout << "#################################\n\n";
}

// Test if after the move constructor the dataframe performs in the same manner as before:
TEST(Statistics_module_BEHAVIOUR,Move)
{
  std::cout << "---####TESTING THE MOVE-CONSTRUCTOR #####---\n";
  std::string config_file("configCSV.txt");
  std::string filename("London_weather.csv");
  // First dataframe:
  DATA_FRAME df(config_file);
  df.read(filename,true);

  //Get the internal data-structure of the original dataframe (ref)
  std::vector<CSV_READER::VecOpvar>& data_org_ref = df.set_data();
  // Get content:
  std::vector<CSV_READER::VecOpvar> data_org = df.get_data();
  std::vector<std::string> row_struct_org = df.rowstructure();
  std::map<std::string,unsigned int> header_names_org = df.HeaderNames();

  df.setOutputfile("outputMoveText.txt");
  df.write(" ");
  df.mean(6);
   
  // Move constructor-invoked:
  DATA_FRAME df_copy(std::move(df)); //Move constructor.
  std::vector<CSV_READER::VecOpvar> data_ = df_copy.set_data();
  std::vector<std::string> row_struct_ = df_copy.rowstructure();
  std::map<std::string,unsigned int> header_names_ = df_copy.HeaderNames();
  
  //Content:
  EXPECT_THAT(data_org_ref.size(),testing::Eq(0)); //Must be zero because we have moved the ownership
  EXPECT_THAT(data_org,testing::ContainerEq(data_)); //Must be equal
  EXPECT_THAT(row_struct_org,testing::ContainerEq(row_struct_));
  EXPECT_THAT(header_names_org,testing::ContainerEq(header_names_));

  //Testing if the output works properly:
  //we must be able to write to outputMoveText.txt and
  //see the same result in the two rows of the file:
  df_copy.mean(6);

  // Check if "outputMoveText.txt" in this directory have the same two rows!
  
  std::cout << "#################################\n\n";
  
  
}

// Test the copy constructor:
TEST(Statistics_module_BEHAVIOUR,Copy)
{
  std::cout << "---####TESTING THE COPY-CONSTRUCTOR #####---\n";
  std::string config_file("configCSV.txt");
  std::string filename("London_weather.csv");
  // First dataframe:
  DATA_FRAME df(config_file);
  df.read(filename,true);

  //Copy constructor:
  DATA_FRAME df_copy(df);
 
  //Org
  std::vector<CSV_READER::VecOpvar> data_org = df.get_data();
  std::vector<std::string> row_struct_org = df.rowstructure();
  std::map<std::string,unsigned int> header_names_org = df.HeaderNames();

  //Copy
  std::vector<CSV_READER::VecOpvar> data_ = df_copy.set_data();
  std::vector<std::string> row_struct_ = df_copy.rowstructure();
  std::map<std::string,unsigned int> header_names_ = df_copy.HeaderNames();
  
  //Content comparison:
  EXPECT_THAT(data_org,testing::ContainerEq(data_)); //Must be equal
  EXPECT_THAT(row_struct_org,testing::ContainerEq(row_struct_));
  EXPECT_THAT(header_names_org,testing::ContainerEq(header_names_));
  
  std::cout << "####################################\n\n";
}

/*
 Testing an alternative manner to construct an object:
 Set the row-structure by hand
*/

TEST(Statistics_module_BEHAVIOUR,BaseConstructor)
{
  std::cout << "---####TESTING THE STATISTICS MODULE BASE CONSTRUCTOR #####---\n";


  std::string config_file("configCSV.txt");
  std::string filename("London_weather.csv");
  std::vector<std::string> row_struct = {"string","double","double","double","double","double",
					 "double","double","double","double"};

  DATA_FRAME df_base;
  df_base.set_config_file(config_file);
  df_base.read(filename,true);
  
  // Previous constructor:
  DATA_FRAME df(config_file);
  df.read(filename,true);

  EXPECT_THAT(df.get_data(),testing::ContainerEq(df_base.get_data()));
  EXPECT_THAT(df.rowstructure(),testing::ContainerEq(df_base.rowstructure()));
  EXPECT_THAT(df.HeaderNames(),testing::ContainerEq(df_base.HeaderNames()));
  std::cout << "---########################################\n\n";
}


//Test the frequencies of a categorical variable:
TEST(Statisics_module_functs,CategoricalTest)
{
  std::cout << "---####TESTING THE FREQUENCY COUNT #####---\n";
  std::string config_file("configCSV.txt");
  std::string filename("London_weather.csv");
  DATA_FRAME df(config_file);
  df.read(filename,true);

  //For example:
  std::string Year = "19790104";

  unsigned int n_date = df.countWord(1,Year);

  EXPECT_EQ(n_date,1);
  
  std::cout << "###########################################\n\n";
}


// Test if the date in the first column is valid: "London_weather.csv"
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
  std::cout << "#################################\n\n";
}

// Test: reading a different config file: (config2.CSV)
// In this case the date are integers and not strings:
TEST(Statistics_module_BEHAVIOUR,configFile)
{
  std::cout << "---####TESTING a different config-file #####---\n";
  std::string config_file("configCSV2.txt");
  std::string filename("London_weather.csv");
  DATA_FRAME df(config_file);
  df.read(filename,true);

  //Convert to string the vector of date and compare the first dates:
  std::vector<int> dateInt = df.getCol<int>("date");
  std::vector<std::string> dateString(dateInt.size());
  //Convert:
  std::transform(dateInt.begin(), dateInt.end(), dateString.begin(), [](const int& val)
  {
    return std::to_string(val);
  });
  
  std::vector<std::string> tenDates={"19790101","19790102","19790103","19790104","19790105",
				     "19790106","19790107","19790108","19790109","19790110"}; //to-do!

  EXPECT_TRUE(std::equal(dateString.begin(),dateString.begin()+10,tenDates.begin()));
  
  std::cout << "---#######################---\n\n";

  
 
}
