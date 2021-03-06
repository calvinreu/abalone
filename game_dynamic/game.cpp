#include "game.hpp"

tile r0[5] = {player0, player0, player0, player0, player0};
tile r1[6] = {player0, player0, player0, player0, player0, player0};
tile r2[7] = {empty, empty, player0, player0, player0, empty, empty};
tile r3[8] = {empty, empty, empty, empty, empty, empty, empty, empty};
tile r4[9] = {empty, empty, empty, empty, empty, empty, empty, empty, empty};
tile r5[8] = {empty, empty, empty, empty, empty, empty, empty, empty};
tile r6[7] = {empty, empty, player1, player1, player1, empty, empty};
tile r7[6] = {player1, player1, player1, player1, player1, player1};
tile r8[5] = {player1, player1, player1, player1, player1};

game::game() : board{r0, r1, r2, r3, r4, r5, r6, r7, r8}{}

bool on_board(const position &Tile)
{
    return Tile.y > -1 && Tile.y < 9 && Tile.x < 9 - differenceToZero(Tile.y - 4) && Tile.x > -1;
}