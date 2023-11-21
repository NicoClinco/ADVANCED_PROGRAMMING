CXX=g++
CPPFLAGS=-I. 
CXXFLAGS=-std=c++17 -Wall -Wpedantic -Werror

SRC=DATA_FRAME.cpp
OBJ_fPIC=$(SRC:.cpp=.shared.o)
DEPS=DATA_FRAME.hpp

LIB_NAME_SHARED=libDataFrame.so

all : shared

shared: $(LIB_NAME_SHARED)


$(LIB_NAME_SHARED): $(OBJ_fPIC)
	$(CXX) $(CXXFLAGS) -shared $^ -o $@

%.shared.o: %.cpp $(DEPS)
	$(CXX) -c -fPIC $(CPPFLAGS) $(CXXFLAGS) $< -o $@

clean:
	rm -f *.o $(LIB_NAME_STATIC) $(LIB_NAME_SHARED)
