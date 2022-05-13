.DEFAULT:
all: reorder_list.o
	g++ -o reorder_list reorder_list.o

reorder_list.o: reorder_list.cpp
	g++ -c reorder_list.cpp -std=c++11

clean:
	rm reorder_list
	rm *.o
