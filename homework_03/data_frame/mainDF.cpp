#include "data_frame.hpp"
#include <stdio.h>
#include <iostream>

int main()
{

  CSV_READER::dataframe df("input.txt");

  df.Read(true);

  for(auto x : df.v)
    {
      for(auto y : x)
	{
	  std::cout << y << " ";
	}
      std::cout << "\n";
    }
  
  return 0;
}
