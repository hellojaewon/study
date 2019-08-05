.DEFAULT:
all: arithmetic_slices.o
	g++ -o arithmetic_slices arithmetic_slices.o

arithmetic_slices.o: arithmetic_slices.cpp
	g++ -c arithmetic_slices.cpp -std=c++11

clean:
	rm arithmetic_slices
	rm *.o
