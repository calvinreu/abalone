#pragma once
#include <SDL2/SDL.h>
#include "../game_dynamic/game.hpp"
#include "../game_dynamic/moves.hpp"
#include "../datatypes.hpp"
#include "config.h"

template<const tile player>
extern void mouse_event(position &selected, size_t &ammount, direction &move_direction, direction &row_direction, const pair<int> &cursorPosition, const game &game_info);

template<const tile player>
extern action get_move(const position &first, size_t &ammount, direction &move_direction, direction &row_direction);

template<const tile player>
extern bool handle_input(game &game_info, position &first, size_t &ammount, direction &row_direction);