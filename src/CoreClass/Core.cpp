/*
** EPITECH PROJECT, 2023
** MIRROR-B-OOP-400-NAN-4-1-arcade-andreas.le-tanter [WSL : Ubuntu]
** File description:
** Core
*/

#include "Core.hpp"

/**
 * @brief Construct a new Core
 * @details Create the Menu and Game object
*/
Core::Core()
{
    _Menu = std::make_shared<Menu>();
    _Game = std::make_shared<Game>();
    _ProgramEvents = std::make_shared<ProgramEvents>();
}

/**
 * @brief Destroy the Core
 * @details Destroy the Menu and Game object
*/
Core::~Core()
{
}

/**
 * @brief Run the Core
 * @details Run the Core
*/
void Core::Run()
{
    while (1) {
        _Menu->setProgramEvents(_ProgramEvents);
        _Menu->DisplayMenu();
        _Game->setProgramEvents(_ProgramEvents);
        _Game->DisplayGame();
    }
}
