
set(EXTRA_DIR1 "${CMAKE_CURRENT_SOURCE_DIR}/BaseMathFunctions/SquareRoot.cpp")
set(EXTRA_DIR2 "${CMAKE_CURRENT_SOURCE_DIR}/SecondMathFunctions/Square.cpp")

 

add_library(
  ${EXTRA_LIBS}
  ${EXTRA_DIR1}
)

add_library ( 
 ${EXTRA_LIBS1}
 ${EXTRA_DIR2}
)


target_include_directories(${EXTRA_LIBS} INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/BaseMathFunctions/")
target_include_directories(${EXTRA_LIBS1} INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/SecondMathFunctions/")
