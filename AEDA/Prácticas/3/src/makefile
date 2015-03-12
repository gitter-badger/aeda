CC = g++
BIN = ../bin/$@
CFLAGS = -std=c++11 -o $(BIN)

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

clean:
	rm ../bin/* *~