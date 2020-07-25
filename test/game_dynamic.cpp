#define DeforbIMG "../UI/img/orb.png"
#define Defgame_infoImg "../UI/img/game_info.png"

#include "../datatypes.hpp"
#include "../game_dynamic/moves.hpp"
#include "../UI/graphic.hpp"
#include <iostream>

graphic output;

int main()
{
    game game_info;
    SDL_Init(SDL_INIT_TIMER);
    output.new_frame(row{0, position{.x = 0, .y = 0}, null}, game_info);
    SDL_Delay(500);

    if(!move(action{.player = player0, position{.x=0, .y=0}, .orbC = 2, .row_direction = down_left, .move_direction = down_left}))
        std::cout << "first move";
    
    output.new_frame(row{0, position{.x = 0, .y = 0}, null}, game_info);
    SDL_Delay(1000);

    if(!move(action{.player = player1, ._position = position{.x = 0; .y = 8}, .orbC = 2, .row_direction = up_left, .move_direction = up_left}))
        std::cout << "first move";
    #include 

    output.new_frame(row{0, position{.x = 0, .y = 0}, null}, game_info);
    SDL_Delay(1000);

    SDL_Quit();
}