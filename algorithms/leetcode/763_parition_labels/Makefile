.DEFAULT:
all: partition_labels.o
	g++ -o partition_labels partition_labels.o

partition_labels.o: partition_labels.cpp
	g++ -c partition_labels.cpp -std=c++11

clean:
	rm partition_labels
	rm *.o
