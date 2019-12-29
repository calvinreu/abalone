CC = g++ -g -c -fpic

all:
	make output
	make input
	make UI

output: graphic.cpp
	$(CC) -lSDL2 -lSDL2_image graphic.cpp -o output.o

input: input.cpp
	$(CC) -lSDL2 input.cpp -o input.o

UI: UI.cpp output.o
	$(CC) -lthread UI.cpp output.o input.o -o UI.o