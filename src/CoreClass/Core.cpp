/*
** EPITECH PROJECT, 2023
** MIRROR-B-OOP-400-NAN-4-1-arcade-andreas.le-tanter [WSL : Ubuntu]
** File description:
** Core
*/

#include "Core.hpp"

Core::Core()
{
    _Menu = std::make_shared<Menu>();
    _Game = std::make_shared<Game>();
    _ProgramEvents = std::make_shared<ProgramEvents>();
}

Core::~Core()
{
}

void Core::Run()
{
    while (1) {
        _Menu->setProgramEvents(_ProgramEvents);
        _Menu->DisplayMenu();
        _Game->setProgramEvents(_ProgramEvents);
        _Game->DisplayGame();
    }
}
