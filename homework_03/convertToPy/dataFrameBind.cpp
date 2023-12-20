#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "data_frame.hpp"


namespace py = pybind11;
PYBIND11_MODULE(dataFrameBind, m) {
  m.doc() = "pybind11 example plugin"; // optional module docstring

  py::class_<CSV_READER::dataframe>(m,"pyDataFrame")
    .def(py::init<const std::string&>())
    .def("Read",&CSV_READER::dataframe::Read,"Read the file specified by the user")
    .def_readwrite("filename_",&CSV_READER::dataframe::filename_);
}
/*
this is a jointly work with m anna. It consists in a development of a density based solver for nearly hydrostatic flows.
In particular, the goal is to solve the compressible euler equations in the presence of gravity, we have tested 2 types of equation set, energy and potential temperature.
 The main bottleneck is the treatment of the source terms, because if not properly treated can give serious problems.
 Thus, in order to have a scheme balanced in a discrete sense, the idea is to perform a sort of local reconstruction in every cell according to a certain potential temperature profile. Then, calculate the perturbations from this equilibrum (I HAVE SKIPPED THE DETAILS)
*/
