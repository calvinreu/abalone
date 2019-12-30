#include "UI.hpp"

void start_UI(const map &board, bool &running)
{
    row selected;
    std::thread t_renderer(run_output, std::ref(board), std::ref(running), std::ref(selected));
    std::thread t_input(run_input, std::ref(board), std::ref(running), std::ref(selected));
    t_renderer.detach();
    t_input.detach();
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

void run_input(const map &board, bool &running, row &selected)
{
    while (running)
    {
        while (!handle_input<player0>(board, running, selected.first, selected.ammount, selected.row_direction)){}
        while (!handle_input<player0>(board, running, selected.first, selected.ammount, selected.row_direction)){}
    }
}