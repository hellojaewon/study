.DEFAULT:
all: find_peak_element.o
	g++ -o find_peak_element find_peak_element.o

find_peak_element.o: find_peak_element.cpp
	g++ -c find_peak_element.cpp -std=c++11

clean:
	rm find_peak_element
	rm *.o
