project(eigenMultiplication)


set(CMAKE_LIBRARY_OUTPUT_DIRECTORY /home/nico/Desktop/PHD-COURSES/ADVANCED_PROGRAMMING/Exercises/EX_PYBIND/ex_3/libs)
set(EIGEN_INCLUDE_DIR /home/nico/Desktop/PHD-COURSES/libraries/eigen/include/eigen3)

set(SOURCE_FILES src/eigen_op.cpp)

set(PYTHON_FILES src/pythonEig.cpp)


find_package(pybind11 REQUIRED)

pybind11_add_module(pythonEig
        ${SOURCE_FILES} 
	${PYTHON_FILES}
)

target_include_directories(pythonEig PUBLIC ${EIGEN_INCLUDE_DIR} PUBLIC include)
