#pragma once
#include <SDL2/SDL.h>
#include "../game dynamic/board.hpp"
#include "../game dynamic/moves.hpp"
#include "../datatypes.hpp"

template<const tile player>
extern void mouse_event(position &selected, byte &ammount, direction &move_direction, direction &row_direction, const pair<int> &cursorPosition, const map &board);

template<const tile player>
extern action get_move(const position &selected, const byte &ammount, const direction &move_direction, const direction &row_direction);

template<const tile player>
extern bool handle_input(const map &board, bool &running, position &first, byte &ammount, direction &row_direction);