cmake_minimum_required(VERSION 3.18)

project(functionsTutoraial VERSION 1.0.0)

set(booleanVariable "TRUE")

if(booleanVariable)
	message(STATUS "the variable is ${booleanVariable}")
endif(booleanVariable)

function(DeferingVariablesIntoFunction var)
	message(STATUS "${${var}}")
endfunction()

DeferingVariablesIntoFunction(booleanVariable)
