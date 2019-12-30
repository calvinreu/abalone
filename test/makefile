CC = g++

UI: input_output.cpp ../UI/output.o ../UI/input.o ../UI/UI.o ../game_dynamic/board.o ../game_dynamic/functions.o ../game_dynamic/move_dynamic.o
	$(CC) input_output.cpp ../UI/output.o ../UI/input.o ../UI/UI.o ../game_dynamic/board.o ../game_dynamic/functions.o ../game_dynamic/move_dynamic.o -lSDL2 -lSDL2_image -pthread -o UI.out

game_dynamic: game_dynamic.cpp
	$(CC) -lSDL2 -lSDL2_image game_dynamic.cpp -o game_dynamic.out