.DEFAULT:
all: top_k_frequent_elements.o
	g++ -o top_k_frequent_elements top_k_frequent_elements.o

top_k_frequent_elements.o: top_k_frequent_elements.cpp
	g++ -c top_k_frequent_elements.cpp -std=c++11

clean:
	rm top_k_frequent_elements
	rm *.o
