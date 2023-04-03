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
                                          680, 480,
                                          0);
    if(!_CurrentWindow) {
        throw Error("Failed to create the window");
    }
    SDL_SetWindowFullscreen(_CurrentWindow, SDL_WINDOW_FULLSCREEN),
    _CurrentWindowSurface = SDL_GetWindowSurface(_CurrentWindow);
    if(!_CurrentWindowSurface) {
        throw Error("Failed to get the window surface");
    }
    SDL_UpdateWindowSurface(_CurrentWindow);
}

void LibrarySDL::FiniWindow()
{
    // delwin(_CurrentWindow);
    // endwin();
}

void LibrarySDL::displayObjects(std::map<int, std::pair<Enum::ObjectType, std::pair<int, int>>> _ObjectData)
{
    (void)_ObjectData;
    // std::map<Enum::ObjectType, std::string> _ObjectTypeDefinition;
    // _ObjectTypeDefinition[Enum::ObjectType::PLAYER] = "P";
    // _ObjectTypeDefinition[Enum::ObjectType::ENEMY] = "E";
    // _ObjectTypeDefinition[Enum::ObjectType::ITEM] = "I";
    // _ObjectTypeDefinition[Enum::ObjectType::BORDER] = "#";
    // _ObjectTypeDefinition[Enum::ObjectType::PLAYER_PART] = "X";

    // wclear(_CurrentWindow);
    // for (auto &it : _ObjectData) {
    //     mvwprintw(_CurrentWindow, it.second.second.second, it.second.second.first, "%s", _ObjectTypeDefinition[it.second.first].c_str());
    // }
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
    return (std::pair<int, int>(0, 0));
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
    SDL_UpdateWindowSurface(_CurrentWindow);
}
