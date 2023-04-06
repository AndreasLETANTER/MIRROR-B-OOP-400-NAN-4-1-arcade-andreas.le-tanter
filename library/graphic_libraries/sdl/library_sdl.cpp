/*
** EPITECH PROJECT, 2023
** BOOTSTRAP_Arcade [WSL : Ubuntu]
** File description:
** library_ncurses
*/

#include "library_sdl.hpp"
#include "../../../src/ErrorClass/ErrorClass.hpp"
#include "arial.hpp"

/**
 * @brief Entry point of the library
*/
extern "C"
{
    IDisplayModule *entryPoint()
    {
        return new LibrarySDL();
    }
}

/**
 * @brief Init the window
 * @return void
*/
void LibrarySDL::InitWindow()
{
    _CurrentWindow = SDL_CreateWindow("Arcade",
                                          SDL_WINDOWPOS_CENTERED,
                                          SDL_WINDOWPOS_CENTERED,
                                          1920, 1080,
                                          SDL_WINDOW_FULLSCREEN);
    if(!_CurrentWindow) {
        throw Error("Failed to create the window");
    }
    _CurrentWindowRenderer = SDL_CreateRenderer(_CurrentWindow, -1, 0);
    if(!_CurrentWindowRenderer) {
        throw Error("Failed to create the renderer");
    }
    _ColorDefinition[Enum::Color::RED] = SDL_Color{255, 0, 0, 255};
    _ColorDefinition[Enum::Color::GREEN] = SDL_Color{0, 255, 0, 255};
    _ColorDefinition[Enum::Color::BLUE] = SDL_Color{0, 0, 255, 255};
    _ColorDefinition[Enum::Color::YELLOW] = SDL_Color{255, 255, 0, 255};
    _ColorDefinition[Enum::Color::WHITE] = SDL_Color{255, 255, 255, 255};
    _ColorDefinition[Enum::Color::BLACK] = SDL_Color{0, 0, 0, 255};


    _ObjectDefinition[Enum::ObjectType::PLAYER] = SDL_Color{0, 255, 0, 255};
    _ObjectDefinition[Enum::ObjectType::ENEMY] = SDL_Color{255, 0, 0, 255};
    _ObjectDefinition[Enum::ObjectType::ITEM] = SDL_Color{255, 255, 0, 255};
    _ObjectDefinition[Enum::ObjectType::BORDER] = SDL_Color{255, 255, 255, 255};
    _ObjectDefinition[Enum::ObjectType::PLAYER_PART] = SDL_Color{0, 0, 255, 255};

    SDL_SetRenderDrawColor(_CurrentWindowRenderer, BACKGROUND_COLOR);
    SDL_RenderClear(_CurrentWindowRenderer);
}

/**
 * @brief constructor of the library
*/
LibrarySDL::LibrarySDL()
{
    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
        throw Error("Failed to initialize the SDL2 library");
    }
    if (TTF_Init() < 0) {
        throw Error("Failed to initialize the SDL2_ttf library");
    }
    SDL_RWops* rw = SDL_RWFromMem((void*)arial_ttf, arial_ttf_len);
    if (!rw) {
        throw Error("Failed to initialize the font");
    }
    _Font = TTF_OpenFontRW(rw, 1, 28);
}

/**
 * @brief fini the window
 * @return void
*/
void LibrarySDL::FiniWindow()
{
    TTF_CloseFont(_Font);
    TTF_Quit();
    SDL_DestroyWindow(_CurrentWindow);
    SDL_DestroyRenderer(_CurrentWindowRenderer);
    SDL_Quit();
}

/**
 * @brief display the objects
 * @details display the objects on the window
 * @param _ObjectData
 * @return void
*/
void LibrarySDL::displayObjects(std::map<int, std::pair<Enum::ObjectType, std::pair<int, int>>> _ObjectData)
{
    SDL_RenderClear(_CurrentWindowRenderer);

    SDL_Rect rect;
    SDL_Color color;
    rect.w = CHAR_SIZE_X;
    rect.h = CHAR_SIZE_Y;
    for (auto &it : _ObjectData) {
        std::pair<int, int> sdlPos = std::pair<int, int>((_ObjectData[it.first].second.first * CHAR_SIZE_X), (_ObjectData[it.first].second.second * CHAR_SIZE_Y));
        rect.x = sdlPos.first;
        rect.y = sdlPos.second;
        color = _ObjectDefinition[_ObjectData[it.first].first];
        SDL_SetRenderDrawColor(_CurrentWindowRenderer, color.r, color.g, color.b, color.a);
        SDL_RenderFillRect(_CurrentWindowRenderer, &rect);
        SDL_RenderDrawRect(_CurrentWindowRenderer, &rect);
    }
    SDL_SetRenderDrawColor(_CurrentWindowRenderer, BACKGROUND_COLOR);
}

/**
 * @brief display the score
 * @param _Score
 * @param x
 * @param y
 * @return void
*/
void LibrarySDL::displayScore(int _Score, int x, int y)
{
    displayText("Score: " + std::to_string(_Score), std::pair<int, int>(x, y), Enum::Color::WHITE, Enum::Color::BLACK);
}

/**
 * @brief display the text
 * @param _String
 * @param _Pos
 * @param FrontFont
 * @param BackFont
 * @return void
*/
void LibrarySDL::displayText(std::string _String, std::pair<int, int> _Pos, Enum::Color FrontFont, Enum::Color BackFont)
{
    std::pair<int, int> sdlPos = std::pair<int, int>((_Pos.first * CHAR_SIZE_X), (_Pos.second * CHAR_SIZE_Y));
    SDL_Color frontColor = _ColorDefinition[FrontFont];
    SDL_Color backColor;
    SDL_Surface *surface;
    SDL_Texture *texture;
    SDL_Rect rect;

    if (BackFont == Enum::Color::BLACK) {
        backColor = {BACKGROUND_COLOR};
    } else {
        backColor = _ColorDefinition[BackFont];
    }
    surface = TTF_RenderText_Shaded(_Font, _String.c_str(), frontColor, backColor);
    texture = SDL_CreateTextureFromSurface(_CurrentWindowRenderer, surface);
    rect.x = sdlPos.first;
    rect.y = sdlPos.second;
    rect.w = surface->w;
    rect.h = surface->h;
    SDL_RenderCopy(_CurrentWindowRenderer, texture, NULL, &rect);
    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
}

/**
 * @brief get the lib type
 * @return Enum::libType
 * @details return the type of the library
*/
Enum::libType LibrarySDL::GetLibType()
{
    return Enum::GRAPHIC;
}

std::pair<int, int> LibrarySDL::GetWindowSize()
{
    int x = 0;
    int y = 0;

    SDL_GetWindowSize(_CurrentWindow, &x, &y);
    return (std::pair<int, int>(x, y));
}

/**
 * @brief get the user input
 * @return char
 * @details return the user input
*/
char LibrarySDL::getUserInput()
{
    SDL_Event e;
    
    if ((SDL_PollEvent(&e) > 0) && (e.type == SDL_KEYDOWN)) {
        if (e.key.keysym.sym == SDLK_RETURN) {
            return (10);
        }
        return e.key.keysym.sym;
    }
    return -1;
}

/**
 * @brief display the window
*/
void LibrarySDL::display()
{
    SDL_RenderPresent(_CurrentWindowRenderer);
}
