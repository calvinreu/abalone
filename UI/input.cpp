#include "input.hpp"

template<const tile player>
void mouse_event(position &selected, size_t &ammount, direction &move_direction, direction &row_direction, const pair<int> &cursorPosition, const game &game_info)
{
    position cursorOnBoard;

    cursorOnBoard.y = (cursorPosition.y - topSpace) / orbHeight;
    cursorOnBoard.x = (cursorPosition.x - ((windowWidth - (layerCount - differenceToZero(cursorOnBoard.y - middleLayer)) * orbWidth) / 2)) / orbWidth;

    if (!on_board(cursorOnBoard))
        return;

    if(ammount == 1)//get direction to the second
    {
        for (direction i = (direction)0; i < null; i = (direction)(i + 1))
        {
            if (get_field_index(selected, i, 1) == cursorOnBoard)
            {
                if(game_info[cursorOnBoard] == player)
                {
                    row_direction = i;
                    ammount++;
                }
                else if(game_info[cursorOnBoard] == empty)//only move one orb to empty field
                {
                    row_direction = i;
                    move_direction = i;
                }
                else
                {
                    row_direction = null;
                    ammount = 0;
                    move_direction = null;
                }
                
                return;
            }
        }

        row_direction = null;
        ammount = 0;
        move_direction = null;

    }
    else if(row_direction != null)
    {
        if(cursorOnBoard == get_field_index(selected, row_direction, ammount))//forward move
        {
            if (game_info[cursorOnBoard] == player && ammount < 3)
                ammount++;
            else
                move_direction = row_direction;

            return;
        }
        else if(get_field_index(selected, opposite_direction(row_direction), 1) == cursorOnBoard)//backward move
        {
            if(game_info[cursorOnBoard] == player)
            {
                selected = cursorOnBoard;
                ammount++;        
            }
            else
            {
                set_field_index(selected, row_direction, ammount -1);
                row_direction = opposite_direction(row_direction);
                move_direction = row_direction;
            }

            return;
        }
        else
        {

            for (auto i = right; i < null; i = (direction)(i + 1))
                if (get_field_index(selected, i, 1) == cursorOnBoard)
                {
                    move_direction = i;
                    return;
                }
            

            row_direction  = null;
            move_direction = null;
            ammount = 0;

            return;
        }
    }

    if(game_info[cursorOnBoard] == player)
    {
        selected = cursorOnBoard;
        ammount = 1;   
        row_direction = null;
        move_direction = null;
    }
}

template<const tile player>
action get_move(const position &first, size_t &ammount, direction &move_direction, direction &row_direction)
{
    action retVal;

    retVal.player         = player        ;
    retVal._position      = first         ;
    retVal.orbC          = ammount       ;
    retVal.row_direction  = row_direction ;
    retVal.move_direction = move_direction;

    ammount        = 0;
    row_direction  = null;
    move_direction = null;

    return retVal;
}

template<const tile player>
bool handle_input(game &game_info, position &first, size_t &ammount, direction &row_direction)
{
    direction moveDirection = null;
    pair<int> mousePosition;
    SDL_Event e;

    while(!SDL_PollEvent( &e ))
    {
        switch (e.type)
        {
        case SDL_MOUSEBUTTONDOWN:
            SDL_GetMouseState( &mousePosition.x, &mousePosition.y);
            mouse_event<player>(first, ammount, moveDirection, row_direction, mousePosition, game_info);
            if(moveDirection != null)
            {
                std::cout << moveDirection << "\n";
                return move(game_info, get_move<player>(first, ammount, moveDirection, row_direction));
            }
            SDL_Delay(inputDelayTime);
            break;

        case SDL_QUIT:
            game_info.running = false;
            return true;
        }
    }

    return false;
}