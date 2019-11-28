#define DefBallIMG "../IO/img/ball.png"
#define DefBoardImg "../IO/img/board.png"

#include "../datatypes.hpp"
#include "../game dynamic/moves.hpp"
#include "../IO/graphic.hpp"
#include "../IO/graphic.cpp"

graphic output;

int main()
{
    SDL_Init(SDL_INIT_EVENTS);


    output.new_frame(position{.x = -10, .y = -10}, 0, null);

    bool b;
    std::cin >> b;

    SDL_Quit();
}