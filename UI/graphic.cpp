#include "graphic.hpp"

#ifndef DeforbIMG
#define DeforbIMG "./UI/img/orb.png"
#endif
#ifndef DefBoardIMG
#define DefBoardIMG "./UI/img/game_info.png"
#endif

graphic::graphic()
{
    window = SDL_CreateWindow( "abalone", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, windowWidth, windowHeight, SDL_WINDOW_MINIMIZED);

    if(window == NULL)
        std::cout << "Window could not be created! SDL Error: %s\n" << SDL_GetError() << std::endl;
  
    renderer = SDL_CreateRenderer( window, -1, 0 );

    if( renderer == NULL )
        std::cout << "Renderer could not be initialize! SDL Error: %s\n" << SDL_GetError() << std::endl;

    int imgFlags = IMG_INIT_PNG;

    if( !( IMG_Init( imgFlags ) & imgFlags ) )
        std::cout << "SDL_image could not be initialize! SDL Error: %s\n" << SDL_GetError() << std::endl;

    
    orbS = IMG_Load(DeforbIMG);

    if( orbS == NULL )
        std::cout << "unable to load image: %s \n" << DeforbIMG << IMG_GetError() << std::endl;

    boardS = IMG_Load("./UI/img/board.png");

    if( boardS == NULL )
        std::cout << "unable to load image: %s \n" << DefBoardIMG << IMG_GetError() << std::endl;

    orb.LoadFromSurface(orbS, renderer);

    SDL_SetRenderDrawColor(renderer, 0, 0, 200, 255);
}

graphic::~graphic()
{

    orb.free();

    SDL_FreeSurface(orbS);
    SDL_FreeSurface(boardS);
    
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);

    window = NULL;
    renderer = NULL;

    IMG_Quit();
}

void graphic::new_frame(const row &selected, const game &game_info)
{
    SDL_RenderClear(renderer);

    size_t layerLenght;
    size_t layer = 0;
    SDL_Rect destRect = {.x = (layerCount-game_info.pointsLostPlayer0) * orbWidth/2, .y = emptySpace, .w = orbWidth, .h = orbHeight};


    for (size_t i = 0; i < game_info.pointsLostPlayer0; i++)
    {
        orb.RenderCopy(&black_orb, &destRect, renderer);
        destRect.x += orbWidth;
    }
    
    destRect.y = topSpace;//everything above the game_info

    for (auto i = game_info.begin(); i < game_info.end(); i++)
    {
        layerLenght = layerCount - differenceToZero<int>(layer - 4);
        destRect.x = (layerCount-layerLenght)*orbWidth/2;

        for (auto i1 = *i; i1 < *i + layerLenght; i1++)
        {
            if (*i1 == player0)
                orb.RenderCopy(&black_orb, &destRect, renderer);
            else if (*i1 == player1)
                orb.RenderCopy(&white_orb, &destRect, renderer);

            destRect.x += orbWidth;
        }

        destRect.y += orbHeight;
        layer++;
    }

    destRect.x = (layerCount-game_info.pointsLostPlayer1) * orbWidth/2;

    for (size_t i = 0; i < game_info.pointsLostPlayer1; i++)
    {
        orb.RenderCopy(&white_orb, &destRect, renderer);
        destRect.x += orbWidth;
    }

    position tempTile = selected.first;

    for (size_t i = 0; i < selected.ammount; i++)
    {
        destRect.x = (differenceToZero(tempTile.y - middleLayer))*orbWidth/2 + (tempTile.x * orbWidth);
        destRect.y = topSpace + (tempTile.y * orbHeight);
        orb.RenderCopy(&selected_orb, &destRect, renderer);
        set_field_index(tempTile, selected.row_direction, 1);
    }

    SDL_RenderPresent(renderer);
}