
// Implementation file:

#include "DATA_FRAME.hpp"


void DATA_FRAME::read(std::string FILEIN)
{
  std::ifstream file_(FILEIN);
  std::string line;

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
     std::cout<<_word_<<std::endl;
    }// end row-loop
    dataframe.push_back(currentRow);
  }
  file_.close();
}

bool DATA_FRAME::IsNumeric(unsigned int col) const
{
  return (row_structure[col] == "double" || row_structure[col] == "int");
}


bool DATA_FRAME::IsColumn(unsigned int col) const
{
  return (col <= row_structure.size());
}

bool DATA_FRAME::IsRow(unsigned int row) const
{
   return (row <= _rows_);
}
/*
double DATA_FRAME::mean(unsigned int col) const
{
  if(!IsNumeric(col))
     throw std::invalid_argument("Cannot do the mean of categorical values");

     
   // Perform a loop trough the vector
   double _mean_ = 0.0;
   int token_type = map_[row_structure[col-1]];
  
   for (auto rowIt = this->rowIterbegin();rowIt!=rowIter.end();rowIt++)
   {
    switch (token_type)
    {
     case 0:
      // Check if the value is NAN
     break;
     case 2
      
     break;
    }
    
   }
  
}
*/

