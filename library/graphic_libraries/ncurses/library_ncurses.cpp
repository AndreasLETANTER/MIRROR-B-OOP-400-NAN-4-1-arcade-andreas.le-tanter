/*
** EPITECH PROJECT, 2023
** BOOTSTRAP_Arcade [WSL : Ubuntu]
** File description:
** library_ncurses
*/

#include <unistd.h>
#include "library_ncurses.hpp"

/**
 * @brief Entry point of the library
*/
extern "C"
{
    IDisplayModule *entryPoint()
    {
        return new LibraryNcurses();
    }
}

/**
 * @brief Init the window
 * @return void
*/
void LibraryNcurses::InitWindow()
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
    noecho();
    start_color();
}

/**
 * @brief fini the window
 * @return void
*/
void LibraryNcurses::FiniWindow()
{
    delwin(_CurrentWindow);
    endwin();
}

/**
 * @brief display the objects
 * @details display the objects on the screen
 * @param _ObjectData
 * @return void
*/
void LibraryNcurses::displayObjects(std::map<int, std::pair<Enum::ObjectType, std::pair<int, int>>> _ObjectData)
{
    std::map<Enum::ObjectType, std::string> _ObjectTypeDefinition;
    _ObjectTypeDefinition[Enum::ObjectType::PLAYER] = "P";
    _ObjectTypeDefinition[Enum::ObjectType::ENEMY] = "E";
    _ObjectTypeDefinition[Enum::ObjectType::ITEM] = "I";
    _ObjectTypeDefinition[Enum::ObjectType::BORDER] = "#";
    _ObjectTypeDefinition[Enum::ObjectType::PLAYER_PART] = "X";

    werase(_CurrentWindow);
    for (auto &it : _ObjectData) {
        mvwprintw(_CurrentWindow, it.second.second.second, it.second.second.first, "%s", _ObjectTypeDefinition[it.second.first].c_str());
    }
}

/**
 * @brief display the score
 * @details display the score on the screen
 * @param _Score
 * @param x
 * @param y
 * @return void
*/
void LibraryNcurses::displayScore(int _Score, int x, int y)
{
    mvwprintw(_CurrentWindow, y, x, "Score: %d", _Score);
}

/**
 * @brief display the text
 * @details display the text on the screen
 * @param _String
 * @param _Pos
 * @param FrontFont
 * @param BackFont
 * @return void
*/
void LibraryNcurses::displayText(std::string _String, std::pair<int, int> _Pos, Enum::Color FrontFont, Enum::Color BackFont)
{
    int contains = _KnownColors.count(std::pair<Enum::Color, Enum::Color>(FrontFont, BackFont));
    int custom_idx = _KnownColors[std::pair<Enum::Color, Enum::Color>(FrontFont, BackFont)];

    if (contains == 0) {
        init_pair(idx, _ColorDefinition[FrontFont], _ColorDefinition[BackFont]);
        wattron(_CurrentWindow, COLOR_PAIR(idx));
        mvwprintw(_CurrentWindow, _Pos.second, _Pos.first, "%s", _String.c_str());
        wattroff(_CurrentWindow, COLOR_PAIR(idx));
        _KnownColors[std::pair<Enum::Color, Enum::Color>(FrontFont, BackFont)] = idx;
        idx++;
    } else {
        wattron(_CurrentWindow, COLOR_PAIR(custom_idx));
        mvwprintw(_CurrentWindow, _Pos.second, _Pos.first, "%s", _String.c_str());
        wattroff(_CurrentWindow, COLOR_PAIR(custom_idx));
    }
}

/**
 * @brief get the lib type
*/
Enum::libType LibraryNcurses::GetLibType() 
{
    return Enum::libType::GRAPHIC;
}

/**
 * @brief get the window size
*/
std::pair<int, int> LibraryNcurses::GetWindowSize()
{
    return (std::pair<int, int>(_CurrentWindow->_maxx, _CurrentWindow->_maxy));
}

/**
 * @brief get the user input
*/
char LibraryNcurses::getUserInput()
{
    nodelay(_CurrentWindow, TRUE);
    return wgetch(_CurrentWindow);
}

/**
 * @brief display the window
*/
void LibraryNcurses::display()
{
    wrefresh(_CurrentWindow);
}
