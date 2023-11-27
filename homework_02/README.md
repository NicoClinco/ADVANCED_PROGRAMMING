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
 
  NOTE (REALLY BASIC USAGE)
  {
   After the compilation and the linking, the user can run
   the main program specifying an input file and an output file
   in which he wants to output some operations.

  RUN THE APPLICATION:-------------------------------------------
  The user has to run the main with the following command:

   ./main -c <configFile> -f <CSVfile> -o <outputfile>

   -In the config file it is specified the structure of the row of the csv file.
   -The CSVfile is the file where we read data
   -The output file is the file in output where we put some output informations.
  --------------------------------------------------------------

   -For the mean, standard deviation,variance and word count, the user
    can easily specify the column of the CSV file.
   -For plotting an histogram for the statistics, the user has to specify
    the column, the title, and the number of intervals, and optionally, he
    can specify if he want to print the result in the terminal.
   -The user can extract a specific column of the csv by getCol() method,
    by specifying the column.
   -For data-traversal, two types of iterators are implemented:
     -A const and a non-const iterator per row,
     -A const and a non-const iterator per column.

   OUTPUT FILE-----------------------------------------------------------
   In order to write in output file, a smart pointer to a CSV_WRITER class
   is stored in the dataframe class:
     -A CSV_WRITER is a class that allows us to write in a file:

     In the main it is shown the basic usage:

     1) Specify the output file (in the main is parsed by cmd line)
     
        df.setOutputfile(outfileName); 

     2) Write to the file, specifying the separator between the entries:

     	df.write(" "); //Specify the separator between the entries, default "tab"

         double mean6 = df.mean(6);
         double std_dev6 = df.stdDev(6);
         df.makeHistogram<double>(6,"Mean temperature statistics",20);


     3) df.closeOutput(); // close the output file

     NOTE:
      -By default, the file is opened in the "append mode", thus, if
       a file with the same name exist, the entries are appended.
      
      -The mean, the standard deviation, the histogram functions when
       called between df.write() and df.closeOutput() are written to
       the output in APPEND mode, for example, in the main:

       df.write() ------------
        // df.mean(col) -> the result is written in the output file
        // df.stdDev(col) -> the result is written in the output file
	// df.makeHistogram(col,"title",intervals) ...
       df.closeOutput() ------

        In this manner, the user does not need every time
	to specify where to write.
       
      - If a user wants to write an entry (for example a vector)
        in the file, it can use the method WriteEntry():
	  -In this case, the only entries allowed are double,int,string
	   and vectors since the class CSV_WRITER has the operator <<
	   overloaded for these types, future versions will extend
	   the operator to other types.
   ----------------------------------------------OUTPUT FILE------
  }

-See main.cpp for basic usage
}


numericalIntegration class for calculating 1D integrals
{
 An extendible base class "numericalIntegration"
 that has a callable operator() inherits from a base class
 (specialized) for the specific quadrature formula adopted:
 -Trapezoidal-rule
 -Midpoint-rule
 -Simpson-rule
 -Gauss-Legendre-rule: from the GSL library:
  https://www.gnu.org/software/gsl/doc/html/integration.html#gauss-legendre-integration

 -See "quad_module/Quadrature.hpp" if you want to extend
  the function to other types of quadrature.
 -See main.cpp for the basic usage
 -In order to show the order of convergence between the four methods,
  it is plotted a graph that show the order of convergence between them (error.png)
  for the function f(x) = sin(x) x from [0,π]
  generated with the lib matplotplusplus: https://github.com/alandefreitas/matplotplusplus
  Note that:
   -The trapezoidal and the midpoint show the same order of convergence (N^-2)
   -The Simpson-rule is faster (N^-4)
   -The Gauss-Legeandre is even more faster
}

