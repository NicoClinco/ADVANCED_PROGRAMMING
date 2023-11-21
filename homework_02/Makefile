CXX=g++
CPPFLAGS=-I./data_frame_module -I/home/nicopc/Desktop/PHD-COURSES/include
CXXFLAGS=-std=c++17 -Wall -Wpedantic


LDFLAGS=-Wl,-rpath,data_frame_module/  \
		   -Wl,-rpath,/home/nicopc/Desktop/PHD-COURSES/lib \
		   -Ldata_frame_module \
		   -L/home/nicopc/Desktop/PHD-COURSES/lib

LDLIBS=-lDataFrame -lboost_program_options


SRC=main.cpp
OBJ=$(SRC:.cpp=.o)

all: main

main: $(OBJ)
	$(CXX) $(CXXFLAGS) $^ $(LDFLAGS) $(LDLIBS) -o $@
%.o: %.cpp
	$(CXX) -c $< $(CPPFLAGS) $(CXXFLAGS) -o $@

clean:
	rm -f *.o ex1
