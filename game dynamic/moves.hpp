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

inline void straight_empty(const action &_move, const position &last_tile, map &board)
{
    board[_move._position]  = empty;
    board[last_tile] = _move.player;
}

inline bool straight_full(const action &_move, const position &startEnemyRow, map &board)
{
    byte enemyC = 2;
    position currentTile = startEnemyRow;
    while (true)
    {
        set_field_index(currentTile, _move.move_direction, 1);

        if (board[startEnemyRow] == empty)
        {
            board[startEnemyRow] = _move.player;
            board[_move._position] = empty;

            if (_move.player == player0)
            {
                if (on_board(currentTile))
                    board[currentTile] = player1;
                else
                    lostBallCPlayer1++;
            }
            else
            {
                if (on_board(currentTile))
                    board[currentTile] = player0;
                else
                    lostBallCPlayer0++;
            }

            return true;
        }
        else if (board[currentTile] == _move.player)
        {
            return false;//cannot push own balls
        }
        else
        {
            enemyC++;
            if (enemyC > _move.ballC)
                return false;
        }
    }
}

bool move(const action &_move, map &board)
{

    if(_move.ballC > 3)// over free balls
        return false;

    position currentTile = _move._position;

    if(_move.row_direction == _move.move_direction)
    {
        //straight moves
        set_field_index(currentTile, _move.move_direction, (s_byte)_move.ballC);

        if(!on_board(currentTile))
            return false;

        if (board[currentTile] == empty)
        {
            straight_empty(_move, currentTile, board);
            return true;
        }
        else if (board[currentTile] == _move.player)
        {
            return false;//cannot push own balls
        }
        else
        {
            return straight_full(_move, currentTile, board);
        }
    }
    /*else
    {
        
        set_field_index(currentTile, move_.move_direction, 1);

        if(map[currentTile.y][currentTile.x] == empty)
        {
            for (size_t i = 1; i < move_.ballC; i++)
            {
                set_field_index(currentTile, move_.row_direction, 1);

                if(map[currentTile.y][currentTile.x] != empty)
                    return false;
            }

            currentTile = {move_.xpos, move_.ypos};
            set_field_index(currentTile, move_.move_direction, 1);
            for (size_t i = 1; i < move_.ballC; i++)
            {
                set_field_index(currentTile, move_.row_direction, 1);
                map[currentTile.y][currentTile.x] = move_.player;
            }     
        }
        else
        {
            return false;
        } 
    }*/

    std::cout << "movement error" << std::endl;
    return false; 
}