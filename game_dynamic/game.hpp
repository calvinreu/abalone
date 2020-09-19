#pragma once
#include "../datatypes.hpp"
#include "functions.hpp"
#include "config.h"

const int layerCount = 9;
const int middleLayer = (layerCount-1)/2;

enum tile{
    empty = 2,
    player0 = 0,
    player1 = 1
};

class game
{
    private:
        tile* board[9];
    public:
        game();
        tile& operator[](const position &_position){ return board[_position.y][_position.x]; }
        const tile& operator[](const position &_position) const { return board[_position.y][_position.x]; }
        const tile* const* begin() const { return board             ; }
        const tile* const* end()   const { return board + layerCount; }
        tile** begin() { return board             ; }
        tile** end()   { return board + layerCount; }
        
        bool running = true;
        tile turn = player0;//which players turn it is
        size_t pointsLostPlayer0 = 0;
        size_t pointsLostPlayer1 = 0;
};

extern bool on_board(const position &Tile);