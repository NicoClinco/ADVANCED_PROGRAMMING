
#ifndef DATA_FRAME_H
#define DATA_FRAME_H


#include <stdio.h>
#include <iostream>
#include <functional>
#include <cassert>
#include <string>
#include <fstream>
#include <sstream>
#include <variant>
#include <vector>
#include <map>


class DATA_FRAME
{
 public:
  // Read the row structure:
  DATA_FRAME(std::vector<std::string> rowstructure):
    row_structure{rowstructure},_rows_{0} {};

  void read(std::string file);
  
  class RowIterator
  {
   public:

    using type = std::variant<double,std::string,int>;
    using rowtype = std::vector<type>;
    using difference_type = std::ptrdiff_t;
    using iterator_category =std::forward_iterator_tag;
    using ref = std::vector<type>&;
    using pRowIterator = std::vector<rowtype>::iterator;

    RowIterator(std::vector<rowtype>::iterator it):curIter(it){};

    // Iterator:
  typename RowIterator::pRowIterator operator->(){return curIter;};

    // Reference:
  typename RowIterator::ref operator*(){return *(curIter);};
    // Postfix
    
    RowIterator& operator++(int){curIter++; return *this;}
    friend bool operator== (const RowIterator& a, const RowIterator& b) { return a.curIter == b.curIter; };
    friend bool operator!= (const RowIterator& a, const RowIterator& b) { return a.curIter != b.curIter; };  
private:
  
    std::vector<rowtype>::iterator curIter;
  };
  
  RowIterator rowIterbegin(){return RowIterator(dataframe.begin());};

  RowIterator rowIterEnd(){return RowIterator(dataframe.end());}; //end row-iterator
  //--------------------------------------------------// 
  /*
  class colIterator
  {
    TODO
  }
  */

  double mean(unsigned int col);

  double stdDev(unsigned int col);

  double var(unsigned int col);
  // Check if the column is numerical or categorical:
  bool IsNumeric(unsigned int col) const;
  bool IsCategorical(unsigned int col) const;
  
  // Check if the column and the row is valid:
  bool IsColumn(unsigned int col) const;
  bool IsRow(unsigned int row) const;

  // count how many times is present a word:
  unsigned int countWord(unsigned int col,std::string word);

  // Get the corresponding column for manipulation:
  /*
  template<class colTYPE>
  std::vector<colTYPE> getCol(unsigned int col,? std::string _coltype_) const; */
  
  // Get the column and the row to manipulate data:
  //std::vector<> Getcol(unsigned int col);

  //std::vector<std::variant<double,std::string,int> > Getrow(usigned int row);
  
 private:

  std::vector<std::string> row_structure;
  std::vector<std::vector<std::variant<double,std::string,int> > > dataframe;

  // Create an std::map which maps the values to indexes:
  std::map<std::string, int> map_{{"double", 0}, {"string", 1}, {"int", 2}};
  unsigned int _rows_;
};



#endif
