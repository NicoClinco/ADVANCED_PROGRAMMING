CXX=g++
CPPFLAGS=-I./data_frame_module -I/home/nico/Desktop/PHD-COURSES/MY_BOOST/boost/ \
	 -I/home/nico/Desktop/PHD-COURSES/gls/include
CXXFLAGS=-std=c++17 -Wall -Wpedantic


LDFLAGS=-Wl,-rpath,data_frame_module/  \
	-Wl,-rpath,/home/nico/Desktop/PHD-COURSES/MY_BOOST/lib \
	-Wl,-rpath,/home/nico/Desktop/PHD-COURSES/gls/lib \
	-Ldata_frame_module \
	-L/home/nico/Desktop/PHD-COURSES/MY_BOOST/lib \
	-L/home/nico/Desktop/PHD-COURSES/gls/lib

LDLIBS=-lDataFrame -lboost_program_options -lgsl -lgslcblas


SRC=main.cpp
OBJ=$(SRC:.cpp=.o)

all: main

main: $(OBJ)
	$(CXX) $(CXXFLAGS) $^ $(LDFLAGS) $(LDLIBS) -o $@
%.o: %.cpp
	$(CXX) -c $< $(CPPFLAGS) $(CXXFLAGS) -o $@

clean:
	rm -f *.o ex1
