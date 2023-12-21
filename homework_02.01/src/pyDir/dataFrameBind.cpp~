#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "data_frame.hpp"


namespace py = pybind11;
PYBIND11_MODULE(dataFrameBind, m) {
  m.doc() = "pybind11 example plugin"; // optional module docstring

  py::class_<CSV_READER::dataframe>(m,"pyDataFrame")
    .def(py::init<const std::string&>())
    .def("Read",&CSV_READER::dataframe::Read,"Read the file specified by the user")
    .def_readwrite("filename_",&CSV_READER::dataframe::filename_)
    .def_readwrite("data",&CSV_READER::dataframe::v)
    .def_readwrite("headernames",&CSV_READER::dataframe::headersName);
}
