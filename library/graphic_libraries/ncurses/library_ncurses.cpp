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

void LibraryNcurses::InitWindow()
{
    initscr();
    _CurrentWindow = newwin(0, 0, 0, 0);
    nodelay(_CurrentWindow, true);
    curs_set(false);
}

LibraryNcurses::~LibraryNcurses()
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
    _ObjectTypeDefinition[ObjectType::BORDER] = "B";
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

const std::string &LibraryNcurses::GetLibType() const
{
    static std::string name = "Graphic";
    return name;
}