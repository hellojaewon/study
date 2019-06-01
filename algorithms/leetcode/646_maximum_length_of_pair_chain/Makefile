.DEFAULT:
all: maximum_length_of_pair_chain.o
	g++ -o maximum_length_of_pair_chain maximum_length_of_pair_chain.o

maximum_length_of_pair_chain.o: maximum_length_of_pair_chain.cpp
	g++ -c -Werror -Wall maximum_length_of_pair_chain.cpp -std=c++11

clean:
	rm maximum_length_of_pair_chain
	rm *.o
