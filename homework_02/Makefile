CXX=g++

BOOST_PATH=/u/n/nclinco/Downloads/ADV_PROGRAMMING/boost

GSL_PATH=/u/n/nclinco/Downloads/ADV_PROGRAMMING/gsl

CPPFLAGS=-I./data_frame_module -I$(BOOST_PATH)/include \
	     -I$(GSL_PATH)/include

CXXFLAGS=-std=c++17 -Wall -Wpedantic


LDFLAGS=-Wl,-rpath,data_frame_module/  \
	-Wl,-rpath,$(BOOST_PATH)/lib \
	-Wl,-rpath,$(GSL_PATH)/lib \
	-Ldata_frame_module \
	-L$(BOOST_PATH)/lib \
	-L$(GSL_PATH)/lib

LDLIBS=-lDataFrame -lboost_program_options -lgsl -lgslcblas


SRC=main.cpp
OBJ=$(SRC:.cpp=.o)

.PHONY : all clean

all: main

main: $(OBJ)
	$(CXX) $(CXXFLAGS) $^ $(LDFLAGS) $(LDLIBS) -o $@
%.o: %.cpp
	$(CXX) -c $< $(CPPFLAGS) $(CXXFLAGS) -o $@

clean:
	rm -f *.o main
