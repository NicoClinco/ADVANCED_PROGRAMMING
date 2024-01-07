#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/stl_bind.h>
#include <pybind11/operators.h>

#include "DATA_FRAME.hpp"
#include "CSV_WRITER.hpp"


PYBIND11_MAKE_OPAQUE(std::vector<std::string>);
PYBIND11_MAKE_OPAQUE(CSV_READER::VecOpvar);
PYBIND11_MAKE_OPAQUE(std::vector<CSV_READER::VecOpvar>);


namespace py = pybind11;
/*
// Automatic type-checking:
template<typename Numeric>
bool is_number(const std::string& s)
{
  Numeric n;
  return((std::istringstream(s) >> n >> std::ws).eof());
}
*/



PYBIND11_MODULE(dataFrameBind, m) {

  m.doc() = "Conversion of the statistic module and the writer for csv files"; // optional module docstring
  
  py::bind_vector<std::vector<std::string>>(m, "VectorString");
  py::bind_vector<CSV_READER::VecOpvar>(m,"VecOpvar");
  py::bind_vector<std::vector<CSV_READER::VecOpvar>>(m,"vVecOpvar");

  py::class_<CSV_READER::DATA_FRAME> pyDF(m,"pyDF",py::dynamic_attr());
  pyDF.def(py::init<>()); //Default constructor
  pyDF.def(py::init<const std::string>()); //Construct from config-file

  /*
  // 07-01-24: Construct by reading the CSV-file as strings
  pyDF.def(py::init([](const std::string FILEIN,bool HasHeader){
    
    CSV_READER::DATA_FRAME df; //Default constructor
    std::ifstream file_(FILEIN);
    std::string line;
    
    // Read the first row in case the header is present:
    std::map<std::string,unsigned int> header_;
    unsigned int counterH = 0;
    if(HasHeader){
      file_>>line;
      std::stringstream ss(line);
      std::string _word_;
      while(std::getline(ss,_word_,',')){
	header_[_word_] = counterH;
	counterH++;
      }
    }
    df.set_HeaderNames(header_);

    std::vector<CSV_READER::VecOpvar> dataframe;
    CSV_READER::VecOpvar currentRow; 
    // Read the rest of lines:
    while(file_>>line)
      {

	std::stringstream ss(line);
	std::string _word_;
   
	while(std::getline(ss,_word_,','))
	  {
	    std::cout << _word_<<std::endl;
	    if(is_number<int>(_word_))
	      {
		currentRow.push_back(df.opInt(_word_));
	      }
	    else if(is_number<double>(_word_))
	      {
		currentRow.push_back(df.opDouble(_word_));
	      }
	    else
	      {
		currentRow.push_back(df.opString(_word_));
	      }
	    
	  }//end line
	dataframe.push_back(currentRow);
      }
	file_.close();
	df.set_data() = dataframe;
	return new CSV_READER::DATA_FRAME(df);
      }));
  */
  pyDF.def("IsDouble",&CSV_READER::DATA_FRAME::opDouble);
  pyDF.def("IsString",&CSV_READER::DATA_FRAME::opString);
  pyDF.def("IsInt",&CSV_READER::DATA_FRAME::opInt);
  pyDF.def("read",&CSV_READER::DATA_FRAME::read);

  // Magic methods for get the lenght of a column:
  pyDF.def("__len__",[](CSV_READER::DATA_FRAME& df){return df.get_data().size();});
  
  // Magic methods to get the column:
  pyDF.def("__getitem__",py::overload_cast<size_t>(&CSV_READER::DATA_FRAME::getCol<double>,py::const_),"Get the column by index");
  pyDF.def("__getitem__",py::overload_cast<size_t>(&CSV_READER::DATA_FRAME::getCol<std::string>,py::const_),"Get the column by index");
  pyDF.def("__getitem__",py::overload_cast<std::string>(&CSV_READER::DATA_FRAME::getCol<double>,py::const_),"Get the column, depending on the header names");
  pyDF.def("__getitem__",py::overload_cast<std::string>(&CSV_READER::DATA_FRAME::getCol<std::string>,py::const_),"Get the column, depending on the header names");

  // Methods for statistical operations:
  pyDF.def("mean",py::overload_cast<size_t>(&CSV_READER::DATA_FRAME::mean,py::const_),"Mean of a specified column");
  pyDF.def("mean",py::overload_cast<std::string>(&CSV_READER::DATA_FRAME::mean,py::const_),"Mean of a specified column");
  pyDF.def("stdDev",py::overload_cast<size_t>(&CSV_READER::DATA_FRAME::stdDev,py::const_),"Standard deviation of a specified column");
  pyDF.def("stdDev",py::overload_cast<std::string>(&CSV_READER::DATA_FRAME::stdDev,py::const_),"Standard deviation of a specified column");
  pyDF.def("var",py::overload_cast<size_t>(&CSV_READER::DATA_FRAME::var,py::const_),"Variance of a column");
  pyDF.def("var",py::overload_cast<std::string>(&CSV_READER::DATA_FRAME::var,py::const_),"Variance of a column");
  // Check the goodness of the dataframe:
  pyDF.def("IsNumeric",&CSV_READER::DATA_FRAME::IsNumeric,"True if the column has numerical values");
  pyDF.def("IsCategorical",&CSV_READER::DATA_FRAME::IsNumeric,"True if the column has string values");
  pyDF.def("IsColumn",&CSV_READER::DATA_FRAME::IsColumn,"True if the index of the column is in the correct range");
  pyDF.def("IsRow",&CSV_READER::DATA_FRAME::IsRow,"True if the index of the row is in the correct range");
  pyDF.def("LinRegID",&CSV_READER::DATA_FRAME::LinearRegression<int,double>,"Perform the linear regression of two columns");
  pyDF.def("LinRegDD",&CSV_READER::DATA_FRAME::LinearRegression<double,double>,"Perform the linear regression of two columns");
  pyDF.def("LinRegDI",&CSV_READER::DATA_FRAME::LinearRegression<double,int>,"Perform the linear regression of two columns");
  pyDF.def("LinRegII",&CSV_READER::DATA_FRAME::LinearRegression<int,int>,"Perform the linear regression of two columns");
  
	   
  pyDF.def("__call__",&CSV_READER::DATA_FRAME::operator(),"Return the specific entry in the dataframe");
  pyDF.def_property("data",&CSV_READER::DATA_FRAME::get_data,&CSV_READER::DATA_FRAME::set_data);
  pyDF.def("header_names",[](const CSV_READER::DATA_FRAME& df){
    // Reorder the map by the values:
    auto mapNames = df.HeaderNames();
    std::vector<std::string> names(mapNames.size(),"");
    for (auto const& x : mapNames)
      names[x.second] = x.first;
    return names;  
  },"Get the header names for columns");
  // Iterator for rows:
  pyDF.def
    (
     "__iter__",
     [](CSV_READER::DATA_FRAME &df){return py::make_iterator(df.get_data().begin(),df.get_data().end());},
     py::keep_alive<0, 1>() /* Essential: keep object alive while iterator exists */);

  pyDF.def("__repr__",
	   [](const CSV_READER::DATA_FRAME &a) {
	     // TO FIX the output:
	     return "A generic class for parsing CSV FILE";
	   });
  // Output methods:
  pyDF.def("SetOutputFile",&CSV_READER::DATA_FRAME::setOutputfile);

  pyDF.def("write",&CSV_READER::DATA_FRAME::write,py::arg("separator")=" ");

  pyDF.def("writeEntry",&CSV_READER::DATA_FRAME::WriteEntry<double>,"Write a double in the specified file");
  pyDF.def("writeEntry",&CSV_READER::DATA_FRAME::WriteEntry<int>,"Write an int in the specified file");
  pyDF.def("writeEntry",&CSV_READER::DATA_FRAME::WriteEntry<std::string>,"Write a string in the specified file");
  pyDF.def("writeEntry",&CSV_READER::DATA_FRAME::WriteEntry<std::vector<double>>,"Write a VectorDouble in the specified file");
  pyDF.def("writeEntry",&CSV_READER::DATA_FRAME::WriteEntry<std::vector<std::string>>,"Write a VectorDouble in the specified file");
  
  pyDF.def("closeOutput",&CSV_READER::DATA_FRAME::closeOutput,"Close the output file");
  
  // Iterator for rows:
  py::class_<CSV_READER::DATA_FRAME::RowIterator>(pyDF,"RowIterator")
   
    .def(py::init<typename CSV_READER::DATA_FRAME::RowIterator::pRowIterator>())
    .def("__iter__",
	 [](CSV_READER::DATA_FRAME::RowIterator& rowIter){
	   return rowIter;},
	 py::keep_alive<0,1>())
    .def("__next__",
	 [](CSV_READER::DATA_FRAME::RowIterator& rowIter){
	   rowIter++;
	 },
	 py::keep_alive<0,1>()
	 )
   
    .def("__add__",&CSV_READER::DATA_FRAME::RowIterator::operator+,py::keep_alive<0,1>())
    .def("__sub__",&CSV_READER::DATA_FRAME::RowIterator::operator-,py::keep_alive<0,1>())
    .def("getEntry",[](CSV_READER::DATA_FRAME::RowIterator& rowIter)
    {
      // Get the entire row:
      return rowIter.operator*();
    })
    //Operators for inequalities:
    .def(py::self == py::self)
    .def(py::self != py::self)
    .def("__repr__",
	 [](CSV_READER::DATA_FRAME::RowIterator &RowIter) {
	   return "Iterator used for iter trough the rows of the data-frame";
	 });

  pyDF.def("rowIterbegin",&CSV_READER::DATA_FRAME::rowIterbegin);
  pyDF.def("rowIterEnd",&CSV_READER::DATA_FRAME::rowIterEnd);


  //Iterator for columns:
  py::class_<CSV_READER::DATA_FRAME::colIterator>(pyDF,"ColIterator")
    .def(py::init<CSV_READER::DATA_FRAME::RowIterator,size_t>())
    .def("__iter__",
	 [](CSV_READER::DATA_FRAME::colIterator& colIter){
	   return colIter;
	 },
	 py::keep_alive<0,1>())
    .def("__next__",
	 [](CSV_READER::DATA_FRAME::colIterator& colIter){
	   colIter++;
	 }) 
    // Get a specific entry:
    .def("getEntry",
	 [](CSV_READER::DATA_FRAME::colIterator& colIter){
	   return colIter.operator*();
	 })
    
    //Operators for inequalities:
    .def(py::self == py::self)
    .def(py::self != py::self)
    .def("__repr__",
	 [](CSV_READER::DATA_FRAME::RowIterator &RowIter) {
	   return "Iterator used for iter trough the rows of the data-frame";
	 });

  pyDF.def("colIterbegin",&CSV_READER::DATA_FRAME::colIterbegin);
  pyDF.def("colIterEnd",&CSV_READER::DATA_FRAME::colIterEnd);
	 

  // Class for writing CSV FILES:

  py::class_<CSV_WRITER> pyCSVWriter(m,"pyCSVwriter");
    pyCSVWriter.def(py::init<std::string,const std::string>());
    pyCSVWriter.def("write",&CSV_WRITER::write);
    pyCSVWriter.def("close",&CSV_WRITER::close);
    pyCSVWriter.def("writeToFile",[](CSV_WRITER& writer,const std::string val)
    {
      writer.operator<<(val);
    });
    pyCSVWriter.def("writeToFile",[](CSV_WRITER& writer,const double val)
    {
      writer.operator<<(val);
      
    });
    pyCSVWriter.def("writeToFile",[](CSV_WRITER& writer,const int val)
    {
      writer.operator<<(val);
     
    });
    pyCSVWriter.def("writeToFile",[](CSV_WRITER& writer,const std::vector<double> val)
    {
      writer.operator<<(val);
      
    });
    pyCSVWriter.def("writeToFile",[](CSV_WRITER& writer,const std::vector<int> val)
    {
      writer.operator<<(val);
 
    });
    pyCSVWriter.def("writeToFile",[](CSV_WRITER& writer,const std::vector<std::string> val)
    {
      writer.operator<<(val);
      
    });
    pyCSVWriter.def("endrow",&CSV_WRITER::endrow);
    pyCSVWriter.def("isActive",&CSV_WRITER::isActive);
    
    
    
}
