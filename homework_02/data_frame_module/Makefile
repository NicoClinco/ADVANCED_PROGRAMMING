CXX=g++
CPPFLAGS=-I. -I/u/n/nclinco/Downloads/ADV_PROGRAMMING/boost/include
CXXFLAGS=-std=c++17 -Wall -Wpedantic -Werror

SRC=DATA_FRAME.cpp
OBJ_fPIC=$(SRC:.cpp=.shared.o)
DEPS=DATA_FRAME.hpp

LIB_NAME_SHARED=libDataFrame.so

LD_FLAGS=-Wl,-rpath,/u/n/nclinco/Downloads/ADV_PROGRAMMING/boost/lib \
		 -L/u/n/nclinco/Downloads/ADV_PROGRAMMING/boost/lib

all : shared

shared: $(LIB_NAME_SHARED)


$(LIB_NAME_SHARED): $(OBJ_fPIC)
	$(CXX) $(CXXFLAGS) -shared $^ $(LDFLAGS) $(LDLIBS) -o $@

%.shared.o: %.cpp $(DEPS)
	$(CXX) -c -fPIC $(CPPFLAGS) $(CXXFLAGS) $< -o $@

clean:
	rm -f *.o $(LIB_NAME_SHARED)
