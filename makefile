CC = g++ -c -g -fpic

all:
	make UI
	make game_dynamic
	make main_file

main_file: abalone.cpp build/graphic.o build/input.o build/UI.o build/game.o build/functions.o build/move_dynamic.o build/moves.o
	g++ abalone.cpp -lSDL2 -lSDL2_image -lpthread build/graphic.o build/input.o build/UI.o build/game.o build/functions.o build/move_dynamic.o build/moves.o -o ./abalone.out

UI: UI/config.h UI/graphic.cpp UI/graphic.hpp UI/input.cpp UI/input.hpp UI/input-template.cpp UI/UI.cpp UI/UI.hpp
	$(CC) UI/graphic.cpp        -o build/graphic.o
	$(CC) UI/input-template.cpp -o build/input.o
	$(CC) UI/UI.cpp             -o build/UI.o

game_dynamic: game_dynamic/game.cpp game_dynamic/game.hpp game_dynamic/functions.cpp game_dynamic/functions.hpp game_dynamic/move_dynamic.cpp game_dynamic/move_dynamic.hpp game_dynamic/moves.cpp game_dynamic/moves.hpp
	$(CC) game_dynamic/game.cpp        -o build/game.o
	$(CC) game_dynamic/functions.cpp    -o build/functions.o
	$(CC) game_dynamic/move_dynamic.cpp -o build/move_dynamic.o
	$(CC) game_dynamic/moves.cpp        -o build/moves.o
