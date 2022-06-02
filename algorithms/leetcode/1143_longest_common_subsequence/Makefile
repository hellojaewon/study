.DEFAULT:
all: longest_common_subsequence.o
	g++ -o longest_common_subsequence longest_common_subsequence.o

longest_common_subsequence.o: longest_common_subsequence.cpp
	g++ -c longest_common_subsequence.cpp -std=c++11

clean:
	rm longest_common_subsequence
	rm *.o
