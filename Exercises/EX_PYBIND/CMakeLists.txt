cmake_minimum_required(VERSION 2.8.12)
project(example)


add_subdirectory(pybind11-cmakedir)
pybind11_add_module()
