CC = g++

position: ../build/move_dynamic.o move_dynamic.cpp
	$(CC) move_dynamic.cpp ../build/move_dynamic.o -o position.out

UI: input_output.cpp ../build/graphic.o ../build/input.o ../build/UI.o ../build/game.o ../build/functions.o ../build/move_dynamic.o ../build/moves.o
	$(CC) input_output.cpp ../build/graphic.o ../build/input.o ../build/UI.o ../build/game.o ../build/functions.o ../build/move_dynamic.o ../build/moves.o -lSDL2 -lSDL2_image -pthread -o UI.out

game_dynamic: game_dynamic.cpp
	$(CC) -lSDL2 -lSDL2_image game_dynamic.cpp -o game_dynamic.out

output: output.cpp ../UI/UI.o ../game_dynamic/game.o ../game_dynamic/functions.o ../game_dynamic/move_dynamic.o ../UI/output.o
	$(CC) -lSDL2 -lSDL2_image -pthread output.cpp ../UI/UI.o ../game_dynamic/game.o ../game_dynamic/functions.o ../game_dynamic/move_dynamic.o ../UI/output.o -o output.out