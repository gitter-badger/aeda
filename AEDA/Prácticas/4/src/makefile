CC = g++
BIN = ../bin/$@
CFLAGS = -std=c++11 -o $(BIN)

key: key_main.cpp key.hpp
	$(CC) $(CFLAGS) $@_main.cpp

clean:
	rm ../bin/* *~