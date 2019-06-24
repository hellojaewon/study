.DEFAULT:
all: longest_consecutive_sequence.o
	g++ -o longest_consecutive_sequence longest_consecutive_sequence.o

longest_consecutive_sequence.o: longest_consecutive_sequence.cpp
	g++ -c longest_consecutive_sequence.cpp -std=c++11

clean:
	rm longest_consecutive_sequence
	rm *.o
