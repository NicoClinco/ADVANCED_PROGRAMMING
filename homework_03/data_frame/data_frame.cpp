#include "data_frame.hpp"

using namespace CSV_READER;

CSV_READER::dataframe::dataframe(const std::string& filename):
  filename_(filename)
{
}

void CSV_READER::dataframe::Read(bool HasHeader)
{
  std::ifstream filestream(filename_);
  std::string line;
    
  //check if it is possible to read:
  if(!filestream.good())
    throw("Error: the file does not exist\n");

  //Read the first line:
  std::vector<std::string> firstline_;
  std::getline(filestream,line);
  boost::split(firstline_,line,boost::is_any_of(","),boost::token_compress_on);
  dataframe::IterableType v_(firstline_.size(),std::vector<std::string>(0));
  v = v_; // Copy the data-structure, then we can append datas to v.
  
  if(!HasHeader)
    {
      // Register the row in the data-structure:
      unsigned int counter = 0 ;
      for(auto val : firstline_)
	{
	  v[counter].push_back(val);
	  counter++;
	}
    }
  else
    {
      headersName = firstline_;
    }

  while(std::getline(filestream,line))
    {
      std::stringstream ss(line);
      std::string _word_;
      unsigned int counter = 0;
      //Read line by line and create the data:
      // Allocate the number of columns:
      while(std::getline(ss,_word_,','))
	{
	  // Save everything, also the null values
	  // they will be treated better in python.
	  v[counter].push_back(_word_);
	  counter++;
	}
      //Check the lecture:
      assert(counter == firstline_.size());
    }

}
