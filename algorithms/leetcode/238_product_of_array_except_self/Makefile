.DEFAULT:
all: product_of_array_except_self.o
	g++ -o product_of_array_except_self product_of_array_except_self.o

product_of_array_except_self.o: product_of_array_except_self.cpp
	g++ -c product_of_array_except_self.cpp -std=c++11

clean:
	rm product_of_array_except_self
	rm *.o
