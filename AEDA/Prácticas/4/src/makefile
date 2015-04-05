CC = g++
BIN = ../bin/$@
CFLAGS = -std=c++11 -o $(BIN)

key: key_main.cpp key.hpp human.hpp key_human.hpp key_human_dni.hpp
	$(CC) $(CFLAGS) $@_main.cpp

human: human_main.cpp human.hpp
	$(CC) $(CFLAGS) $@_main.cpp

clean:
	rm ../bin/* *~