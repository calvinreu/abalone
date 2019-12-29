#define DefBallIMG "../UI/img/ball.png"
#define DefBoardImg "../UI/img/board.png"

#define debug
#include "../bugtracker.hpp"

#include "../datatypes.hpp"
#include "../game dynamic/moves.hpp"
#include "../UI/graphic.hpp"
#include "../UI/graphic.cpp"
#include "../UI/input.hpp"
#include "../UI/input.cpp"

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