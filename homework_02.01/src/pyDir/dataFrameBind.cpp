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
  //.def_read("internalData", &CSV_READER::DATA_FRAME::dataframe)
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
