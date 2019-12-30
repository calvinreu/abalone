#pragma once
#include "../datatypes.hpp"
#include "functions.hpp"

const byte middleLayerLenght = 9;
const byte layerC = 4;//layer count from middle to border
const byte middleLayer = 5;

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
        const tile** begin() const { return const_cast<const tile**>(data)    ; }
        const tile** end()   const { return const_cast<const tile**>(data + 9); }
        tile** begin() { return data    ; }
        tile** end()   { return data + 9; }
};

extern bool on_board(const position &Tile);