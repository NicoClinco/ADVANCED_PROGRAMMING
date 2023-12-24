#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include "DATA_FRAME.hpp"





namespace py = pybind11;
PYBIND11_MODULE(dataFrameBind, m) {
  m.doc() = "Conversion of the class DataFrame"; // optional module docstring

  py::class_<CSV_READER::DATA_FRAME> pyDF(m,"pyDF");
  pyDF.def(py::init<const std::string>());
  pyDF.def(py::init<std::vector<std::string>>());
  pyDF.def("IsDouble",&CSV_READER::DATA_FRAME::opDouble);
  pyDF.def("IsString",&CSV_READER::DATA_FRAME::opString);
  pyDF.def("IsInt",&CSV_READER::DATA_FRAME::opInt);
  pyDF.def("read",&CSV_READER::DATA_FRAME::read);
  pyDF.def("crowIterbegin",&CSV_READER::DATA_FRAME::crowIterbegin);
  pyDF.def("crowIterEnd",&CSV_READER::DATA_FRAME::crowIterEnd);
  pyDF.def("__getitem__",py::overload_cast<size_t>(&CSV_READER::DATA_FRAME::getCol<double>,py::const_),"Get the column by index");
  pyDF.def("__getitem__",py::overload_cast<size_t>(&CSV_READER::DATA_FRAME::getCol<std::string>,py::const_),"Get the column by index");
  pyDF.def("__getitem__",py::overload_cast<std::string>(&CSV_READER::DATA_FRAME::getCol<double>,py::const_),"Get the column, depending on the header names");
  pyDF.def("__getitem__",py::overload_cast<std::string>(&CSV_READER::DATA_FRAME::getCol<std::string>,py::const_),"Get the column, depending on the header names");
  pyDF.def("__call__",&CSV_READER::DATA_FRAME::operator(),"Return the specific entry");
  pyDF.def("data",&CSV_READER::DATA_FRAME::data,"Return the internal data-structure");
 
  pyDF.def("__repr__",
	   [](const CSV_READER::DATA_FRAME &a) {
	     // TO FIX the output:
	     return "A generic class for parsing CSV FILE";
	   });

  py::class_<CSV_READER::DATA_FRAME::cRowIterator>(pyDF,"cRowIterator")
    .def(py::init<typename CSV_READER::DATA_FRAME::cRowIterator::pRowIterator>())
    .def("__repr__",
	 [](const CSV_READER::DATA_FRAME::cRowIterator &a) {
	   // TO FIX the output:
	   return "Iterator used for iter trough the rows of the data-frame";
	 });
}
