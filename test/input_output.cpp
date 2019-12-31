#define DefBallIMG "../UI/img/ball.png"
#define DefBoardImg "../UI/img/board.png"

#define debug
#include "../bugtracker.hpp"

#include "../UI/UI.hpp"
#include "../global_info.hpp"

int main()
{
    bool running;
    auto threads = start_UI(board, running);
    threads.t_input->join();
    threads.t_renderer->join();
    SDL_Quit();
}