.DEFAULT:
all: validate_stack_sequences.o
	g++ -o validate_stack_sequences validate_stack_sequences.o

validate_stack_sequences.o: validate_stack_sequences.cpp
	g++ -c validate_stack_sequences.cpp -std=c++11

clean:
	rm validate_stack_sequences
	rm *.o
