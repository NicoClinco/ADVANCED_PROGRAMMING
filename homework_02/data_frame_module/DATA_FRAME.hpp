
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
#include <boost/program_options.hpp>
#include <boost/algorithm/string.hpp>

namespace CSV_READER{

  using OpVariant = std::optional<std::variant<double,std::string,int>>;
  using VecOpvar = std::vector<OpVariant>;
  
class DATA_FRAME
{
 public:

  //Read the data-structure from config-file where the structure
  //of the row is stored:
   DATA_FRAME(std::string CONFIG_FILE);
    
  // Construct from the data-structure given by the user:
  DATA_FRAME(std::vector<std::string> rowstructure):
    row_structure{rowstructure},_rows_{0} {};

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
  void read(std::string file);

  //Iterator for ROWS:
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
    friend bool operator== (const colIterator& a,const colIterator& b) { return a.col_==b.col_; };
    friend bool operator!= (const colIterator& a,const colIterator& b) { return a.col_!=b.col_; };
    
    private:

   colVector& _colVector_;
   size_t col_;
  };

  colIterator colIterbegin(RowIterator _rowIter_,size_t col){return colIterator(_rowIter_,col);};

  colIterator colIterEnd(RowIterator _rowIter_,size_t col){return colIterator(_rowIter_,col);};


  //Return the map needed for accessing the variant object:
  std::map<std::string, int> map() const;

  //Return the row-structure:
  std::vector<std::string> rowstructure() const;
  
  //mean of a column:
  double mean(size_t col);

  //standard deviation of a column
  double stdDev(size_t col);

  // variance of a column
  double var(size_t col);
  // Check if the column is numerical or categorical:
  bool IsNumeric(size_t col) const;
  bool IsCategorical(size_t col) const;
  
  // Check if the column and the row is valid:
  bool IsColumn(size_t col) const;
  bool IsRow(size_t row) const;

 
  // count how many times is present a word:
  size_t countWord(size_t col,std::string word);

  
  // Get the corresponding column for manipulation: (value)
  template<class colTYPE>
  std::vector<colTYPE> getCol(size_t col);


  // Linear Regression: colY
  template<class colTYPEX,class colTYPEY>
  std::tuple<double,double> LinearRegression(size_t colX,size_t colY);
  
 private:

  std::vector<std::string> row_structure;
  std::vector<CSV_READER::VecOpvar> dataframe;
  bool configFile = false;

  // Create an std::map which maps the values to indexes:
  std::map<std::string, int> map_{{"double", 0}, {"string", 1}, {"int", 2}};
  size_t _rows_;
};

}

#endif
