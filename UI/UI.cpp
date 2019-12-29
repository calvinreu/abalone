#include "UI.hpp"

void start_UI(const map &board, bool &running)
{
    row selected;
    std::thread t_renderer(run_output, board, running, selected);
    //std::thread t_input(run_input, );
}

void run_output(const map &board, const bool &running, const row &selected)
{
    SDL_Init(SDL_INIT_TIMER);
    graphic renderer;
    Uint32 startTime;
    
    while (running)
    {
        startTime = SDL_GetTicks();
        renderer.new_frame(selected.first, selected.ammount, selected.row_direction, board);

        SDL_Delay(frameTime - (SDL_GetTicks()-startTime));
    }    
}

void run_input()