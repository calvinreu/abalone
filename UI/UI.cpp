#include "UI.hpp"

extern const Uint32 frameTime;

void start_UI(game &game_info)
{
    SDL_Init(SDL_INIT_VIDEO || SDL_INIT_TIMER || SDL_INIT_EVENTS);
    row selected = {.ammount = 0, .row_direction = null};

    std::thread tGraphic(run_output, std::ref(game_info), std::ref(selected));
    run_input(game_info, selected);
    tGraphic.join();
}

void run_input(game &game_info, row &selected)
{
    while(game_info.running)
    {
        while(!handle_input<player0>(game_info, selected.first, selected.ammount, selected.row_direction));
        while(!handle_input<player1>(game_info, selected.first, selected.ammount, selected.row_direction));
    }
}

void run_output(const game &game_info, const row &selected)
{
    graphic output;
    Uint32 startTime;
    size_t i = 0;

    while (game_info.running)
    {
        startTime = SDL_GetTicks();
        output.new_frame(selected, game_info);
        SDL_Delay(frameTime - (SDL_GetTicks()-startTime));
    }
}