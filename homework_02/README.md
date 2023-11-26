homework_02 : Nicola Clinco


DATA_FRAME class for managing csv file:
{
The class DATA_FRAME is specialized for reading a .csv file
and output some "basic" operation performed on data such as:

-mean
-std deviation
-variance
-linear regression between two columns
-make an histogram for numeric values
-word count for categorical values

-Data traversal with two iterators:
  -crowIterator : constant_iterator by rows
  -crowIterator : constant_iterator by cols
  -rowIterator  : iterator for rows
  -colIterator  : iterator for cols

-Save output to a file specified by the user.

WARNING:
 -In order to run main.cpp the user need to have:
   -boost library (dataframe module, parse input/output file)
   -gls library   (quadrature module)
   -matplotcpp    (it is a library useful to plot)

  NOTE (REALLY BASIC USAGE)
  {
   After the compilation and the linking, the user can run
   the main program specifying an input file and an output file
   in which he wants to output some operations.


   
  }

-See main.cpp for basic usage
}


numericalIntegration class for calculating 1D integrals
{
 An extendible base class "numericalIntegration"
 that has a callable operator() inherits from a base class
 (specialized) for the specific quadrature formula adopted:
 -Trapezoidal-rule
 -MidPoint-rule
 -Simpson-rule
 -Gauss-Legendre-rule

 -See "quad_module/Quadrature.hpp" if you want to extend
  the function to other types of quadrature.
 -See main.cpp for the basic usage
}

