/*
** EPITECH PROJECT, 2023
** MIRROR-B-OOP-400-NAN-4-1-arcade-andreas.le-tanter [WSL : Ubuntu]
** File description:
** Game
*/

#include "Game.hpp"

Game::Game()
{
}

Game::~Game()
{
}

void Game::DisplayGame()
{
    while (_ProgramEvents->getCurrentState() == State::GAME) {
        std::cout << "Game" << std::endl;
        _ProgramEvents->handleEvents();
    }
}