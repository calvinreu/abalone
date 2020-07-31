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

        if (!on_board(currentTile))
        {
            game_info[startEnemyRow] = _move.player;
            game_info[_move._position] = empty;

            if (_move.player == player0)
                game_info.pointsLostPlayer1++;
            else
                game_info.pointsLostPlayer0++;

            return true;

        }


        if (game_info[currentTile] == empty)
        {
            game_info[startEnemyRow] = _move.player;
            game_info[_move._position] = empty;

            if (_move.player == player0)
                game_info[currentTile] = player1;
            else    
                game_info[currentTile] = player0;

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
        {
            std::cout << "not on board \n";
            return false;
        }

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
    else
    {
        set_field_index(currentTile, _move.move_direction, 1);

        if(game_info[currentTile] == empty)
        {
            for (size_t i = 1; i < _move.orbC; i++)//check if the places for the new orbs are empty
            {
                set_field_index(currentTile, _move.row_direction, 1);

                if(game_info[currentTile] != empty)
                    return false;
            }

            currentTile = _move._position;//put orbs on their new position
            set_field_index(currentTile, _move.move_direction, 1);
            game_info[currentTile] = _move.player;
            for (size_t i = 1; i < _move.orbC; i++)
            {
                set_field_index(currentTile, _move.row_direction, 1);
                game_info[currentTile] = _move.player;
            }

            currentTile = _move._position;//delete the old orbs
            game_info[currentTile] = empty;
            for (size_t i = 0; i < _move.orbC; i++)
            {
                set_field_index(currentTile, _move.row_direction, 1);
                game_info[currentTile] = empty;
            }

            return true; 
        }
        else
        {
            return false;
        } 
    }

    std::cout << "movement error" << std::endl;
    return false; 
}