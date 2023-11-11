#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>

int main()
{
  std::ifstream file;
  file.open("input.txt");

  std::map<std::string,int> countWords;
  
  std::string _line_;
  while(std::getline(file,_line_))
  {
    std::string single_token;
    std::stringstream ss(_line_);
    std::cout << "\n";
    while (ss >> single_token)
      {
	countWords[single_token]++;
      }
  }
  file.close();
  for (auto x : countWords)
    std::cout << x.first << " = " << x.second <<std::endl;
  
  return 0;
}
