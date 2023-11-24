CXX=g++
CPPFLAGS=-I.
CXXFLAGS=-std=c++17 -Wall -Wpedantic -Werror

DEPS=$(wildcard *.h)
SRC=$(wildcard *.cpp)

OBJ_fPIC=$(SRC:.cpp=.o)

LIB_NAME_SHARED=libParser.so

.PHONY: clean

all : shared
shared : $(LIB_NAME_SHARED)


$(LIB_NAME_SHARED): $(OBJ_fPIC)
	g++ $(CXXFLAGS) -shared $^ -o $@

%.o: %.cpp $(DEPS)
	$(CXX) -c -fPIC $(CPPFLAGS) $(CXXFLAGS) $< -o $@

clean:
	rm -f *.o $(LIB_NAME_SHARED)

