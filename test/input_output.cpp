#define DefBallIMG "../IO/img/ball.png"
#define DefBoardImg "../IO/img/board.png"

#include "../datatypes.hpp"
#include "../game dynamic/moves.hpp"
#include "../IO/graphic.hpp"
#include "../IO/graphic.cpp"
#include "../IO/input.hpp"
#include "../IO/input.cpp"

graphic output;

int main()
{
    SDL_Init(SDL_INIT_EVENTS);

    output.new_frame(position{.x = 0, .y = 0}, 0, null);

    for (size_t i = 0; i < 5; i++)
    {
        handle_input<player0>();
        handle_input<player1>();
    }
    

    SDL_Quit();
}