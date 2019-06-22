.DEFAULT:
all: repeated_dna_sequences.o
	g++ -o repeated_dna_sequences repeated_dna_sequences.o

repeated_dna_sequences.o: repeated_dna_sequences.cpp
	g++ -c repeated_dna_sequences.cpp -std=c++11

clean:
	rm repeated_dna_sequences
	rm *.o
