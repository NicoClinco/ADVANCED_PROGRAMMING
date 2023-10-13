add_executable(Calculations simpleProgramExe.cpp)



#[[ Here we include the directories of the binary because here is defined the
    variables which will be printed in the executable:

]]

target_include_directories(Calculations PUBLIC "${PROJECT_BINARY_DIR}")
target_link_libraries(Calculations PUBLIC tutorial_compiler_flags)

if(${MyMathLib})
	message(STATUS "Linking the libraries \n")
	target_link_libraries(Calculations PUBLIC ${EXTRA_LIBS})
	target_link_libraries(Calculations PUBLIC ${EXTRA_LIBS1})
endif()

