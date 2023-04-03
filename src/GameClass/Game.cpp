/*
** EPITECH PROJECT, 2023
** MIRROR-B-OOP-400-NAN-4-1-arcade-andreas.le-tanter [WSL : Ubuntu]
** File description:
** Game
*/

#include "Game.hpp"

/**
 * @brief Construct a new Game
 * @details Create the Game object
*/
Game::Game()
{
}

/**
 * @brief Destroy the Game
 * @details Destroy the Game object
*/
Game::~Game()
{
}

/**
 * @brief Display the Game
 * @details Display the Game
*/
void Game::DisplayGame()
{
    int keypressed = 0;

    while (_ProgramEvents->getCurrentState() == State::GAME) {
        if (_ProgramEvents->getCurrentGameLibrary()->getInstance()->getStatus() == false) {
            keypressed = _ProgramEvents->handleEvents();
            _ProgramEvents->getCurrentGameLibrary()->getInstance()->handleUserInput(keypressed);
            _ProgramEvents->getCurrentGraphicLibrary()->getInstance()->displayObjects(_ProgramEvents->getCurrentGameLibrary()->getInstance()->getObjects());
            _ProgramEvents->getCurrentGraphicLibrary()->getInstance()->displayText(_ProgramEvents->getCurrentUserName(), std::pair<int, int>(1, 1), Enum::Color::WHITE, Enum::Color::BLACK);
            _ProgramEvents->getCurrentGraphicLibrary()->getInstance()->displayScore(_ProgramEvents->getCurrentGameLibrary()->getInstance()->getScore(), 1, 3);
            _ProgramEvents->getCurrentGraphicLibrary()->getInstance()->display();
        } else {
            keypressed = _ProgramEvents->handleEvents();
            _ProgramEvents->getCurrentGameLibrary()->getInstance()->handleUserInput(keypressed);
            _ProgramEvents->getCurrentGraphicLibrary()->getInstance()->displayText("GAME OVER", std::pair<int, int>(100, 25), Enum::Color::RED, Enum::Color::BLACK);
            _ProgramEvents->getCurrentGraphicLibrary()->getInstance()->displayText(_ProgramEvents->getCurrentUserName(), std::pair<int, int>(1, 1), Enum::Color::WHITE, Enum::Color::BLACK);
            _ProgramEvents->getCurrentGraphicLibrary()->getInstance()->displayScore(_ProgramEvents->getCurrentGameLibrary()->getInstance()->getScore(), 1, 3);
            _ProgramEvents->getCurrentGraphicLibrary()->getInstance()->display();
        }
    }
}
