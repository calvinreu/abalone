#include "graphic.hpp"
#include <iostream>

graphic::graphic()
{
    SDL_Init(SDL_INIT_VIDEO);

    window = SDL_CreateWindow( "abalone", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 100 * 9, 100 * 15, SDL_WINDOW_VULKAN);

    if(window == NULL)
        std::cout << "Window could not be created! SDL Error: %s\n" << SDL_GetError() << std::endl;
  
    renderer = SDL_CreateRenderer( window, -1, 0 );

    if( renderer == NULL )
        std::cout << "Renderer could not be initialize! SDL Error: %s\n" << SDL_GetError() << std::endl;

    int imgFlags = IMG_INIT_PNG;

    if( !( IMG_Init( imgFlags ) & imgFlags ) )
        std::cout << "SDL_image could not be initialize! SDL Error: %s\n" << SDL_GetError() << std::endl;

    
    ballS = IMG_Load("./IO/img/ball.png");

    if( ballS == NULL )
        std::cout << "unable to load image: %s \n" << "IO/img/ball.png " << IMG_GetError() << std::endl;

    board = IMG_Load("./IO/img/board.png");

    if( board == NULL )
        std::cout << "unable to load image: %s \n" << "IO/img/board.png " << IMG_GetError() << std::endl;

    ball.LoadFromSurface(ballS, renderer);

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
}

graphic::~graphic()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);

    SDL_FreeSurface(ballS);
    SDL_FreeSurface(board);

    ball.free();

    window = NULL;
    renderer = NULL;

    SDL_Quit();
    IMG_Quit();
}

void graphic::new_frame(std::vector<position> selectedBalls)
{
    SDL_RenderClear(renderer);

    byte layerLenght;
    byte layer = 0;
    SDL_Rect destRect = {.x = (900-(lostBallCPlayer0 * 100))/2, .y = 100, .w = 100, .h = 100};


    for (size_t i = 0; i < lostBallCPlayer0; i++)
    {
        ball.RenderCopy(&black_ball, &destRect, renderer);
        destRect.x += 100;
    }
    
    destRect.y = 300;

    for (auto i = map; i < map + 9; i++)
    {
        layerLenght = 9 - modulus(layer - 4);
        destRect.x = (900-(layerLenght * 100))/2;

        for (auto i1 = *i; i1 < *i + layerLenght; i1++)
        {
            switch (*i1)
            {
            case player0:
                ball.RenderCopy(&black_ball, &destRect, renderer);
                break;
            
            case player1:
                std::cout << "player 1";
                ball.RenderCopy(&white_ball, &destRect, renderer);
                break;
            }

            destRect.x += 100;
        }

        destRect.y += 100;
        layer++;
    }

    destRect.x = (900-(lostBallCPlayer1 * 100))/2;

    for (size_t i = 0; i < lostBallCPlayer1; i++)
    {
        ball.RenderCopy(&white_ball, &destRect, renderer);
        destRect.x += 100;
    }

    for (auto i = selectedBalls.begin(); i < selectedBalls.end(); i++)
    {
        destRect.x = (900-(modulus(layer - 4) * 100))/2;
        destRect.y = 300 + (layer * 100);
        ball.RenderCopy(&selected_ball, &destRect, renderer);
    }

    SDL_RenderPresent(renderer);
}