CXX=g++
CPPFLAGS=-I. -I/home/nico/Desktop/PHD-COURSES/gls/include
CXXFLAGS=-std=c++17 -Wall -Wpedantic



LDFLAGS=-Wl,-rpath,/home/nico/Desktop/PHD-COURSES/gls/lib \
	-L/home/nico/Desktop/PHD-COURSES/gls/lib
LDLIBS=-lgsl -lgslcblas


SRC=main.cpp
OBJ=$(SRC:.cpp=.o)

all: main

main: $(OBJ)
	$(CXX) $(CXXFLAGS) $^ $(LDFLAGS) $(LDLIBS) -o $@
%.o: %.cpp
	$(CXX) -c $< $(CPPFLAGS) $(CXXFLAGS) -o $@

clean:
	rm -f *.o main
