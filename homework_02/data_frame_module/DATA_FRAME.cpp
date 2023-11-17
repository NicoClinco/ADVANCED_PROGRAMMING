
// Implementation file:

#include "DATA_FRAME.hpp"


void DATA_FRAME::read(std::string FILEIN)
{
  std::ifstream file_(FILEIN);
  std::string line;

  // save the current row:
  std::vector<std::variant<double,std::string,int> > currentRow(row_structure.size());
  // PERFORM THE CHECKS!

  
  while(file_>>line)
  {

    std::stringstream ss(line);
    std::string _word_;
    int counter = 0;
   
    while(std::getline(ss,_word_,','))
    {
      // check the correctness.

	  // CHECK IF IT IS VALID:
	  
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
  if(!IsColumn(col))
	 throw std::invalid_argument("Invalid index of the column");
  
  return (row_structure[col-1] == "double" || row_structure[col-1] == "int");
}

bool DATA_FRAME::IsCategorical(unsigned int col) const
{
 if(!IsColumn(col))
   throw std::invalid_argument("Invalid index of the column");
  
  return (row_structure[col-1] == "string");
}


bool DATA_FRAME::IsColumn(unsigned int col) const
{
  return (col <= row_structure.size());
}

bool DATA_FRAME::IsRow(unsigned int row) const
{
   return (row <= _rows_);
}

double DATA_FRAME::mean(unsigned int col) 
{
  if(!IsNumeric(col))
     throw std::invalid_argument("Cannot do the mean of categorical values");

     
   // Perform a loop trough the vector and calculate the mean
   double _mean_ = 0.0;
   int token_type = map_[row_structure[col-1]]; 
   unsigned int nRowsvalid = 0;
   for (auto rowIt = this->rowIterbegin();rowIt!=this->rowIterEnd();rowIt++)
   {
    auto item =*(rowIt); // Get the row:
    switch (token_type)
    {
     case 0:
      _mean_+=std::get<double>(item[col-1]);
     break;
	case 2:
      _mean_+=std::get<int>(item[col-1]);
     break;
    }
    nRowsvalid++;
   } //end loop trough the rows.

  _mean_/=nRowsvalid;
  return _mean_;
}

double DATA_FRAME::stdDev(unsigned int col) 
{
  if(!IsNumeric(col))
    throw std::invalid_argument("Cannot do the std-dev for categorical values");

  //Obtain the mean:
  double mean = this->mean(col);
  
  double stddev = 0.0;
  // Perform a loop
   int token_type = map_[row_structure[col-1]]; 
   unsigned int nRowsvalid = 0;
   for (auto rowIt = this->rowIterbegin();rowIt!=this->rowIterEnd();rowIt++)
   {
    auto item = *(rowIt); // Get the row.
    switch (token_type)
    {
	case 0:
	  {
	  double item_ = std::get<double>(item[col-1]);
	  stddev+=(item_-mean)*(item_-mean);
	  break;
      }
	case 2:
	  {
	   int item_ = std::get<int>(item[col-1]);
	   stddev+=(item_-mean)*(item_-mean);
       break;
      }
	}
    nRowsvalid++;
   } //end loop trough the rows.
   stddev/=nRowsvalid;
   return stddev;
}

unsigned int DATA_FRAME::countWord(unsigned int col,std::string tofind)
{
  if(!IsCategorical(col))
	throw std::invalid_argument("Tried to count word from a numerical column");

  unsigned int nFrequencies = 0;
   for (auto rowIt = this->rowIterbegin();rowIt!=this->rowIterEnd();rowIt++)
   {
    auto item = *(rowIt); // Get the row.
	std::string item_ = std::get<std::string>(item[col-1]);
	if(item_==tofind)
	  nFrequencies++;
   }
   return nFrequencies;
} //end loop trough the rows.
   



// Explicit specialization:
template<class colTYPE>
std::vector<colTYPE> DATA_FRAME::getCol(unsigned int col)
{
  std::vector<colTYPE> _col_;
  for (auto rowIt = this->rowIterbegin();rowIt!=this->rowIterEnd();rowIt++)
  {
   auto item = *(rowIt); // Get the row.
   colTYPE item_ = std::get<colTYPE>(item[col-1]);
   _col_.push_back(item_);
  }
 return _col_;
}

template
std::vector<std::string> DATA_FRAME::getCol<std::string>(unsigned int col);
template
std::vector<double> DATA_FRAME::getCol<double>(unsigned int col);
template
std::vector<int> DATA_FRAME::getCol<int>(unsigned int col);

/*
template<>
std::vector<std::string> DATA_FRAME::getCol(unsigned int col)
{
  std::vector<std::string> _col_;
  for (auto rowIt = this->rowIterbegin();rowIt!=this->rowIterEnd();rowIt++)
  {
   auto item = *(rowIt); // Get the row.
   std::string item_ = std::get<std::string>(item[col-1]);
   _col_.push_back(item);
  }
 return _col_;
}
*/





