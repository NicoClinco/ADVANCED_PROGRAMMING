#ifndef _DATASOURCE_
#define _DATASOURCE_

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

class DataSource
{
  public:
  DataSource(std::string name):
    _name_(name)
  {};

  virtual ~DataSource() {};
  
  void display_info()
  {
    std::cout<<"name-type :"<< _name_<< std::endl;
    for(auto _ : _data_)
      std::cout << _ << " ";
    std::cout <<"\n";
  }
  
  virtual void read_data() = 0;

  protected:
   std::string _name_;
   std::vector<float> _data_;
};


class FileDataSource:
  public DataSource
{
public:
  FileDataSource(std::string name,std::string fname):
    DataSource(name),_fname_(fname)
  {
    // Open the file:
    file.open(_fname_); // file is static.
  };

  ~FileDataSource()
  {
    if(file.is_open())
    {
      std::cout << "Closing file: " << _fname_ << std::endl;
      file.close();
    }
  }

  
  virtual void read_data() override
  {
    std::cout<<"Reading from file: "<< _fname_;
    _data_.clear();
    float val{0};
    
    while(file >> val)
      _data_.push_back(val);
  }
protected:
  std::string _fname_;
  std::ifstream file;
};

class ConsoleDataSource:
    public DataSource
{
public:
  ConsoleDataSource(std::string name):
     DataSource(name)
  {};

  virtual void read_data() override
  {
    std::cout << "Insert number's list\n"<<std::endl;
    _data_.clear();
    std::string line;
    std::getline(std::cin, line);
    
    std::istringstream iss(line);

    float val{0};

    while(iss >> val)
      _data_.push_back(val);
  } 
};

#endif
