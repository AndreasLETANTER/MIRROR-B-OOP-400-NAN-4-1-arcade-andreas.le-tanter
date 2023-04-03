/*
** EPITECH PROJECT, 2023
** BOOTSTRAP_Arcade [WSL : Ubuntu]
** File description:
** library_ncurses
*/

#include "library_sdl.hpp"
#include "../../../src/ErrorClass/ErrorClass.hpp"

extern "C"
{
    IDisplayModule *entryPoint()
    {
        return new LibrarySDL();
    }
}

void LibrarySDL::InitWindow()
{
    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
        throw Error("Failed to initialize the SDL2 library");
    }
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
    SDL_SetRenderDrawColor(_CurrentWindowRenderer, BACKGROUND_COLOR);
    SDL_RenderClear(_CurrentWindowRenderer);
}

void LibrarySDL::FiniWindow()
{
    SDL_Quit();
}

float UpdateScaleFactor(float _ScaleFactor, std::pair<int, int> _WindowSize, std::pair<int, int> _MapSize)
{
    float scaleFactor = _ScaleFactor;

    if (_MapSize.first * CHAR_SIZE_X * scaleFactor > _WindowSize.first) {
        scaleFactor = _WindowSize.first / (_MapSize.first * CHAR_SIZE_X);
    }
    if (_MapSize.second * CHAR_SIZE_Y * scaleFactor > _WindowSize.second) {
        scaleFactor = _WindowSize.second / (_MapSize.second * CHAR_SIZE_Y);
    }
    return scaleFactor;
}

void LibrarySDL::displayObjects(std::map<int, std::pair<Enum::ObjectType, std::pair<int, int>>> _ObjectData)
{
    (void)_ObjectData;
    SDL_RenderClear(_CurrentWindowRenderer);

    SDL_Rect rect;
    rect.w = CHAR_SIZE_X;
    rect.h = CHAR_SIZE_Y;
    // std::map<Enum::ObjectType, std::string> _ObjectTypeDefinition;
    // _ObjectTypeDefinition[Enum::ObjectType::PLAYER] = "P";
    // _ObjectTypeDefinition[Enum::ObjectType::ENEMY] = "E";
    // _ObjectTypeDefinition[Enum::ObjectType::ITEM] = "I";
    // _ObjectTypeDefinition[Enum::ObjectType::BORDER] = "#";
    // _ObjectTypeDefinition[Enum::ObjectType::PLAYER_PART] = "X";
    // wclear(_CurrentWindow);
    for (auto &it : _ObjectData) {
        float scaleFactor = UpdateScaleFactor(1, GetWindowSize(), _ObjectData[it.first].second);
        std::pair<int, int> sfmlPos = std::pair<int, int>((_ObjectData[it.first].second.first * CHAR_SIZE_X * scaleFactor), (_ObjectData[it.first].second.second * CHAR_SIZE_Y * scaleFactor));
        rect.x = sfmlPos.first;
        rect.y = sfmlPos.second;
        SDL_SetRenderDrawColor(_CurrentWindowRenderer, 255, 255, 255, 255);
        SDL_RenderFillRect(_CurrentWindowRenderer, &rect);
        SDL_RenderDrawRect(_CurrentWindowRenderer, &rect);
        SDL_SetRenderDrawColor(_CurrentWindowRenderer, BACKGROUND_COLOR);
    }
}

void LibrarySDL::displayScore(int _Score, int x, int y)
{
    (void)_Score;
    (void)x;
    (void)y;
    // mvwprintw(_CurrentWindow, y, x, "Score: %d", _Score);
    // wrefresh(_CurrentWindow);
}

void LibrarySDL::displayText(std::string _String, std::pair<int, int> _Pos, Enum::Color FrontFont, Enum::Color BackFont)
{
    (void)_String;
    (void)_Pos;
    (void)FrontFont;
    (void)BackFont;
    // idx++;
    // init_pair(idx, _ColorDefinition[FrontFont], _ColorDefinition[BackFont]);
    // wattron(_CurrentWindow, COLOR_PAIR(idx));
    // mvwprintw(_CurrentWindow, _Pos.second, _Pos.first, "%s", _String.c_str());
    // wattroff(_CurrentWindow, COLOR_PAIR(idx));
}

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

char LibrarySDL::getUserInput()
{
    SDL_Event e;

    if (SDL_PollEvent(&e) > 0)
    {
        return e.key.keysym.sym;
    }
    return -1;
}

void LibrarySDL::display()
{
    SDL_RenderPresent(_CurrentWindowRenderer);
}
