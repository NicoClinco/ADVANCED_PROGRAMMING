cmake_minimum_required(VERSION 3.12)

add_executable(main mainDF.cpp)

target_include_directories(main PUBLIC /home/nico/Desktop/PHD-COURSES/ADVANCED_PROGRAMMING/homework_03/headers)
target_link_directories(main PUBLIC /home/nico/Desktop/PHD-COURSES/ADVANCED_PROGRAMMING/homework_03/libs)
target_link_libraries(main PUBLIC dataframe)

set_target_properties(main PROPERTIES RUNTIME_OUTPUT_DIRECTORY "/home/nico/Desktop/PHD-COURSES/ADVANCED_PROGRAMMING/homework_03/apps")
