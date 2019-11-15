#pragma once
#include "../datatypes.hpp"
#include "move_dynamic.hpp"
#include "functions.hpp"
#include "board.hpp"
#include <iostream>

struct action
{
    tile player;
    s_byte xpos;
    s_byte ypos;
    byte ballC;//starts at 0
    direction row_direction;
    direction move_direction;
};


bool move(const action &move_)
{
    if (move_.player == empty)//error handling
    {
        std::cout << "false move command" << std::endl;
        return false;
    }
    

    if(move_.ballC > 2)
        return false;

    position currentTile = {move_.xpos, move_.ypos};

    if(move_.row_direction == move_.move_direction)
    {
        get_field_index(currentTile, move_.move_direction, move_.ballC);

        if(!on_board(currentTile))
            return false;

        if (map[currentTile.y][currentTile.x] == empty)
        {
            map[move_.ypos][move_.xpos] = empty;
            map[currentTile.y][currentTile.x] = move_.player;

            return true;
        }
        else if (map[currentTile.y][currentTile.x] == move_.player)
        {
            return false;
        }
        else
        {
            byte enemyC = 0;
            position enemyRow = currentTile;

            while (true)
            {
                get_field_index(enemyRow, move_.move_direction, 1);

                if (map[enemyRow.y][enemyRow.x] == empty)
                {
                    if (move_.player == player0){
                        map[currentTile.y][currentTile.x] = player0;
                        map[move_.ypos][move_.xpos] = empty;

                        if (on_board(enemyRow))
                            map[enemyRow.y][enemyRow.x] = player1;
                        else
                            lostBallCPlayer1++;
                    }
                    else
                    {
                        map[currentTile.y][currentTile.x] = player1;
                        map[move_.ypos][move_.xpos] = empty;

                        if (on_board(enemyRow))
                            map[enemyRow.y][enemyRow.x] = player0;
                        else
                            lostBallCPlayer0++;
                    }

                    return true;
                    
                }
                else if (map[enemyRow.y][enemyRow.x] == move_.player)
                {
                    return false;
                }
                else
                {
                    enemyC++;

                    if (enemyC == move_.ballC)
                        return false;
                }
            }
        }
    }
    else
    {
        
        get_field_index(currentTile, move_.move_direction, 1);

        if(map[currentTile.y][currentTile.x] == empty)
        {
            for (size_t i = 1; i < move_.ballC; i++)
            {
                get_field_index(currentTile, move_.row_direction, 1);

                if(map[currentTile.y][currentTile.x] != empty)
                    return false;
            }

            if (move_.player == player0)
            {
                currentTile = {move_.xpos, move_.ypos};

                get_field_index(currentTile, move_.move_direction, 1);

                for (size_t i = 1; i < move_.ballC; i++)
                {
                    get_field_index(currentTile, move_.row_direction, 1);
                    map[currentTile.y][currentTile.x] = player0;
                }
            }
            else
            {
                currentTile = {move_.xpos, move_.ypos};

                get_field_index(currentTile, move_.move_direction, 1);

                for (size_t i = 1; i < move_.ballC; i++)
                {
                    get_field_index(currentTile, move_.row_direction, 1);
                    map[currentTile.y][currentTile.x] = player1;
                }
            }        
        }
        else
        {
            return false;
        } 
    }

    std::cout << "movement error" << std::endl;
    return false;
}