CXX=g++
CPPFLAGS=-I. -I$(GSL_PATH)/include
CXXFLAGS=-std=c++17 -Wall -Wpedantic -Werror

SRC=Quadrature.cpp
OBJ_fPIC=$(SRC:.cpp=.shared.o)
DEPS=Quadrature.hpp

LIB_NAME_SHARED=libQuadrature.so


LD_FLAGS=-Wl,-rpath,$(GSL_PATH)/lib   \
	 -L$(GSL_PATH)/lib

#LD_LIBS= -lgsl -lgslcblas
LD_LIBS= $(LD_LIBS_QUAD_LIB)

all : shared

shared: $(LIB_NAME_SHARED)


$(LIB_NAME_SHARED): $(OBJ_fPIC)
	$(CXX) $(CXXFLAGS) -shared $^ $(LDFLAGS) $(LDLIBS) -o $@

%.shared.o: %.cpp $(DEPS)
	$(CXX) -c -fPIC $(CPPFLAGS) $(CXXFLAGS) $< -o $@

clean:
	rm -f *.o $(LIB_NAME_SHARED)
