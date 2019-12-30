CC = g++ -g -c -fpic

all:
	make output
	make input
	make UI

output: graphic.cpp
	$(CC) graphic.cpp -o output.o

input: input.cpp
	$(CC) input.cpp -o input.o

UI: UI.cpp
	$(CC) UI.cpp -o UI.o