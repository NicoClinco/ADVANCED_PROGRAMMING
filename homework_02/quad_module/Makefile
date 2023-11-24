CXX=g++

BOOST_PATH=/u/n/nclinco/Downloads/ADV_PROGRAMMING/boost

GSL_PATH=/u/n/nclinco/Downloads/ADV_PROGRAMMING/gsl

CXX=g++
CPPFLAGS=-I. -I$(BOOST_PATH)/include \
		 -I$(GSL_PATH)/include

CXXFLAGS=-std=c++17 -Wall -Wpedantic


LDFLAGS=-Wl,-rpath,$(BOOST_PATH)/lib \
		-Wl,-rpath,$(GSL_PATH)/lib \
		-L$(BOOST_PATH)/lib \
		-L$(GSL_PATH)/lib

LDLIBS=-lboost_program_options -lgsl -lgslcblas


SRC=main.cpp
OBJ=$(SRC:.cpp=.o)

all: main

main: $(OBJ)
	$(CXX) $(CXXFLAGS) $^ $(LDFLAGS) $(LDLIBS) -o $@
%.o: %.cpp
	$(CXX) -c $< $(CPPFLAGS) $(CXXFLAGS) -o $@

clean:
	rm -f *.o main
