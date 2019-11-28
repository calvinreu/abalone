#pragma once
#include "../datatypes.hpp"
#include "functions.hpp"

const byte middleLayerLenght = 9;
const byte layerC = 4;//layer count from middle to border
const byte middleLayer = 5;

byte lostBallCPlayer0 = 0;
byte lostBallCPlayer1 = 0;

enum tile{
    empty = 2,
    player0 = 0,
    player1 = 1
};



tile r0[5] = {player0, player0, player0, player0, player0};
tile r1[6] = {player0, player0, player0, player0, player0, player0};
tile r2[7] = {empty, empty, player0, player0, player0, empty, empty};
tile r3[8] = {empty, empty, empty, empty, empty, empty, empty, empty};
tile r4[9] = {empty, empty, empty, empty, empty, empty, empty, empty, empty};
tile r5[8] = {empty, empty, empty, empty, empty, empty, empty, empty};
tile r6[7] = {empty, empty, player1, player1, player1, empty, empty};
tile r7[6] = {player1, player1, player1, player1, player1, player1};
tile r8[5] = {player1, player1, player1, player1, player1};

tile* map[9] = {r0, r1, r2, r3, r4, r5, r6, r7, r8};



bool on_board(const position &Tile)
{
    return Tile.y > -1 && Tile.y < 9 && Tile.x < 9 - modulus(Tile.y - 4) && Tile.x > -1;
}