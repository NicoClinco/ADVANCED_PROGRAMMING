CXX=g++
CPPFLAGS=-I. -I$(BOOST_PATH)/include
CXXFLAGS=-std=c++17 -Wall -Wpedantic -Werror

SRC=DATA_FRAME.cpp
OBJ_fPIC=$(SRC:.cpp=.shared.o)
DEPS=DATA_FRAME.hpp

LIB_NAME_SHARED=libDataFrame.so

# WE DON'T LINK ANY LIBRARY OF BOOST SINCE HISTOGRAM IS HEADER-ONLY.

all : shared

shared: $(LIB_NAME_SHARED)


$(LIB_NAME_SHARED): $(OBJ_fPIC)
	$(CXX) $(CXXFLAGS) -shared $^ $(LDFLAGS) $(LDLIBS) -o $@

%.shared.o: %.cpp $(DEPS)
	$(CXX) -c -fPIC $(CPPFLAGS) $(CXXFLAGS) $< -o $@

clean:
	rm -f *.o $(LIB_NAME_SHARED)
