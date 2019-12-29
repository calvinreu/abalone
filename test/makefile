CC = g++

all:
	make output

output: output.cpp
	$(CC) output.cpp -o output.out -lSDL2 -lSDL2_image

UI: input_output.cpp
	$(CC) input_output.cpp -o UI.out -lSDL2 -lSDL2_image

game_dynamic: game_dynamic.cpp
	$(CC) -lSDL2 -lSDL2_image game_dynamic.cpp -o game_dynamic.out