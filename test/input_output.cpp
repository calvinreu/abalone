#define DefBallIMG "../IO/img/ball.png"
#define DefBoardImg "../IO/img/board.png"

#define debug
#include "../bugtracker.hpp"

#include "../datatypes.hpp"
#include "../game dynamic/moves.hpp"
#include "../IO/graphic.hpp"
#include "../IO/graphic.cpp"
#include "../IO/input.hpp"
#include "../IO/input.cpp"

graphic output;
bool quit = false;
map board;

int main()
{
    SDL_Init(SDL_INIT_EVENTS);

    output.new_frame(position{.x = 0, .y = 0}, 0, null, board);

    while(!quit)
    {
        while(!handle_input<player0>(board)){}
        while(!handle_input<player1>(board)){}
    }
    
    SDL_Quit();
}