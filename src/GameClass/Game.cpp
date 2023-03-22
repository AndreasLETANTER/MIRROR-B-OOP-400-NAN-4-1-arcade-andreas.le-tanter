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

int getScore()
{
    return 0;
}

static std::map<int, std::pair<Enum::ObjectType, std::pair<int, int>>> getObjectsData(int keypressed)
{
    std::map<int, std::pair<Enum::ObjectType, std::pair<int, int>>> _ObjectData;
    static int x = 10;
    static int y = 20;
    if (keypressed == 'z') {
        y--;
    }
    if (keypressed == 's') {
        y++;
    }
    if (keypressed == 'q') {
        x--;
    }
    if (keypressed == 'd') {
        x++;
    }

    _ObjectData[0] = std::make_pair(Enum::ObjectType::PLAYER, std::make_pair(x,  y));
    _ObjectData[1] = std::make_pair(Enum::ObjectType::ENEMY, std::make_pair(5, 20));
    _ObjectData[3] = std::make_pair(Enum::ObjectType::ITEM, std::make_pair(8, 27));
    _ObjectData[4] = std::make_pair(Enum::ObjectType::ITEM, std::make_pair(10, 25));

    return _ObjectData;
}

void Game::DisplayGame()
{
    int keypressed = 0;

    while (_ProgramEvents->getCurrentState() == State::GAME) {
        _ProgramEvents->getCurrentGraphicLibrary()->getInstance()->displayObjects(getObjectsData(keypressed));
        _ProgramEvents->getCurrentGraphicLibrary()->getInstance()->displayText(_ProgramEvents->getCurrentUserName(), std::pair<int, int>(1, 1), Enum::Color::WHITE, Enum::Color::BLACK);
        _ProgramEvents->getCurrentGraphicLibrary()->getInstance()->displayScore(getScore(), 1, 3);
        keypressed = _ProgramEvents->handleEvents();
    }
}
