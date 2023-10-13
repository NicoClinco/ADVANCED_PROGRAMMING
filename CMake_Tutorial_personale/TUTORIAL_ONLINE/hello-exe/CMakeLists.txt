add_executable(HelloExecutable simpleProgram.cpp)

target_link_libraries(HelloExecutable PRIVATE plotLib)
target_link_libraries(HelloExecutable PRIVATE plotLib2)

