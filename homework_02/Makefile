CXX=g++
CPPFLAGS=-I./data_frame_module -I/home/nico/Desktop/TEMPORARY/homework_02/boost_1_83_0
CXXFLAGS=-std=c++17 -Wall -Wpedantic

LDFLAGS=-Wl,-rpath,data_frame_module/ -Wl,-rpath,/home/nico/Desktop/TEMPORARY/homework_02/boost_1_83_0/stage/lib -Ldata_frame_module/ -L/home/nico/Desktop/TEMPORARY/homework_02/boost_1_83_0/stage/lib

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
