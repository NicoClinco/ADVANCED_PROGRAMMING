#ifndef data_frame_hpp
#define data_frame_hpp

#include <cmath>
#include <boost/algorithm/string.hpp>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>

namespace CSV_READER{

/*
 Generic class that contains
 the entries all as strings.
 
 Then, thanks to the python bindings 
 we can manipulate this data structure in pandas.
 
*/
  
class dataframe
{
public:

  using IterableType = std::vector<std::vector<std::string>>;
  
  dataframe(const std::string& filename);

  void Read(bool HasHeader);


public:
  std::string filename_;
  dataframe::IterableType v;
  std::vector<std::string> headersName;
};

}

#endif
