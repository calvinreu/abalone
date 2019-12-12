#include "input.hpp"

extern graphic output;
extern bool quit;

template<const tile player>
void mouse_event(position &selected, byte &ammount, direction &move_direction, direction &row_direction, const pair<int> &cursorPosition, map &board)
{
    position cursorOnBoard;

    cursorOnBoard.y = (cursorPosition.y - 300) / 100;
    cursorOnBoard.x = (cursorPosition.x - ((900 - (9 - modulus(cursorOnBoard.y - 4)) * 100) / 2)) / 100;

    if(ammount == 0)
    {
        if (!on_board(cursorOnBoard))
            return;

        if(board[cursorOnBoard] == player)
        {
            selected = cursorOnBoard;
            ammount++;        
        }
    }
    else
    {
        if(row_direction == null)
        {
            for (direction i = (direction)0; i < null; i = (direction)(i + 1))
            {
                if (get_field_index(selected, i, 1) == cursorOnBoard)
                {
                    row_direction = i;
                    ammount++;
                }
            }
        }
        else
        {
            if(cursorOnBoard == get_field_index(selected, row_direction, ammount))
            {
                if (board[cursorOnBoard] == player)
                    ammount++;
                else
                    move_direction = row_direction;
            }
            else
            {
                if(get_field_index(selected, row_direction, -1) == cursorOnBoard)
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
                }
            }
            
        }
        
    }
}

template<const tile player>
action get_move(const position &selected, const byte &ammount, const direction &move_direction, const direction &row_direction)
{
    action retVal;

    retVal.player         = player        ;
    retVal._position      = selected      ;
    retVal.ballC          = ammount       ;
    retVal.row_direction  = row_direction ;
    retVal.move_direction = move_direction;

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
                mouse_event<player>(selected, ammount, moveDirection, rowDirection, mousePosition, board);
                break;
            case SDL_QUIT:
                quit = true;
                return true;
            }
        }

        output.new_frame(selected, ammount, rowDirection, board);

        if(moveDirection != null)
            return move(get_move<player>(selected, ammount, moveDirection, rowDirection), board);
    }
}