#include "../UI/UI.hpp"

int main()
{
    game game_info;
    game_info[position{.x=4, .y=4}] = player0;
    game_info[position{.x=3, .y=4}] = player0;
    start_UI(game_info);
    SDL_Quit();
}