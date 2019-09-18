.DEFAULT:
all: encode_and_decode_tinyurl.o
	g++ -o encode_and_decode_tinyurl encode_and_decode_tinyurl.o

encode_and_decode_tinyurl.o: encode_and_decode_tinyurl.cpp
	g++ -c encode_and_decode_tinyurl.cpp -std=c++11

clean:
	rm encode_and_decode_tinyurl
	rm *.o
