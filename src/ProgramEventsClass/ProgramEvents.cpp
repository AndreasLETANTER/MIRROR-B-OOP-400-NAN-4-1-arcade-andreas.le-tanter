/*
** EPITECH PROJECT, 2023
** MIRROR-B-OOP-400-NAN-4-1-arcade-andreas.le-tanter [WSL : Ubuntu]
** File description:
** ProgramEvents
*/

#include "ProgramEvents.hpp"

/**
 * @brief Construct a new Program Events object
*/
ProgramEvents::ProgramEvents()
{
    _Init = new Init("lib/");
    if (_Init->getGraphicalInstances().size() > 0)
        currentGraphicLibrary = _Init->getGraphicalInstances()[0];
    if (_Init->getGamesInstances().size() > 0)
        currentGameLibrary = _Init->getGamesInstances()[0];
    _currentUserName = "UserName: ";

    _keyMap['l'] = [](ProgramEvents *_ProgramEvents) { _ProgramEvents->SwapGraphicLib(); };
    _keyMap['k'] = [](ProgramEvents *_ProgramEvents) { _ProgramEvents->SwapGameLib(); };
    _keyMap['u'] = [](ProgramEvents *_ProgramEvents) { _ProgramEvents->ChangeUserName(); };
    _keyMap['m'] = [](ProgramEvents *_ProgramEvents) { _ProgramEvents->GoToMenu(); };
    _keyMap['g'] = [](ProgramEvents *_ProgramEvents) { _ProgramEvents->GoToGame(); };
    _keyMap['e'] = [](ProgramEvents *_ProgramEvents) { _ProgramEvents->Exit(); };
    _currentState = MENU;
}

/**
 * @brief Destroy the Program Events object
*/
ProgramEvents::~ProgramEvents()
{
}

/**
 * @brief Handle the events
*/
char ProgramEvents::handleEvents()
{
    int keypressed = currentGraphicLibrary->getInstance()->getUserInput();

    if (_keyMap.find(keypressed) != _keyMap.end()) {
        _keyMap[keypressed](this);
    } else {
        return keypressed;
    }
    return 0;
}

/**
 * @brief Swap the current graphic library
*/
void ProgramEvents::SwapGraphicLib()
{
    std::string graphic_name;
    std::string current_graphic_name;
    bool found = false;

    if (currentGraphicLibrary == nullptr) {
        return;
    }
    current_graphic_name = typeid(*currentGraphicLibrary->getInstance()).name();
    for (auto &g : _Init->getGraphicalInstances()) {
        graphic_name = typeid(*g.second->getInstance()).name();
        if (found == true) {
            currentGraphicLibrary->getInstance()->FiniWindow();
            currentGraphicLibrary = g.second;
            currentGraphicLibrary->getInstance()->InitWindow();
            return;
        }
        if (graphic_name == current_graphic_name) {
            found = true;
        }
    }
    if (found == true) {
        currentGraphicLibrary->getInstance()->FiniWindow();
        currentGraphicLibrary = _Init->getGraphicalInstances()[0];
        currentGraphicLibrary->getInstance()->InitWindow();
    }
}

/**
 * @brief Swap the current game library
*/
void ProgramEvents::SwapGameLib()
{
    std::string game_name;
    std::string current_game_name;
    bool found = false;

    if (currentGameLibrary == nullptr) {
        return;
    }
    current_game_name = typeid(*currentGameLibrary->getInstance()).name();
    for (auto &g : _Init->getGamesInstances()) {
        game_name = typeid(*g.second->getInstance()).name();
        if (found == true) {
            currentGameLibrary = g.second;
            return;
        }
        if (game_name == current_game_name) {
            found = true;
        }
    }
    if (found == true) {
        currentGameLibrary = _Init->getGamesInstances()[0];
    }
}

/**
 * @brief Change the current user name
*/
void ProgramEvents::ChangeUserName()
{
    std::string buffer;
    std::cin >> buffer;
    _currentUserName = "UserName: " + buffer;
}

/**
 * @brief Go to the menu
*/
void ProgramEvents::GoToMenu()
{
    currentGraphicLibrary->getInstance()->InitWindow();
    _currentState = MENU;
}

/**
 * @brief Go to the game
*/
void ProgramEvents::GoToGame()
{
    currentGraphicLibrary->getInstance()->FiniWindow();
    currentGraphicLibrary->getInstance()->InitWindow();
    _currentState = GAME;
}

/**
 * @brief Exit the program
*/
void ProgramEvents::Exit()
{
    getCurrentGraphicLibrary()->getInstance()->FiniWindow();
    exit(0);
}
