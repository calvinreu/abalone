#include "../UI/UI.hpp"
#include "../game_dynamic/board.hpp"
#include "../global_info.hpp"
#include <SDL2/SDL.h>

extern map board;

int main()
{
    row selected;
    bool running;
    SDL_Init(SDL_INIT_VIDEO || SDL_INIT_TIMER);
    run_output(board, running, selected);
}