#include "UI.hpp"

extern const Uint32 frameTime;

void start_UI(map &board, bool &running)
{
    SDL_Init(SDL_INIT_VIDEO || SDL_INIT_TIMER || SDL_INIT_EVENTS);
    row selected = {.ammount = 0, .row_direction = null};

    std::thread tGraphic(run_output, std::ref(board), std::ref(selected), std::ref(running));
    run_input(board, selected, running);
    tGraphic.join();
}

void run_UI(const map &board, bool &running)
{
    graphic renderer;
    Uint32 startTime;
    row selected = {.ammount = 0, .row_direction = null};
    bool finished;

    while (running)
    {
        finished = false;
        while (!finished)
        {
            //startTime = SDL_GetTicks();
            finished = handle_input<player0>(board, running, selected.first, selected.ammount, selected.row_direction);
            //renderer.new_frame(selected, board);
            //if( SDL_GetTicks()-startTime < frameTime )
            //    SDL_Delay(frameTime - (SDL_GetTicks()-startTime));
        }
        finished = false;
        while (!finished)
        {
            //startTime = SDL_GetTicks();
            finished = handle_input<player1>(board, running, selected.first, selected.ammount, selected.row_direction);
            //renderer.new_frame(selected, board);
            //SDL_Delay(frameTime - (SDL_GetTicks()-startTime));
        }
    }
}

void run_input(map &board, row &selected, bool &running)
{
    while(running)
    {
        while(!handle_input<player0>(board, running, selected.first, selected.ammount, selected.row_direction));
        while(!handle_input<player1>(board, running, selected.first, selected.ammount, selected.row_direction));
    }
}

void run_output(const map &board, const row &selected, const bool &running)
{
    graphic output;
    Uint32 startTime;
    size_t i = 0;

    while (running)
    {
        startTime = SDL_GetTicks();
        output.new_frame(selected, board);
        std::cout << "x: " << (int)selected.first.x << " y: " << (int)selected.first.y << "\n";
        std::cout << "selected.ammount: " << selected.ammount << "\n";
        std::cout << "selected.direction: " << selected.row_direction << "\n";
        SDL_Delay(frameTime - (SDL_GetTicks()-startTime));
    }
}