.DEFAULT:
all: insert_interval.o
	g++ -o insert_interval insert_interval.o

insert_interval.o: insert_interval.cpp
	g++ -c insert_interval.cpp -std=c++11

clean:
	rm insert_interval
	rm *.o
