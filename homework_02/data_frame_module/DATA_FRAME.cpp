
// Implementation file:

#include "DATA_FRAME.hpp"

CSV_READER::DATA_FRAME::DATA_FRAME(std::string CONFIG_FILE)
{
 
  std::ifstream config_file(CONFIG_FILE);
  std::string line;
  //check the correctness:
  if(!config_file.good())
    throw("Error: the config-file is corrupted\n");

  std::vector<std::string> SplitVec;

  std::getline(config_file,line);
 
  boost::split(SplitVec,line,boost::is_any_of("= , \t"),
                       boost::token_compress_on);
  bool Check_config = false;
  for(auto x : SplitVec)
  {
    if(x=="header_cols")
      Check_config=true;
     if(x!="header_cols")
       row_structure.push_back(x);
  }
  std::cout << Check_config << std::endl;
  Check_config ? (configFile=true) : throw std::invalid_argument("ERROR-WRONG ENTRIES IN THE CONFIG-FILE\n");
}


void CSV_READER::DATA_FRAME::read(std::string FILEIN)
{
  std::ifstream file_(FILEIN);
  std::string line;

 
  VecOpvar currentRow(row_structure.size());

  // check if the file is good:
  if(!file_.good())
    throw("Error: the file does not exist\n");
  
  while(file_>>line)
  {

    std::stringstream ss(line);
    std::string _word_;
    int counter = 0;
    
    while(std::getline(ss,_word_,','))
    {
      	  
      int token_type = map_[row_structure[counter]];
      switch (token_type)
      {
        case 0:
	  currentRow[counter] = opDouble(_word_);
	break;
	case 1:
	   currentRow[counter] = opString(_word_);
 	 break;
	 case 2:
	   currentRow[counter] = opInt(_word_);
	  break;
      }// end switch
     counter++;
   
    }// end row-loop
    dataframe.push_back(currentRow);
    _rows_++;
  }
  file_.close();
}

bool CSV_READER::DATA_FRAME::IsNumeric(size_t col) const
{
  if(!IsColumn(col))
	 throw std::invalid_argument("Invalid index of the column");
  
  return (row_structure[col-1] == "double" || row_structure[col-1] == "int");
}

bool CSV_READER::DATA_FRAME::IsCategorical(size_t col) const
{
 if(!IsColumn(col))
   throw std::invalid_argument("Invalid index of the column\n");
  
  return (row_structure[col-1] == "string");
}


bool CSV_READER::DATA_FRAME::IsColumn(size_t col) const
{
  return (col <= row_structure.size());
}

bool CSV_READER::DATA_FRAME::IsRow(size_t row) const
{
   return (row <= _rows_);
}

std::map<std::string, int> CSV_READER::DATA_FRAME::map() const
{
  return map_;
}

std::vector<std::string> CSV_READER::DATA_FRAME::rowstructure() const
{
  return row_structure;
}

double CSV_READER::DATA_FRAME::mean(size_t col) const
{
  if(!IsNumeric(col))
     throw std::invalid_argument("Cannot do the mean of categorical values");

     
   // Perform a loop trough the vector and calculate the mean
   double _mean_ = 0.0;
   int token_type = map_.at(row_structure[col-1]); 
   unsigned int nRowsvalid = 0;
   for (auto rowIt = this->crowIterbegin();rowIt!=this->crowIterEnd();rowIt++)
   {
    auto item =*(rowIt); // Get the row:
    if(item[col-1].has_value())
    {
      switch (token_type)
	{
	case 0:
	  _mean_+=std::get<double>(item[col-1].value());
	  break;
	case 2:
	  _mean_+=std::get<int>(item[col-1].value());
	  break;
	}
      nRowsvalid++;
    }
    
   } //end loop trough the rows.

  _mean_/=nRowsvalid;

  // if it is writing, write to file:
  std::string title = "Mean of column " + std::to_string(col)+ +":";
  this->WriteEntry(title,_mean_);
  
  return _mean_;
}

double CSV_READER::DATA_FRAME::stdDev(size_t col) const
{
  if(!IsNumeric(col))
    throw std::invalid_argument("Cannot do the std-dev for categorical values");

  // Avoid to write the mean if it is possible to write:
  bool prevWritestate = Iswriting;
  if(Iswriting==true)
    Iswriting=false;
  
  double mean = this->mean(col);
  Iswriting = prevWritestate;
  
  double stddev = 0.0;
  // Perform a loop
  int token_type = map_.at(row_structure[col-1]); 
  unsigned int nRowsvalid = 0;
  for (auto rowIt = this->crowIterbegin();rowIt!=this->crowIterEnd();rowIt++)
    {
      auto item = *(rowIt); // Get the row.
      if(item[col-1].has_value())
	{
	  switch (token_type)
	    {
	    case 0:
	      {
		double item_ = std::get<double>(item[col-1].value());
		stddev+=(item_-mean)*(item_-mean);
		break;
	      }
	    case 2:
	      {
		int item_ = std::get<int>(item[col-1].value());
		stddev+=(item_-mean)*(item_-mean);
		break;
	      }
	    }
	  nRowsvalid++;
	}
    } //end loop trough the rows.
  stddev/=nRowsvalid;
  stddev=sqrt(stddev);

  std::string title = "Standard deviation of column " + std::to_string(col) +":";
  this->WriteEntry(title,stddev);
  return stddev;
}

double CSV_READER::DATA_FRAME::var(size_t col) const
{
  // Avoid to write the mean if it is possible to write:
  bool prevWritestate = Iswriting;
  if(Iswriting==true)
    Iswriting=false;
  double stddev = stdDev(col);
  Iswriting=prevWritestate;

  double var = stddev*stddev;

  std::string title = "Variance of column " + std::to_string(col) +":";
  this->WriteEntry(title,var);
    
  return var;
}

size_t CSV_READER::DATA_FRAME::countWord(size_t col,std::string tofind) const
{
  if(!IsCategorical(col))
    throw std::invalid_argument("Tried to count word from a numerical column");

  unsigned int nFrequencies = 0;
  for (auto rowIt = this->crowIterbegin();rowIt!=this->crowIterEnd();rowIt++)
    {
      auto item = *(rowIt); // Get the row.
      if(item[col-1].has_value()){
	std::string item_ = std::get<std::string>(item[col-1].value());
	if(item_==tofind)
	  nFrequencies++;
      }
    }//end row loop

  std::string title = "frequency count of world " + tofind +" in column "+std::to_string(col) +":";
  this->WriteEntry(title,nFrequencies);
  return nFrequencies;
} //end loop trough the rows.
   



// Explicit specialization:
template<class colTYPE>
std::vector<colTYPE> CSV_READER::DATA_FRAME::getCol(size_t col) const
{
  std::vector<colTYPE> _col_;
  for (auto rowIt = this->crowIterbegin();rowIt!=this->crowIterEnd();rowIt++)
  {
   auto item = *(rowIt); // Get the row.
   if (item[col-1].has_value())
   {
     colTYPE item_ = std::get<colTYPE>(item[col-1].value());
   _col_.push_back(item_);
   }
  }
 return _col_;
}

template
std::vector<std::string> CSV_READER::DATA_FRAME::getCol<std::string>(size_t col) const;
template
std::vector<double> CSV_READER::DATA_FRAME::getCol<double>(size_t col) const;
template
std::vector<int> CSV_READER::DATA_FRAME::getCol<int>(size_t col) const;



// Linear regression:
template<class colTYPEX,class colTYPEY>
std::tuple<double,double> CSV_READER::DATA_FRAME::LinearRegression(size_t colX,size_t colY) const
{
  if(!IsNumeric(colX))
    throw std::invalid_argument("Cannot do the linear-regression for categorical values");

  if(!IsNumeric(colY))
    throw std::invalid_argument("Cannot do the linear-regression for categorical values");
  
  std::vector<colTYPEX> _colX_;
  std::vector<colTYPEY> _colY_;
  
  for (auto rowIt = this->crowIterbegin();rowIt!=this->crowIterEnd();rowIt++)
  {
   auto item = *(rowIt); // Get the row.
   if(item[colX-1].has_value() && item[colY-1].has_value())
     {
       colTYPEX Xitem_ = std::get<colTYPEX>(item[colX-1].value());
       colTYPEY Yitem_ = std::get<colTYPEY>(item[colY-1].value());
   _colX_.push_back(Xitem_);
   _colY_.push_back(Yitem_);
     }
  }

  // Calculate y = w*x + b :

   const size_t N    = _colX_.size();
   const double s_x  = std::accumulate( _colX_.begin(),  _colX_.end(), 0.0);
   const double s_y  = std::accumulate( _colY_.begin(),  _colY_.end(), 0.0);
   const double  s_xx = std::inner_product(_colX_.begin(),_colX_.end(),_colX_.begin(), 0.0);
   const double s_xy = std::inner_product(_colX_.begin(),_colX_.end(), _colY_.begin(), 0.0);
   const double  w    = (N * s_xy - s_x * s_y) / (N* s_xx - s_x * s_x);
   const double  b    = (s_y - w*s_x)/N;

   return std::tuple<double,double>(w,b);
  
}

// EXPLICIT INSTATION FOR Linear Regression:
template
std::tuple<double,double> CSV_READER::DATA_FRAME::LinearRegression<double,double>(size_t colX,size_t colY) const;

template
std::tuple<double,double> CSV_READER::DATA_FRAME::LinearRegression<double,int>(size_t colX,size_t colY) const;

template
std::tuple<double,double> CSV_READER::DATA_FRAME::LinearRegression<int,double>(size_t colX,size_t colY) const;

template
std::tuple<double,double> CSV_READER::DATA_FRAME::LinearRegression<int,int>(size_t colX,size_t colY) const;

template<class T>
void CSV_READER::DATA_FRAME::makeHistogram(size_t col,std::string title,unsigned int n_interval) const
{
  if(IsNumeric(col))
    {
      using namespace boost::histogram;
      auto data = this->getCol<T>(col);
      // Get the maxium and the minimum element in the vector
      double xMin = *(std::min_element(data.begin(), data.end()));
      double xMax = *(std::max_element(data.begin(), data.end()));
      
      // Generate the histogram:
      auto hdata = make_histogram(axis::regular<>(n_interval,xMin,xMax,title));
      // Fill the istogram:
      std::for_each(data.begin(),data.end(),std::ref(hdata));

      std::ostringstream os;
      std::string to_print;
      for (auto&& x : indexed(hdata)) {
	os << boost::format("from-to [%4.1f, %4.1f): %i\n")
	  % x.bin().lower() % x.bin().upper() % *x;
      }
      to_print = os.str();
      title=title+"\n";
      // Write to file in the writing mode:
      this->WriteEntry(title,to_print);
    }
}

template
void CSV_READER::DATA_FRAME::makeHistogram<double>(size_t col,std::string title,unsigned int n_interval) const;

template
void CSV_READER::DATA_FRAME::makeHistogram<int>(size_t col,std::string title,unsigned int n_interval) const;

 
void CSV_READER::DATA_FRAME::setOutputfile(std::string _outfile_)
{
  outputfile_ = _outfile_;
}

void CSV_READER::DATA_FRAME::write(std::string separator)
{
  // if it is null:
  if(!pWriter_){
    pWriter_=std::unique_ptr<CSV_WRITER>(new CSV_WRITER(outputfile_,separator));
  }
  pWriter_->write();
  Iswriting=true;
}

void CSV_READER::DATA_FRAME::closeOutput()
{
  if(pWriter_)
    pWriter_->close();
  Iswriting=false;
}

template<class T>
void CSV_READER::DATA_FRAME::WriteEntry(std::string word,const T& val) const
{
  if(Iswriting && pWriter_){
    *pWriter_ <<word;
    *pWriter_ << val;
    pWriter_->endrow();
  }
}

// Functions needed to write in a file:

template
void CSV_READER::DATA_FRAME::WriteEntry<double>(std::string word,const double& val) const;

template
void CSV_READER::DATA_FRAME::WriteEntry<int>(std::string word,const int& val) const;

template
void CSV_READER::DATA_FRAME::WriteEntry<std::string>(std::string word,const std::string& val) const;


template
void CSV_READER::DATA_FRAME::WriteEntry<std::vector<double>>(std::string word,const std::vector<double>& val) const;


template
void CSV_READER::DATA_FRAME::WriteEntry<std::vector<std::string>>(std::string word,const std::vector<std::string>& val) const;
