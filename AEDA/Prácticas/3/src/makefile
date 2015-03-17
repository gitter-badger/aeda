CC = g++
BIN = ../bin/$@
CFLAGS = -std=c++11 -o $(BIN)

all: *.hpp main.cpp
	$(CC) $(CFLAGS) main.cpp

node: node_main.cpp node.hpp
	$(CC) $(CFLAGS) $@_main.cpp

simplelinkedlist: simplelinkedlist_main.cpp simplelinkedlist.hpp node.hpp
	$(CC) $(CFLAGS) $@_main.cpp

vector: vector_main.cpp vector.hpp
	$(CC) $(CFLAGS) $@_main.cpp
	
stack: stack_main.cpp stack.hpp
	$(CC) $(CFLAGS) $@_main.cpp
	
queue: queue_main.cpp queue.hpp
	$(CC) $(CFLAGS) $@_main.cpp

natural: natural_main.cpp natural.hpp number.hpp
	$(CC) $(CFLAGS) $@_main.cpp
	
integer: integer_main.cpp integer.hpp number.hpp
	$(CC) $(CFLAGS) $@_main.cpp
	
rational: rational_main.cpp rational.hpp integer.hpp number.hpp
	$(CC) $(CFLAGS) $@_main.cpp
	
real: real_main.cpp real.hpp
	$(CC) $(CFLAGS) $@_main.cpp

complex: complex_main.cpp complex.hpp
	$(CC) $(CFLAGS) $@_main.cpp

clean:
	rm ../bin/* *~