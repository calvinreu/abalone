#include "../UI/UI.hpp"
#include "../game_dynamic/game.hpp"
#include "../global_info.hpp"
#include <SDL2/SDL.h>

extern game game_info;

int main()
{
    row selected;
    bool running;
    SDL_Init(SDL_INIT_VIDEO || SDL_INIT_TIMER);
    run_output(game_info, selected, running);
}