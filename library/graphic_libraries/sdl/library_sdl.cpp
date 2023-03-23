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

void LibrarySDL::InitWindow()
{
    initscr();
    _CurrentWindow = newwin(0, 0, 0, 0);
    keypad(stdscr, TRUE);
    curs_set(0);
    _ColorDefinition[Enum::Color::RED] = COLOR_RED;
    _ColorDefinition[Enum::Color::GREEN] = COLOR_GREEN;
    _ColorDefinition[Enum::Color::BLUE] = COLOR_BLUE;
    _ColorDefinition[Enum::Color::YELLOW] = COLOR_YELLOW;
    _ColorDefinition[Enum::Color::WHITE] = COLOR_WHITE;
    _ColorDefinition[Enum::Color::BLACK] = COLOR_BLACK;

    start_color();
}

void LibrarySDL::FiniWindow()
{
    delwin(_CurrentWindow);
    endwin();
}

void LibrarySDL::displayObjects(std::map<int, std::pair<Enum::ObjectType, std::pair<int, int>>> _ObjectData)
{
    std::map<Enum::ObjectType, std::string> _ObjectTypeDefinition;
    _ObjectTypeDefinition[Enum::ObjectType::PLAYER] = "P";
    _ObjectTypeDefinition[Enum::ObjectType::ENEMY] = "E";
    _ObjectTypeDefinition[Enum::ObjectType::ITEM] = "I";
    _ObjectTypeDefinition[Enum::ObjectType::BORDER] = "#";
    _ObjectTypeDefinition[Enum::ObjectType::PLAYER_PART] = "X";

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

void LibrarySDL::displayText(std::string _String, std::pair<int, int> _Pos, Enum::Color FrontFont, Enum::Color BackFont)
{
    idx++;
    init_pair(idx, _ColorDefinition[FrontFont], _ColorDefinition[BackFont]);
    wattron(_CurrentWindow, COLOR_PAIR(idx));
    mvwprintw(_CurrentWindow, _Pos.second, _Pos.first, "%s", _String.c_str());
    wattroff(_CurrentWindow, COLOR_PAIR(idx));
}

Enum::libType LibrarySDL::GetLibType()
{
    return Enum::GRAPHIC;
}

std::pair<int, int> LibrarySDL::GetWindowSize()
{
    return (std::pair<int, int>(_CurrentWindow->_maxx, _CurrentWindow->_maxy));
}

char LibrarySDL::getUserInput()
{
    return wgetch(_CurrentWindow);
}
