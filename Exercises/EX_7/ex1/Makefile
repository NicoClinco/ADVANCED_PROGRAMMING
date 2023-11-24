CXX=g++
PATH_DIR=/u/n/nclinco/Downloads/ADV_PROGRAMMING/ADVANCED_PROGRAMMING/Exercises/EX_7/muparserx-4.0.12/parser
CPPFLAGS=-I$(PATH_DIR)
CXXFLAGS=-std=c++17 -Wall -Wpedantic

LDFLAGS=-Wl,-rpath,$(PATH_DIR) -L$(PATH_DIR) # For dynamic linking.
LDLIBS=-lParser


SRC=ex1.cpp
OBJ=$(SRC:.cpp=.o)

all: main

main: $(OBJ)
	$(CXX) $(CXXFLAGS) $^ $(LDFLAGS) $(LDLIBS) -o $@
%.o: %.cpp
	$(CXX) -c $< $(CPPFLAGS) $(CXXFLAGS) -o $@

clean:
	rm -f *.o main
