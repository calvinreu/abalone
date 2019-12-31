#pragma once
#include "../datatypes.hpp"
#include "move_dynamic.hpp"
#include "functions.hpp"
#include "board.hpp"
#include <iostream>


struct action
{
    tile player;
    position _position;
    byte ballC;
    direction row_direction;
    direction move_direction;
};

extern inline void straight_empty(const action &_move, const position &last_tile);
extern inline bool straight_full(const action &_move, const position &startEnemyRow);
extern bool move(const action &_move);