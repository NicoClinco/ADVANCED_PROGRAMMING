#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <optional>


namespace py = pybind11;


using vecOp = std::vector<std::optional<double>>;

class MyIterable
{
public:
  MyIterable(const vecOp& data):
    m_data(data){};
  vecOp& getData()
  {
    return m_data;
  }
public:
  vecOp m_data;
};


class MyIterableString
{
public:
  MyIterableString(const std::vector<std::string>& data):
    m_data(data){};
  std::vector<std::string>& getData()
  {
    return m_data;
  }
public:
  std::vector<std::string> m_data;
};

/*

//Important:
 Try to create a try and catch block to handle
 the types.
  
class DataFrame
{
public:

  using IterableType = std::vector<std::vector<std::string>>;
  
  DataFrame(const std::string& filename);

  void Read(bool HasHeader)
  {
    std::ifstream filestream(filename);
    std::string line;
    
    //Loop trough the column and see everything like a big matrix
    if(!file_.good())
      throw("Error: the file does not exist\n");

    //Read the first line:
    if(HasHeader)
      {
	std::vector<std::string> headers_;
	std::getline(file_,line);
	boost::split(headers_,line,boost::is_any_of(","),boost::token_compress_on);
      }

    // Create a vector of vectors:
    DataFrame::IterableType v_(headers_.size(),std::vector<std::string>(0));
    v = v_;

    while(std::getline(filestream,line))
      {
	std::stringstream ss(line);
	std::string _word_;
	unsigned int counter = 0;
	//Read line by line and create the data:
	// Allocate the number of columns:
	while(std::getline(ss,_word_,','))
	  {
	    // Save everything, also the null values
	    // they will be treated better in python.
	    v[counter].push_back(_word_);
	    counter++;
	  }
	//Check the lecture:
	assert(counter == headers_.size());
      }
  }//end Read
  

private:
  
  DataFrame::IterableType v;
  
}

*/


PYBIND11_MODULE(example, m) {
  m.doc() = "pybind11 example plugin"; // optional module docstring

  py::class_<MyIterable>(m,"MyIterable")
    .def(py::init<const vecOp&>())
    .def("getData",&MyIterable::getData,"Get the internal data");

  py::class_<MyIterableString>(m,"MyIterableString")
    .def(py::init<const std::vector<std::string>&>())
    .def("getData",&MyIterableString::getData,"Get the internal data");
}
