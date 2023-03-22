/*
** EPITECH PROJECT, 2023
** BOOTSTRAP_Arcade [WSL : Ubuntu]
** File description:
** library_ncurses
*/

#include <unistd.h>
#include "library_sdl.hpp"

extern "C"
{
    IDisplayModule *entryPoint()
    {
        return new LibrarySDL();
    }
}

LibrarySDL::LibrarySDL()
{
    
}

LibrarySDL::~LibrarySDL()
{
    
}

void LibrarySDL::InitWindow()
{
    initscr();
    _CurrentWindow = newwin(0, 0, 0, 0);
    keypad(stdscr, TRUE);
    curs_set(0);
    _ColorDefinition[Color::RED] = COLOR_RED;
    _ColorDefinition[Color::GREEN] = COLOR_GREEN;
    _ColorDefinition[Color::BLUE] = COLOR_BLUE;
    _ColorDefinition[Color::YELLOW] = COLOR_YELLOW;
    _ColorDefinition[Color::WHITE] = COLOR_WHITE;
    _ColorDefinition[Color::BLACK] = COLOR_BLACK;

    start_color();
}

void LibrarySDL::FiniWindow()
{
    delwin(_CurrentWindow);
    endwin();
}

void LibrarySDL::displayObjects(std::map<int, std::pair<ObjectType, std::pair<int, int>>> _ObjectData)
{
    std::map<ObjectType, std::string> _ObjectTypeDefinition;
    _ObjectTypeDefinition[ObjectType::PLAYER] = "P";
    _ObjectTypeDefinition[ObjectType::ENEMY] = "E";
    _ObjectTypeDefinition[ObjectType::ITEM] = "I";
    _ObjectTypeDefinition[ObjectType::BORDER] = "#";
    _ObjectTypeDefinition[ObjectType::PLAYER_PART] = "X";

    wclear(_CurrentWindow);
    for (auto &it : _ObjectData) {
        mvwprintw(_CurrentWindow, it.second.second.second, it.second.second.first, "%s", _ObjectTypeDefinition[it.second.first].c_str());
    }
}

void LibrarySDL::displayScore(int _Score, int x, int y)
{
    mvwprintw(_CurrentWindow, y, x, "Score: %d", _Score);
    wrefresh(_CurrentWindow);
}

void LibrarySDL::displayText(std::string _String, std::pair<int, int> _Pos, Color FrontFont, Color BackFont)
{
    idx++;
    init_pair(idx, _ColorDefinition[FrontFont], _ColorDefinition[BackFont]);
    wattron(_CurrentWindow, COLOR_PAIR(idx));
    mvwprintw(_CurrentWindow, _Pos.second, _Pos.first, "%s", _String.c_str());
    wattroff(_CurrentWindow, COLOR_PAIR(idx));
}

const std::string &LibrarySDL::GetLibType() const
{
    static std::string name = "Graphic";
    return name;
}

std::pair<int, int> LibrarySDL::GetWindowSize()
{
    return (std::pair<int, int>(_CurrentWindow->_maxx, _CurrentWindow->_maxy));
}

char LibrarySDL::getUserInput()
{
    return wgetch(_CurrentWindow);
}