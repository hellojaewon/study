.DEFAULT:
all: interval_list_intersections.o
	g++ -o interval_list_intersections interval_list_intersections.o

interval_list_intersections.o: interval_list_intersections.cpp
	g++ -c interval_list_intersections.cpp -std=c++11

clean:
	rm interval_list_intersections
	rm *.o
