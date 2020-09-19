#include "game.hpp"

game::game() : board{r0, r1, r2, r3, r4, r5, r6, r7, r8}{}

bool on_board(const position &Tile)
{
    return Tile.y > -1 && Tile.y < 9 && Tile.x < 9 - differenceToZero(Tile.y - 4) && Tile.x > -1;
}