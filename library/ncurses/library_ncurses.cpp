/*
** EPITECH PROJECT, 2023
** BOOTSTRAP_Arcade [WSL : Ubuntu]
** File description:
** library_ncurses
*/

#include <unistd.h>
#include "library_ncurses.hpp"

extern "C"
{
    IDisplayModule *entryPoint()
    {
        return new LibraryNcurses();
    }
}

LibraryNcurses::LibraryNcurses()
{
    
}

LibraryNcurses::~LibraryNcurses()
{
    
}

void LibraryNcurses::InitWindow()
{
    initscr();
    _CurrentWindow = newwin(0, 0, 0, 0);
    nodelay(_CurrentWindow, true);
    curs_set(0);
    _ColorDefinition[Color::RED] = COLOR_RED;
    _ColorDefinition[Color::GREEN] = COLOR_GREEN;
    _ColorDefinition[Color::BLUE] = COLOR_BLUE;
    _ColorDefinition[Color::YELLOW] = COLOR_YELLOW;
    _ColorDefinition[Color::WHITE] = COLOR_WHITE;
    _ColorDefinition[Color::BLACK] = COLOR_BLACK;

    start_color();
}

void LibraryNcurses::FiniWindow()
{
    delwin(_CurrentWindow);
    endwin();
}

void LibraryNcurses::displayObjects(std::map<int, std::pair<ObjectType, std::pair<int, int>>> _ObjectData)
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

void LibraryNcurses::displayScore(int _Score, int x, int y)
{
    mvwprintw(_CurrentWindow, y, x, "Score: %d", _Score);
    wrefresh(_CurrentWindow);
}

void LibraryNcurses::displayText(std::string _String, std::pair<int, int> _Pos, Color FrontFont, Color BackFont)
{
    idx++;
    init_pair(idx, _ColorDefinition[FrontFont], _ColorDefinition[BackFont]);
    wattron(_CurrentWindow, COLOR_PAIR(idx));
    mvwprintw(_CurrentWindow, _Pos.second, _Pos.first, "%s", _String.c_str());
    wattroff(_CurrentWindow, COLOR_PAIR(idx));
}

const std::string &LibraryNcurses::GetLibType() const
{
    static std::string name = "Graphic";
    return name;
}

std::pair<int, int> LibraryNcurses::GetWindowSize()
{
    return (std::pair<int, int>(_CurrentWindow->_maxx, _CurrentWindow->_maxy));
}

char LibraryNcurses::getUserInput()
{
    return wgetch(_CurrentWindow);
}
