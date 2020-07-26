#include "moves.hpp"


inline void straight_empty(game &game_info, const action &_move, const position &last_tile)
{
    game_info[_move._position]  = empty;
    game_info[last_tile] = _move.player;
}

inline bool straight_full(game &game_info, const action &_move, const position &startEnemyRow)
{
    size_t enemyC = 1;
    position currentTile = startEnemyRow;
    while (true)
    {
        set_field_index(currentTile, _move.move_direction, 1);

        if (game_info[currentTile] == empty)
        {
            game_info[startEnemyRow] = _move.player;
            game_info[_move._position] = empty;

            if (_move.player == player0)
            {
                if (on_board(currentTile))
                    game_info[currentTile] = player1;
                else
                    game_info.pointsLostPlayer1++;
            }
            else
            {
                if (on_board(currentTile))
                    game_info[currentTile] = player0;
                else
                    game_info.pointsLostPlayer0++;
            }

            return true;
        }
        else if (game_info[currentTile] == _move.player)
        {
            return false;//cannot push own orbs
        }
        else
        {
            enemyC++;
            if (enemyC > _move.orbC)
                return false;
        }
    }
}

bool move(game &game_info, const action &_move)
{

    if(_move.orbC > 3)// over free orbs
        return false;

    position currentTile = _move._position;

    if(_move.row_direction == _move.move_direction)
    {
        //straight moves
        set_field_index(currentTile, _move.move_direction, _move.orbC);

        if(!on_board(currentTile))
            return false;

        if (game_info[currentTile] == empty)
        {
            straight_empty(game_info, _move, currentTile);
            return true;
        }
        else if (game_info[currentTile] == _move.player)
        {
            return false;//cannot push own orbs
        }
        else
        {
            return straight_full(game_info, _move, currentTile);
        }
    }
    /*else
    {
        
        set_field_index(currentTile, move_.move_direction, 1);

        if(game[currentTile.y][currentTile.x] == empty)
        {
            for (size_t i = 1; i < move_.orbC; i++)
            {
                set_field_index(currentTile, move_.row_direction, 1);

                if(game[currentTile.y][currentTile.x] != empty)
                    return false;
            }

            currentTile = {move_.xpos, move_.ypos};
            set_field_index(currentTile, move_.move_direction, 1);
            for (size_t i = 1; i < move_.orbC; i++)
            {
                set_field_index(currentTile, move_.row_direction, 1);
                game[currentTile.y][currentTile.x] = move_.player;
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