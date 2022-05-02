.DEFAULT:
all: longest_increasing_subsequence.o
	g++ -o longest_increasing_subsequence longest_increasing_subsequence.o

longest_increasing_subsequence.o: longest_increasing_subsequence.cpp
	g++ -c longest_increasing_subsequence.cpp -std=c++11

clean:
	rm longest_increasing_subsequence
	rm *.o
