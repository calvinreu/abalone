CC = g++ -g -c -fpic

all:
	make board
	make functions
	make move_dynamic

board: board.cpp
	$(CC) board.cpp -o board.o

functions: functions.cpp
	$(CC) functions.cpp -o functions.o

move_dynamic: move_dynamic.cpp
	$(CC) move_dynamic.cpp -o move_dynamic.o