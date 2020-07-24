#include "../bugtracker.hpp"

#include "../UI/UI.hpp"
#include "../global_info.hpp"

int main()
{
    bool running = true;
    start_UI(board, running);
    SDL_Quit();
}