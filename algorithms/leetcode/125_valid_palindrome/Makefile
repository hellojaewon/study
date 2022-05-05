.DEFAULT:
all: valid_palindrome.o
	g++ -o valid_palindrome valid_palindrome.o

valid_palindrome.o: valid_palindrome.cpp
	g++ -c valid_palindrome.cpp -std=c++11

clean:
	rm valid_palindrome
	rm *.o
