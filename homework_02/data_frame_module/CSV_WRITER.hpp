#ifndef _CSVWRITER_H
#define _CSVWRITER_H

#include <fstream>
#include <vector>

class CSV_WRITER
{
public:
  
  CSV_WRITER(std::string _fileout,const std::string separator = " "):
    outfile_(_fileout),separator_{separator}
  {
  };

  // write into the file
  void write()
  {
    outstream_.exceptions( std::ofstream::failbit | std::ofstream::badbit);
    try {
      //write in append mode:
      outstream_.open(outfile_, std::ofstream::app | std::ofstream::out);
      isActive_=true;
    }
    catch (const std::ofstream::failure& e) {
      std::cerr << "Exception opening/reading/closing file\n";
    }
  }

  // Close the file:
  void close()
  {
    if(outstream_.is_open()){
      std::cout << "Closing the file: " << outfile_ << std::endl;
      outstream_.close();}
    isActive_=false;
  }
  //Check if the ofstream is writing:
  bool isActive()
  {
    return isActive_;
  }
    // Operator: callable
    CSV_WRITER& operator << ( CSV_WRITER& (* val)(CSV_WRITER&))
    {
    if(!isActive())
    throw("Error the output stream is not active\n");
    
    return val(*this);
    }
  
  
  CSV_WRITER& operator << (const char* val)
  {
    if(!isActive())
      throw std::runtime_error("Error the output stream is not active\n");
   
    outstream_  << val  << separator_;
    return *this;
  }

  CSV_WRITER& operator << (const std::string & val)
  {
    if(!isActive())
      throw std::runtime_error("Error the output stream is not active\n");
    
    outstream_  << val << separator_;
    return *this;
  }

  template<class T>
  CSV_WRITER& operator << (const std::vector<T>& val)
  {
    if(!isActive())
      throw std::runtime_error("Error the output stream is not active\n");
    
    for(auto it=val.begin();it!=val.end();it++){
      outstream_ << (*it) << separator_;}
    return *this;
  }

  template<class T>
  CSV_WRITER& operator << (const T& val)
  {
    if(!isActive())
      throw std::runtime_error("Error the output stream is not active\n");

    outstream_ << val << separator_;
    return *this;
  }

  // END ROW:
  void endrow()
  {
    if(!isActive())
      throw std::runtime_error("Error the output stream is not active\n");
    outstream_ << std::endl;
   
  }


  ~CSV_WRITER()
  {
    if(outstream_.is_open())
      {
	std::cout << "Closing the file: " << outfile_ << std::endl;
	outstream_.close();
      }
  }
  
private:
  std::ofstream outstream_;
  std::string outfile_;
  std::string separator_=" ";
  bool isActive_=false;
  
};



#endif
