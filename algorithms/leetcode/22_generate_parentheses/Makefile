.DEFAULT:
all: generate_parentheses.o
	g++ -o generate_parentheses generate_parentheses.o

generate_parentheses.o: generate_parentheses.cpp
	g++ -c generate_parentheses.cpp -std=c++11

clean:
	rm generate_parentheses
	rm *.o
