#pragma once
#include "../datatypes.hpp"
#include "game.hpp"

enum direction
{
    up_left = 2,
    up_right = 3,
    right = 0,
    down_right = 4,
    down_left = 5,
    left = 1,
    null = 6
    
};

extern void set_field_index(position &field, const direction &change, const size_t &ammount);
extern position get_field_index(const position &field, const direction &change, const size_t &ammount);
extern direction opposite_direction(const direction &first);