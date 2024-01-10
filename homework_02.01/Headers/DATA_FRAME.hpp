#ifndef DATA_FRAME_H
#define DATA_FRAME_H


#include <stdio.h>
#include <iostream>
#include <functional>
#include <numeric>
#include <cassert>
#include <string>
#include <fstream>
#include <sstream>
#include <variant>
#include <optional>
#include <vector>
#include <map>
#include <cmath>
#include <memory>
#include "CSV_WRITER.hpp"

#include <boost/optional.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/histogram.hpp>
#include <boost/format.hpp>

namespace CSV_READER{

  using OpVariant = std::optional<std::variant<double,std::string,int>>;
  using VecOpvar = std::vector<OpVariant>;
  
class DATA_FRAME
{
 public:

  // Base-constructor:
  DATA_FRAME();

  //Copy-constructor:
  DATA_FRAME(const DATA_FRAME& df):
    row_structure(df.row_structure),
    dataframe(df.dataframe),
    header_(df.header_),
    configFile(df.configFile),
    pWriter_(nullptr)
  {};

  //Move-constructor:
  DATA_FRAME(DATA_FRAME&& df):
    row_structure(std::move(df.row_structure)),
    dataframe(std::move(df.dataframe)),
    header_(std::move(df.header_)),
    configFile(df.configFile),
    pWriter_(std::move(df.pWriter_)),
    outputfile_(df.outputfile_),
    Iswriting(df.Iswriting)
  {
    std::cout << "Warning-moving the resources to another data-frame\n";
  };
    
  
  //Read the data-structure from config-file where the structure
  //of the row is stored:
  DATA_FRAME(std::string CONFIG_FILE);
    
  // Construct from the data-structure given by the user:
  DATA_FRAME(std::vector<std::string> rowstructure):
    row_structure{rowstructure},_rows_{0} {};

  void set_config_file(std::string CONFIG_FILE);
  
  // Functions needed for missing values:
  OpVariant opDouble(std::string s)
  {
  return !s.empty() ? OpVariant(double(std::stod(s))) : std::nullopt;
  }

  OpVariant opString(std::string s)
  {
  return !s.empty() ? OpVariant(std::string(s)) : std::nullopt;
  }

  OpVariant opInt(std::string s)
  {
  return !s.empty() ? OpVariant(int(std::stoi(s))) : std::nullopt;
  }

  //Read from input-file
  void read(std::string file,bool HasHeader);


  // COSTANT-ROW-ITERATOR:
  class cRowIterator
  {
  public:

    using type = std::optional<std::variant<double,std::string,int>>;
    using rowtype = std::vector<type>;
    using ref_ = const std::vector<type>&;
    using pRowIterator = std::vector<rowtype>::const_iterator;

    cRowIterator(std::vector<rowtype>::const_iterator it):curIter(it){};

    // Iterator:
    typename cRowIterator::pRowIterator operator->(){return curIter;};

    // Reference:
    typename cRowIterator::ref_ operator*(){return *(curIter);};
    // Postfix
    
    void operator++(int){curIter++;}

    cRowIterator operator+(int n){curIter=curIter+n;return *this;}

    cRowIterator operator-(int n){curIter=curIter-n;return *this;}
    
    friend bool operator== (const cRowIterator& a, const cRowIterator& b) { return a.curIter == b.curIter; };
    friend bool operator!= (const cRowIterator& a, const cRowIterator& b) { return a.curIter != b.curIter; };  
  private:
  
    std::vector<rowtype>::const_iterator curIter;
  };
  
  cRowIterator crowIterbegin() const {return cRowIterator(dataframe.begin());};

  cRowIterator crowIterEnd() const {return cRowIterator(dataframe.end());}; //end row-iterator
  
  //*********************************************************************//

  //Iterator for ROWS (non-const)
  class RowIterator
  {
   public:

    using type = std::optional<std::variant<double,std::string,int>>;
    using rowtype = std::vector<type>;
    using ref = std::vector<type>&;
    using pRowIterator = std::vector<rowtype>::iterator;

    RowIterator(std::vector<rowtype>::iterator it):curIter(it){};

    // Iterator:
  typename RowIterator::pRowIterator operator->(){return curIter;};

    // Reference:
  typename RowIterator::ref operator*(){return *(curIter);};
    // Postfix
    
    void operator++(int){curIter++;}

	//void operator+(int n){curIter=curIter+n;}

	RowIterator operator+(int n){curIter=curIter+n;return *this;}

	//void operator-(int n){curIter=curIter-n;}

	RowIterator operator-(int n){curIter=curIter-n;return *this;}
    
    friend bool operator== (const RowIterator& a, const RowIterator& b) { return a.curIter == b.curIter; };
    friend bool operator!= (const RowIterator& a, const RowIterator& b) { return a.curIter != b.curIter; };  
private:
  
    std::vector<rowtype>::iterator curIter;
  };
  
  RowIterator rowIterbegin(){return RowIterator(dataframe.begin());};

  RowIterator rowIterEnd(){return RowIterator(dataframe.end());}; //end row-iterator
  //--------------------------------------------------// 

  //ITERATOR for COLUMNS:
  class colIterator
  {
  public:
    using type = std::optional<std::variant<double,std::string,int>>;
    using ref = type&;
    using colVector = std::vector<type>;
    using colIter = colVector::iterator;
    
    // Assert the column!
    colIterator(RowIterator _rowIter_,size_t col):_colVector_{_rowIter_.operator*()},col_{col}{};

    typename colIterator::colIter operator->(){return _colVector_.begin()+col_;};

    typename colIterator::ref operator*(){return _colVector_[col_];};

    //post-fix
    void operator++(int){col_++;};

    //prefix
    void operator++(){++col_;};

    // TO CHECK:
    friend bool operator== (const colIterator& a,const colIterator& b) { return a.col_==b.col_;};
    friend bool operator!= (const colIterator& a,const colIterator& b) { return a.col_!=b.col_;};
    
    private:

   colVector& _colVector_;
   size_t col_;
  };

  colIterator colIterbegin(RowIterator _rowIter_,size_t col){return colIterator(_rowIter_,col);};

  colIterator colIterEnd(RowIterator _rowIter_,size_t col){return colIterator(_rowIter_,col);};

  class ccolIterator
  {
  public:
    using type = std::optional<std::variant<double,std::string,int>>;
    using ref_ = type;
    using colVector = std::vector<type>;
    using colIter = colVector::const_iterator;
    
    // Assert the column!
    ccolIterator(cRowIterator _rowIter_,size_t col):_colVector_{_rowIter_.operator*()},col_{col}{};

    typename ccolIterator::colIter operator->(){return _colVector_.begin()+col_;};

    typename ccolIterator::ref_ operator*(){return _colVector_[col_];};

    //post-fix
    void operator++(int){col_++;};

    //prefix
    void operator++(){++col_;};

    // TO CHECK:
    friend bool operator== (const ccolIterator& a,const ccolIterator& b) { return a.col_==b.col_; };
    friend bool operator!= (const ccolIterator& a,const ccolIterator& b) { return a.col_!=b.col_; };
    
  private:

    const colVector& _colVector_;
    size_t col_;
  };

  ccolIterator ccolIterbegin(cRowIterator _rowIter_,size_t col){return ccolIterator(_rowIter_,col);};

  ccolIterator ccolIterEnd(cRowIterator _rowIter_,size_t col){return ccolIterator(_rowIter_,col);};


  //Return the map needed for accessing the variant object:
  std::map<std::string, int> map() const;

  //Return the row-structure:
  std::vector<std::string> rowstructure() const;
  
  //mean of a column:
  double mean(size_t col) const;

  // By header name:
  double mean(std::string colName) const;

  //standard deviation of a column
  double stdDev(size_t col) const;

  //By header name:
  double stdDev(std::string colName) const;
  

  // variance of a column
  double var(size_t col) const;

  // By header name:
  double var(std::string colName) const;
  
  // Check if the column is numerical or categorical:
  bool IsNumeric(size_t col) const;
  bool IsCategorical(size_t col) const;
  
  // Check if the column and the row is valid:
  bool IsColumn(size_t col) const;
  bool IsRow(size_t row) const;

 
  // count how many times is present a word:
  size_t countWord(size_t col,std::string word) const;

  // Get the corresponding column for manipulation: (value)
  template<class colTYPE>
  std::vector<colTYPE> getCol(size_t col) const;

  template<class colTYPE>
  std::vector<colTYPE> getCol(std::string col) const;
  
  
  // Linear Regression: y = w*x+b
  // colX : x-column
  // colY : y-column
  template<class colTYPEX,class colTYPEY>
  std::tuple<double,double> LinearRegression(size_t colX,size_t colY) const;

  template<class T>
  void makeHistogram(size_t col,std::string title,unsigned int n_interval,bool stdOutput=true) const;


  // Accessing operator (writing)
  std::vector<CSV_READER::VecOpvar>& set_data();

  // Accessing operator (reading)
  std::vector<CSV_READER::VecOpvar> get_data();

  // Indexing operator (writing)
  CSV_READER::OpVariant& operator() (size_t row,size_t col);

  // Header map:
  std::map<std::string,unsigned int> HeaderNames() const;

  //Set the Header map:
  void set_HeaderNames(const std::map<std::string,unsigned int>& headernames);

  //Set the Row structure:
  void set_row_structure(const std::vector<std::string>& rowstructure);

  //*****OUTPUT FILE MANAGER***********//
  void setOutputfile(std::string _outfile_);

  
  void write(std::string separator=" ");

  void closeOutput();

  template<class T>
  void WriteEntry(std::string word,const T& val) const;

  // Destructor:
  ~DATA_FRAME()
  {
    this->closeOutput();
  };
  //**********************************//
 private:

  std::vector<std::string> row_structure;
  std::vector<CSV_READER::VecOpvar> dataframe;
  std::map<std::string,unsigned int> header_;
  bool configFile = false;

  // Create an std::map which maps the values to indexes:
  std::map<std::string, int> map_{{"double", 0}, {"string", 1}, {"int", 2}};
  size_t _rows_;

  // Pointer to the CSV_WRITER:
  mutable std::unique_ptr<CSV_WRITER> pWriter_;
  std::string outputfile_;
  mutable bool Iswriting; 
};

}

#endif
