.DEFAULT:
all: remove_k_digits.o
	g++ -o remove_k_digits remove_k_digits.o

remove_k_digits.o: remove_k_digits.cpp
	g++ -c remove_k_digits.cpp -std=c++11

clean:
	rm remove_k_digits
	rm *.o
