#include <stdio.h>
#include <iostream>
#include <functional>
#include <cassert>
#include <string>
#include <fstream>
#include <sstream>
#include <variant>
#include <map>

class DATA_FRAME
{
 public:
  DATA_FRAME(std::vector<std::string> rowstructure):
    row_structure{rowstructure} {};

  void read(std::string file);

  double mean(unsigned int col);

  //double stdDev(unsigned int col);

  bool IsNumeric(unsigned int col) const;
  
  
  
 private:
  //std::vector<std::string> row_structure = {"int","double","string","int","double"};
  std::vector<std::string> row_structure;
  std::vector<std::vector<std::variant<double,std::string,int> > > dataframe;

  // Create an std::map which maps the values to indexes:
  std::map<std::string, int> map_{{"double", 0}, {"string", 1}, {"int", 2}};
  
};

void DATA_FRAME::read(std::string FILEIN)
{
  std::ifstream file_(FILEIN);
  std::string line;

  std::vector<std::variant<double,std::string,int> > currentRow(row_structure.size());
  // PERFORM THE CHECKS!

  while(std::getline(file_,line))
  {
    std::istringstream iss(line);
    std::string _word_;
    int counter = 0;
    while(iss >> _word_)
    {
      // check the correctness.
      int token_type = map_[row_structure[counter]];
      switch (token_type)
      {
        case 0:
	  currentRow[counter] = double(std::stod(_word_));
	break;
	case 1:
	  currentRow[counter] = std::string(_word_);
	break;
	case 2:
	  currentRow[counter] = int(std::stoi(_word_));
	break;
      }// end switch
     counter++;
    }// end row-loop
    dataframe.push_back(currentRow);
  }
  file_.close();
}

bool DATA_FRAME::IsNumeric(unsigned int col) const
{
  // check if col< dim(dataframe)
  return (row_structure[col] == "double" || row_structure[col] == "int");
}

double DATA_FRAME::mean(unsigned int col) const
{
  if (IsNumeric(col))
  {
    // Perform a loop trough the vector
    double _mean_ = 0.0;
    for (auto rowIT = dataframe.begin();rowIT != dataframe.end();rowIT++)
    {
      int token_type = map_[row_structure[col]];
      switch (token_type)
      case 0:
	
      break;
    }
  }
}



int main()
{
  // every row

  //specified by the user: create a map that maps the values given by the user to the integers:
  std::vector<std::string> row_structure = {"int","double","string","int","double"};

  // The user has to pass the data-structure:
  DATA_FRAME df(row_structure);
  df.read("input.txt");

  //bool is_numeric = df.IsNumeric(2);
  std::cout << is_numeric<<std::endl;












  
  /*
  std::map<std::string,int> map_;
  map_["double"] = 0;
  map_["string"] = 1;
  map_["int"] = 2;
  std::vector<std::vector<std::variant<double,std::string,int> > > DATA_FRAME;
  std::vector<std::variant<double,std::string,int> > currentRow(row_structure.size());
  */

  
  // Create an enumeration in the class

  
  //read file
  //read row
  //iterate trough the entries
  /*
  std::ifstream file("input.txt");
  std::string line;

  while(std::getline(file,line))
  {
    std::istringstream iss(line);
    std::string _word_;
    int counter = 0;
    while(iss >> _word_)
    {
      // check the correctness.
      int token_type = map_[row_structure[counter]];
      
      switch (token_type)
      {
        case 0:
	  currentRow[counter] = double(std::stod(_word_));
	break;
	 
	case 1:
	  currentRow[counter] = std::string(_word_);
	break;
	case 2:
	  currentRow[counter] = int(std::stoi(_word_));
	break;
      }// end switch
     counter++;
    }// end row-loop
    DATA_FRAME.push_back(currentRow);
  }
  file.close();
  */
  /*
  int counter = 0;
  for(auto it = currentRow.begin();it<currentRow.end();it++)
  {
    std::visit([](auto& x){std::cout << x;}, *it);
    std::cout << " ";
    //counter++;
   
  }
  */
  return 0;
 
}
