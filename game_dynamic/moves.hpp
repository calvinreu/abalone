#pragma once
#include "../datatypes.hpp"
#include "move_dynamic.hpp"
#include "functions.hpp"
#include "game.hpp"
#include <iostream>


struct action
{
    tile player;
    position _position;
    size_t orbC;
    direction row_direction;
    direction move_direction;
};

extern inline void straight_empty(game &game_info, const action &_move, const position &last_tile);
extern inline bool straight_full (game &game_info, const action &_move, const position &startEnemyRow);
extern bool move(game &game_info, const action &_move);