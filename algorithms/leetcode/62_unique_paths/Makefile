.DEFAULT:
all: unique_paths.o
	g++ -o unique_paths unique_paths.o

unique_paths.o: unique_paths.cpp
	g++ -c unique_paths.cpp -std=c++11

clean:
	rm unique_paths
	rm *.o
