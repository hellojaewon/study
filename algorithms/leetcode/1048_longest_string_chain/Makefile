.DEFAULT:
all: longest_string_chain.o
	g++ -o longest_string_chain longest_string_chain.o

longest_string_chain.o: longest_string_chain.cpp
	g++ -c longest_string_chain.cpp -std=c++11

clean:
	rm longest_string_chain
	rm *.o
