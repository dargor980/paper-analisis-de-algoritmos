CXX = g++
CXXFLAGS = -std=c++11 -g3 -Wall
MKDIR = mkdir -p
LIBS = -lm

directorios:
	$(MKDIR) build dist

clean:
	rm -fr *.o a.out build dist

main.o: directorios main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp -o build/main.o

all: clean directorios main.o
	$(CXX) $(CXXFLAGS) -o dist/determinante build/main.o $(LIBS)
	rm -fr build

.DEFAULT_GOAL := all