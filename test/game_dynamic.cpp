#define DefBallIMG "../IO/img/ball.png"
#define DefBoardImg "../IO/img/board.png"

#include "../datatypes.hpp"
#include "../game dynamic/moves.hpp"
#include "../IO/graphic.hpp"
#include "../IO/graphic.cpp"
#include <iostream>

graphic output;

int main()
{
    SDL_Init(SDL_INIT_TIMER);
    output.new_frame(position{.x = 0, .y = 0}, 0, null);
    SDL_Delay(500);

    if(!move(action{.player = player0, .xpos = 0, .ypos = 0, .ballC = 1, .row_direction = down_left, .move_direction = down_left}))
        std::cout << "first move";
    
    output.new_frame(position{.x = 0, .y = 0}, 0, null);
    SDL_Delay(1000);

    if(!move(action{.player = player1, .xpos = 0, .ypos = 8, .ballC = 1, .row_direction = up_left, .move_direction = up_left}))
        std::cout << "first move";
    
    output.new_frame(position{.x = 0, .y = 0}, 0, null);
    SDL_Delay(1000);

    SDL_Quit();
}