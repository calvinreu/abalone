#include "input.hpp"

extern graphic output;
extern bool quit;

template<const tile player>
void mouse_event(position &selected, byte &ammount, direction &move_direction, direction &row_direction, const pair<int> &cursorPosition, map &board)
{
    position cursorOnBoard;

    cursorOnBoard.y = (cursorPosition.y - 300) / 100;
    cursorOnBoard.x = (cursorPosition.x - ((900 - (9 - modulus(cursorOnBoard.y - 4)) * 100) / 2)) / 100;

    if (!on_board(cursorOnBoard))
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
                else if(board[cursorOnBoard] == empty)//only move to empty because 1 ball cannot push
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
action get_move(position &selected, byte &ammount, direction &move_direction, direction &row_direction)
{
    action retVal;

    retVal.player         = player        ;
    retVal._position      = selected      ;
    retVal.ballC          = ammount       ;
    retVal.row_direction  = row_direction ;
    retVal.move_direction = move_direction;

    ammount        = 0;
    row_direction  = null;
    move_direction = null;

    return retVal;
}

template<const tile player>
bool handle_input(map &board)
{
    position  selected            ; 
    byte      ammount       = 0   ;
    direction moveDirection = null;
    direction rowDirection  = null;
    pair<int> mousePosition;

    SDL_Event e;

    while (true)
    {
        while(!SDL_PollEvent( &e ))
        {
            switch (e.type)
            {
            case SDL_MOUSEBUTTONDOWN:
                SDL_GetMouseState( &mousePosition.x, &mousePosition.y);
                mouse_event_getinfo_call
                mouse_event<player>(selected, ammount, moveDirection, rowDirection, mousePosition, board);

                render_call
                output.new_frame(selected, ammount, rowDirection, board);

                if(moveDirection != null)
                {
                    movement_call
                    return move(get_move<player>(selected, ammount, moveDirection, rowDirection), board);
                }
                    
                break;
            case SDL_QUIT:
                quit = true;
                return true;
            }
        }
    }
}