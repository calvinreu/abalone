#define DefBallIMG "../UI/img/ball.png"
#define DefBoardImg "../UI/img/board.png"

#define debug
#include "../bugtracker.hpp"

#include "../global_info.hpp"
#include "../UI/UI.hpp"

graphic output;
bool quit = false;
map board;

int main()
{
    map board;
    bool running;
    auto threads = start_UI(board, running);
    threads.t_input->join();
    threads.t_renderer->join();
    SDL_Quit();
}