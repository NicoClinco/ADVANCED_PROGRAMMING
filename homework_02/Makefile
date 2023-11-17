CXX=g++
CPPFLAGS=-I./data_frame_module
CXXFLAGS=-std=c++17 -Wall -Wpedantic

LDFLAGS=-Wl,-rpath,data_frame_module/ -Ldata_frame_module/ # For dynamic linking.
LDLIBS=-lDataFrame


SRC=main.cpp
OBJ=$(SRC:.cpp=.o)

all: main

main: $(OBJ)
	$(CXX) $(CXXFLAGS) $^ $(LDFLAGS) $(LDLIBS) -o $@
%.o: %.cpp
	$(CXX) -c $< $(CPPFLAGS) $(CXXFLAGS) -o $@

clean:
	rm -f *.o ex1