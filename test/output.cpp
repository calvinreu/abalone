#define DefBallIMG "../UI/img/ball.png"
#define DefBoardImg "../UI/img/board.png"

#include "../datatypes.hpp"
#include "../game dynamic/moves.hpp"
#include "../UI/graphic.hpp"
#include "../UI/graphic.cpp"

graphic output;

int main()
{
    SDL_Init(SDL_INIT_EVENTS);


    output.new_frame(position{.x = -10, .y = -10}, 0, null);

    bool b;
    std::cin >> b;

    SDL_Quit();
}