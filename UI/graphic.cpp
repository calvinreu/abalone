#include "graphic.hpp"
#include <iostream>

#ifndef DefBallIMG
#define DefBallIMG "./UI/img/ball.png"
#endif
#ifndef DefBoardIMG
#define DefBoardIMG "./UI/img/board.png"
#endif

graphic::graphic()
{
    SDL_Init(SDL_INIT_VIDEO);

    window = SDL_CreateWindow( "abalone", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 100 * 9, 100 * 15, SDL_WINDOW_FULLSCREEN_DESKTOP);

    if(window == NULL)
        std::cout << "Window could not be created! SDL Error: %s\n" << SDL_GetError() << std::endl;
  
    renderer = SDL_CreateRenderer( window, -1, 0 );

    if( renderer == NULL )
        std::cout << "Renderer could not be initialize! SDL Error: %s\n" << SDL_GetError() << std::endl;

    int imgFlags = IMG_INIT_PNG;

    if( !( IMG_Init( imgFlags ) & imgFlags ) )
        std::cout << "SDL_image could not be initialize! SDL Error: %s\n" << SDL_GetError() << std::endl;

    
    ballS = IMG_Load(DefBallIMG);

    if( ballS == NULL )
        std::cout << "unable to load image: %s \n" << DefBallIMG << IMG_GetError() << std::endl;

    boardS = IMG_Load("./UI/img/board.png");

    if( boardS == NULL )
        std::cout << "unable to load image: %s \n" << DefBoardIMG << IMG_GetError() << std::endl;

    ball.LoadFromSurface(ballS, renderer);

    SDL_SetRenderDrawColor(renderer, 0, 0, 200, 255);
}

graphic::~graphic()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);

    SDL_FreeSurface(ballS);
    SDL_FreeSurface(boardS);

    ball.free();

    window = NULL;
    renderer = NULL;

    IMG_Quit();
}

void graphic::new_frame(const position &selected, const byte &ammount, const direction &row_direction, const map &board)
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

    for (auto i = board.begin(); i < board.end(); i++)
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

    position tempTile = selected;

    for (size_t i = 0; i < ammount; i++)
    {
        destRect.x = ((900-((9 -(modulus(tempTile.y - 4))) * 100))/2) + (tempTile.x * 100);
        destRect.y = 300 + (tempTile.y * 100);
        ball.RenderCopy(&selected_ball, &destRect, renderer);
        set_field_index(tempTile, row_direction, 1);
    }

    SDL_RenderPresent(renderer);
}