#pragma once
#include <datatypes.h>
#include "../game_dynamic/board.hpp"

struct row
{
    size_t ammount;
    position first;
    direction row_direction;
};//selected bullets from the first in row direction with ammount