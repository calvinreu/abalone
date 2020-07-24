#include "input.hpp"

template<const tile player>
void mouse_event(position &selected, size_t &ammount, direction &move_direction, direction &row_direction, const pair<int> &cursorPosition, const map &board)
{
    position cursorOnBoard;

    cursorOnBoard.y = (cursorPosition.y - topSpace) / orbHeight;
    cursorOnBoard.x = (cursorPosition.x - ((windowWidth - (layerCount - differenceToZero(cursorOnBoard.y - middleLayer)) * orbWidth) / 2)) / orbWidth;

    std::cout << "cursor x: " << (int)cursorOnBoard.x << " y: " << (int)cursorOnBoard.y << "\n";

    if (!on_board(cursorOnBoard))
        return;

    if(ammount == 3)//needs to be changed to choose a new orb
        return;

    if(ammount == 1)//get direction to the second
    {
        for (direction i = (direction)0; i < null; i = (direction)(i + 1))
        {
            if (get_field_index(selected, i, 1) == cursorOnBoard)
            {
                if(board[cursorOnBoard] == player)
                {
                    row_direction = i;
                    ammount++;
                }
                else if(board[cursorOnBoard] == empty)//only move to empty because 1 orb cannot push
                {
                    row_direction = i;
                    move_direction = i;
                }
                
                return;
            }
        }
    }
    else if(row_direction != null)
    {
        if(cursorOnBoard == get_field_index(selected, row_direction, ammount))//forward move
        {
            if (board[cursorOnBoard] == player)
                ammount++;
            else
                move_direction = row_direction;

            return;
        }
        else if(get_field_index(selected, row_direction, -1) == cursorOnBoard)//backward move
        {
            if(board[cursorOnBoard] == player)
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
            
            return;
        }
    }

    if(board[cursorOnBoard] == player)
    {
        selected = cursorOnBoard;
        ammount = 1;   
        row_direction = null;     
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
bool handle_input(const map &board, bool &running, position &first, size_t &ammount, direction &row_direction)
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
            mouse_event_getinfo_call
            mouse_event<player>(first, ammount, moveDirection, row_direction, mousePosition, board);
            if(moveDirection != null)
            {
                movement_call
                return move(get_move<player>(first, ammount, moveDirection, row_direction));
            }  
            break;

        case SDL_QUIT:
            running = false;
            return true;
        }
    }

    return false;
}