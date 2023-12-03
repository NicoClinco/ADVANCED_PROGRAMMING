homework_02 : Nicola Clinco


(INSTALLATION WITH MAKEFILE - UPDATE 01/12/23)
{
  -In the principal directory is contained a Makefile
   that allows us to build the dataframe module and
   the quadrature module:

  -The user has just to specify the path directory where
   boost, gsl and matplotplusplus is installed:

  -For the statistic module:
  -The user has to specify BOOST_PATH in the principal Makefile
   (it is not necessary that the user modify the Make in /dataframe
   with the path of boost since it is exported from the principal Make)

  -The user can run "make data_frame_module" and then, main_DATA_FRAME
   is available to be launched.

  -For the quadrature module:
  -The user has to specify GSL_PATH if he wants only create the library
   for the quadrature module, while he must specify the path to
   MATPLOTPLUSPLUS for running main_NUMERICAL_INTEGRATION.
   Again, there is no need to specify the path in the subfolder
   quad_module since it is exported from the principal Makefile.
  -The user can run "make quadrature_module" and then,
   main_NUMERICAL_INTEGRATION is available to be launched.
}


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
}

  (PREREQUISITE: data_frame_module)
  {
   You need to have installed in your system the following packages
    -the boost library  https://www.boost.org/
  }
   
  {(REALLY BASIC USAGE- main_DATA_FRAME )
  {
   After the compilation and the linking, the user can run
   the main program specifying an input file and an output file
   in which he wants to output some operations.

  RUN THE APPLICATION:-------------------------------------------
  The user has to run  main_DATA_FRAME with the following command:

   ./main_DATA_FRAME -c <configFile> -f <CSVfile> -o <outputfile>

  In our case:

   ./main_DATA_FRAME -c configCSV.txt -f London_weather.csv -o statistics.txt

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
      -By default, the file is opened in the "ouput/append mode", thus, if
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
  

-See main_DATA_FRAME.cpp for basic usage:
 I selected the london weather dataset from kaggle
 https://www.kaggle.com/datasets/emmanuelfwerr/london-weather-data
 that contains some information about measured wheater data (such as
 the pressure, temperature...) of London measured from 1970.


 A Few details about the data-storage:
 
  -In order to have the same "data-structure" as the original 
   file (to see everything like a matrix), i've decided to create
   a vector of vector of optional of variants, stored by rows:
   In this manner, it is easy to iterate trough the data thanks
   to the iterators, however, a weakness of the approach is that
   the method could be not fast as in the case we have stored by 
   column.
   
  -In the class data_frame it is stored a smart pointer to a class
   (CSV_WRITER) that handles the output: the idea is to have an 
   easy way to write various operations in the file by using
   the DATA_FRAME class with the method "writeEntry()".
 }





NUMERICAL_INTEGRATION class for calculating 1D integrals
{
 An extendible base class "NUMERICAL_INTEGRATION"
 that has a callable operator() inherits from a base class
 (specialized) for the specific quadrature formula adopted:
 -Trapezoidal-rule
 -Midpoint-rule
 -Simpson-rule
 -Gauss-Legendre-rule: from the GSL library:
  https://www.gnu.org/software/gsl/doc/html/integration.html#gauss-legendre-integration


  (PREREQUISITE: quadrature_module)
  {
   You need to have installed in your system the following packages
   -the boost library  https://www.boost.org/
   -the gsl library    https://www.gnu.org/software/gsl/
   -matplotplusplus     https://alandefreitas.github.io/matplotplusplus/
   -The latter is required for plotting graphs.

   NOTE - In order to use matplot++, you can follow the instruction
          on the site (and use CMake to link your app to the program)
	  or link the two libraries needed by specifing them as in my Makefile:

          If you have installed matplot++ in a directory (INSTALLATION_DIR),
          you have just to include:
	  libmatplot.a (that is located in INSTALLATION_DIR/lib/libmatplot.a)
	  and libnodesoup.a (located in INSTALLATION_DIR/lib/Matplot++/libnodesoup.a)

	  follow the Makefile in this directory for clarity "MATPLOTPLUSPLUS" is
	  the INSTALLATION_DIR where matplot++ is installed in my case.
  }

 -See "quad_module/Quadrature.hpp" if you want to extend
  the function to other types of quadrature.
 -See main_NUMERICAL_INTEGRATION.cpp for the basic usage
  -In the main_NUMERICAL_INTEGRATION.cpp i've reported two examples:
  -f(x)=x : The results confirm that all the quadrature formulas are exact naturally,
            since f'' = 0.
            I've not plotted the convergence lines because the library gives some
            problems with plotting with small numbers...  
  -f(x)=sin(x) :
  -In order to show the order of convergence between the four methods,
   it is plotted a graph that shows the order of convergence between them (sinx.png)
   for the function f(x) = sin(x) x from [0,π]
   generated with the lib matplotplusplus: https://github.com/alandefreitas/matplotplusplus
   Note that:
    -The trapezoidal and the midpoint show the same order of convergence (N^-2)
    -The Simpson-rule is faster (N^-4)
    -The Gauss-Legendre is even more faster (the results are are shown until N=5, because,
     again, for small numbers the library gives problem in plotting).
  
  A quick remark on the Gauss-Legeandre formula:
    -Despite my implementation is inefficient for large number of nodes (i use two times the
     function of GLS that returns the weights and the quadrature points), i tought to mantain
     the same design pattern of the Simpson, Trapz and Midpoint.
     The most efficient way to calculate the integral is to use only one time the function
     in the operator ().
}

