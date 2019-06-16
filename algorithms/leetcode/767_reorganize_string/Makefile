.DEFAULT:
all: reorganize_string.o
	g++ -o reorganize_string reorganize_string.o

reorganize_string.o: reorganize_string.cpp
	g++ -c reorganize_string.cpp -std=c++11

clean:
	rm reorganize_string
	rm *.o
