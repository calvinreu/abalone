#include "moves.hpp"

extern map board;
extern size_t lostorbCPlayer1;
extern size_t lostorbCPlayer0;

inline void straight_empty(const action &_move, const position &last_tile)
{
    board[_move._position]  = empty;
    board[last_tile] = _move.player;
}

inline bool straight_full(const action &_move, const position &startEnemyRow)
{
    size_t enemyC = 1;
    position currentTile = startEnemyRow;
    while (true)
    {
        set_field_index(currentTile, _move.move_direction, 1);

        if (board[currentTile] == empty)
        {
            board[startEnemyRow] = _move.player;
            board[_move._position] = empty;

            if (_move.player == player0)
            {
                if (on_board(currentTile))
                    board[currentTile] = player1;
                else
                    lostorbCPlayer1++;
            }
            else
            {
                if (on_board(currentTile))
                    board[currentTile] = player0;
                else
                    lostorbCPlayer0++;
            }

            return true;
        }
        else if (board[currentTile] == _move.player)
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

bool move(const action &_move)
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

        if (board[currentTile] == empty)
        {
            straight_empty(_move, currentTile);
            return true;
        }
        else if (board[currentTile] == _move.player)
        {
            return false;//cannot push own orbs
        }
        else
        {
            return straight_full(_move, currentTile);
        }
    }
    /*else
    {
        
        set_field_index(currentTile, move_.move_direction, 1);

        if(map[currentTile.y][currentTile.x] == empty)
        {
            for (size_t i = 1; i < move_.orbC; i++)
            {
                set_field_index(currentTile, move_.row_direction, 1);

                if(map[currentTile.y][currentTile.x] != empty)
                    return false;
            }

            currentTile = {move_.xpos, move_.ypos};
            set_field_index(currentTile, move_.move_direction, 1);
            for (size_t i = 1; i < move_.orbC; i++)
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