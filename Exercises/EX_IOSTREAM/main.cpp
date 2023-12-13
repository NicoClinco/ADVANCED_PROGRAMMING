// Tutorial: ho to read from files: 10/12


#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <boost/any.hpp>
#include <boost/algorithm/string.hpp>

// Read only integers but leave other types:
void get_int_from_file(std::string filename,std::vector<int>& v)
{
  std::ifstream f;
  f.open(filename);
  int n{0};
  
  if(f.good())
    {
      while(true){
	if(f>>n)
	  v.push_back(n);
	
	// I have not found an integer:
	if(f.fail())
	  {
	    f.clear();
	    std::string word;
	    while(f>>word)
	      {
		try{
		  std::stoi(word);
		  f.unget();
		    }
		//if a sort of execption is found, then, come in the following block:
		catch (...)
		  {
		    std::cout << "Warning-found a string \n"<<std::endl;	  
		  }
		break;
	      }
	  }
	//EOF:
	if(f.eof())
	  return;
      }    	
    }
}
namespace Parser
{
class Predicates
{
public:

  
  bool is_empty(const boost::any & operand)
  {
    return operand.empty();
  }

  bool is_int(const boost::any & operand)
  {
    return operand.type() == typeid(int);
  }

  bool is_char_ptr(const boost::any & operand)
  {
    try
      {
	boost::any_cast<const char *>(operand);
        return true;
      }
    catch(const boost::bad_any_cast &)
      {
        return false;
      }
  }

  bool is_string(const boost::any & operand)
  {
    return boost::any_cast<std::string>(&operand);
  }
};

  class CSVparser
  {
  public:
    // Construct from string:
    CSVparser(std::string filename):
      filename_{filename}
    {}
    //Read from file:
    void read()
    {
      // open the file
      f_.open(filename_);
      if(f_.good())
	{
	  data = std::vector<std::vector<boost::any>>(4);
	  // Read line by line:
	  std::string currentLine;
	  std::vector<std::string> lineSplitted;
	  while(std::getline(f_,currentLine))
	    {
	      //Elaborate Row:
	      boost::split(lineSplitted, currentLine, boost::is_any_of(","));
	      
	      unsigned int counter = 0; //used for what type of entry we are managing:
	      for(const auto& item : lineSplitted)
		{
		  if(!item.empty())
		    {
		      data[counter].push_back(item);
		    }
		  counter++; 
		}//end post-proc line
	      
	    }//getLine
	  
	}

    }
  private:
    std::string filename_;
    std::ifstream f_;
    std::vector<std::string> RowStructure = {"int","double","string"};
    std::map<std::string,unsigned int> rowStructureMap{{"int", 0}, {"double", 1}, {"string", 2}};
  public:
    std::vector<std::vector<boost::any> > data;
  };

}
  
int main(){

  Parser::CSVparser parser("csvfile.csv");
  parser.read();

  Parser::Predicates predict;
  
  //auto data = parser.data;


 
}
