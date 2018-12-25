.DEFAULT:
all: longest_common_prefix.o
	g++ -o longest_common_prefix longest_common_prefix.o

longest_common_prefix.o: longest_common_prefix.cpp
	g++ -c longest_common_prefix.cpp -std=c++11

clean:
	rm longest_common_prefix
	rm *.o
