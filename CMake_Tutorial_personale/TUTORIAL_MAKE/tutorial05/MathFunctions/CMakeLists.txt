add_library(MathFunctions MathFunctions.cxx)

# state that anybody linking to us needs to include the current source dir
# to find MathFunctions.h, while we don't.
target_include_directories(MathFunctions INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

# add the subdirectory for the other library
#add_subdirectory(MathLibraries)

add_library(PowerLibrary "${CMAKE_CURRENT_SOURCE_DIR}/MathLibraries/powerclass.cpp")
target_include_directories(PowerLibrary INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/MathLibraries")
target_link_libraries(Tutorial PUBLIC PowerLibrary)

option(USE_MYMATH "Use tutorial provided math implementation" ON)
if (USE_MYMATH)
  target_compile_definitions(MathFunctions PRIVATE "USE_MYMATH")

  # library that just does sqrt
  add_library(SqrtLibrary STATIC
              mysqrt.cxx
              )

  # link our compiler flags interface library
  target_link_libraries(SqrtLibrary PUBLIC tutorial_compiler_flags)
  target_link_libraries(MathFunctions PRIVATE SqrtLibrary)
endif()

# link our compiler flags interface library
target_link_libraries(MathFunctions PUBLIC tutorial_compiler_flags)

# TODO 1: Create a variable called installable_libs that is a list of all
# libraries we want to install (e.g. MathFunctions and tutorial_compiler_flags)
set(installable_libs MathFunctions tutorial_compiler_flags PowerLibrary)
install(TARGETS ${installable_libs} DESTINATION lib)
# Then install the installable libraries to the lib folder.
# Hint: Use the TARGETS and DESTINATION parameters

# TODO 2: Install the library headers to the include folder.
# Hint: Use the FILES and DESTINATION parameters
install(FILES MathFunctions.h "${CMAKE_CURRENT_SOURCE_DIR}/MathLibraries/powerclass.hpp" DESTINATION include)


