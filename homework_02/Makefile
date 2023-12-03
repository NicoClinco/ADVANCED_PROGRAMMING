CXX=g++

# Libraries needed for compile main_DATA_FRAME:
BOOST_PATH=/home/nico/Desktop/PHD-COURSES/libraries/Boost


#Libraries needed to compile main_NUMERICAL_INTEGRATION:
# gsl and matplotplusplus (install from zip in this directory)
GSL_PATH=/home/nico/Desktop/PHD-COURSES/libraries/gsl
MATPLOTPP_INCLUDE =/home/nico/Desktop/TEMPORARY/MATPLOTPLUSPLUS
MATPLOTPP_LIB=/home/nico/Desktop/TEMPORARY/MATPLOTPLUSPLUS/lib
MATPLOTPP_LIBNODESOUP=/home/nico/Desktop/TEMPORARY/MATPLOTPLUSPLUS/lib/Matplot++

CPPFLAGS_DATAFRAME = -I./data_frame_module -I$(BOOST_PATH)/include

CPPFLAGS_QUAD = -I$(MATPLOTPP_INCLUDE)/include -I./quad_module \
		-I$(GSL_PATH)/include

CXXFLAGS=-std=c++17 -Wall -Wpedantic -Werror


LD_FLAGS_DATAFRAME = -Wl,-rpath,data_frame_module/          \
	             -Wl,-rpath,$(BOOST_PATH)/lib           \
	             -Ldata_frame_module                    \
		     -L$(BOOST_PATH)/lib                    

LD_FLAGS_QUAD = -Wl,-rpath,quad_module/                \
		-Wl,-rpath,$(MATPLOTPP_LIB)            \
		-Wl,-rpath,$(MATPLOTPP_LIBNODESOUP)    \
	        -Wl,-rpath,$(GSL_PATH)/lib             \
	        -Lquad_module                          \
	        -L$(MATPLOTPP_LIB)	               \
	        -L$(MATPLOTPP_LIBNODESOUP)	       \
	        -L$(GSL_PATH)/lib   

# Libs required for main_DATA_FRAME.cpp
LD_LIBS_DATAFRAME = -lDataFrame -lboost_program_options

# Libs required for quad_module lib
LD_LIBS_QUAD_LIB = -lgsl -lgslcblas

# Libs required for main_NUMERICAL_INTEGRATION.cpp
LD_LIBS_QUAD = -lQuadrature -lmatplot -lnodesoup $(LD_LIBS_QUAD_LIB)


SRC_DATAFRAME=main_DATA_FRAME.cpp
SRC_QUAD=main_NUMERICAL_INTEGRATION.cpp

OBJ_DF=$(SRC_DATAFRAME:.cpp=.o)
OBJ_QUAD=$(SRC_QUAD:.cpp=.o)

.PHONY : clean


all : quad_module data_frame_module

quad_module : quadLib main_NUMERICAL_INTEGRATION

data_frame_module : dataLib main_DATA_FRAME



main_DATA_FRAME: $(OBJ_DF)
	$(CXX) $(CXXFLAGS) $^ $(LD_FLAGS_DATAFRAME) $(LD_LIBS_DATAFRAME) -o $@
	rm -f main_DATA_FRAME.o

main_DATA_FRAME.o: main_DATA_FRAME.cpp
	$(CXX) -c $< $(CPPFLAGS_DATAFRAME) $(CXXFLAGS) -o $@
	rm -f main_NUMERICAL_INTEGRATION.o

main_NUMERICAL_INTEGRATION: $(OBJ_QUAD)
	$(CXX) $(CXXFLAGS) $^ $(LD_FLAGS_QUAD) $(LD_LIBS_QUAD) -o $@
main_NUMERICAL_INTEGRATION.o: main_NUMERICAL_INTEGRATION.cpp
	$(CXX) -c $< $(CPPFLAGS_QUAD) $(CXXFLAGS) -o $@

#Generate the library for data_frame automatically:
export BOOST_PATH
dataLib:
	$(MAKE) -C data_frame_module

#Generate the library for quadrature automatically:
export GSL_PATH
export LD_LIBS_QUAD_LIB
quadLib:
	$(MAKE) -C quad_module

clean:
	rm -f *.o main_NUMERICAL_INTEGRATION main_DATA_FRAME

