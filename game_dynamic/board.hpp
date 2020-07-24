#pragma once
#include "../datatypes.hpp"
#include "functions.hpp"

const int layerCount = 9;
const int middleLayer = (layerCount-1)/2;

enum tile{
    empty = 2,
    player0 = 0,
    player1 = 1
};

class map
{
    private:
        tile* data[9];
    public:
        map();
        tile& operator[](const position &_position){ return data[_position.y][_position.x]; }
        const tile& operator[](const position &_position) const { return data[_position.y][_position.x]; }
        const tile* const* begin() const { return data    ; }
        const tile* const* end()   const { return data + layerCount; }
        tile** begin() { return data    ; }
        tile** end()   { return data + layerCount; }
};

extern bool on_board(const position &Tile);