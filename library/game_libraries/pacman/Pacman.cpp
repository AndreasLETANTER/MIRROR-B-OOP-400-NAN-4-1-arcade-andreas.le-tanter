/*
** EPITECH PROJECT, 2023
** MIRROR-B-OOP-400-NAN-4-1-arcade-andreas.le-tanter [WSL : Ubuntu]
** File description:
** Pacman
*/

#include "Pacman.hpp"

/**
 * @brief Construct a new Pacman:: Pacman object
*/
extern "C"
{
    IGameEngine *entryPoint()
    {
        return new Pacman();
    }
}

/**
 * @brief handle the user input
 * @details handle the user input and move the player
 * @param key
*/
void Pacman::handleUserInput(char key)
{
    static int x = 10;
    static int y = 20;
    if (key == 'z') {
        y--;
    }
    if (key == 's') {
        y++;
    }
    if (key == 'q') {
        x--;
    }
    if (key == 'd') {
        x++;
    }

    _ObjectData[0] = std::make_pair(Enum::ObjectType::PLAYER, std::make_pair(x,  y));
    _ObjectData[1] = std::make_pair(Enum::ObjectType::ENEMY, std::make_pair(5, 20));
    _ObjectData[3] = std::make_pair(Enum::ObjectType::ITEM, std::make_pair(8, 27));
    _ObjectData[4] = std::make_pair(Enum::ObjectType::ITEM, std::make_pair(10, 25));
}

/**
 * @brief Get the Score object
 * @details Get the score of the player
 * @return int
*/
int Pacman::getScore()
{
    return 0;
}

/**
 * @brief Get the Status object
 * @details Get the status of the game
 * @return true
 * @return false
*/
bool Pacman::getStatus()
{
    return false;
}

/**
 * @brief get the lib type
 * @details get the lib type
 * @return Enum::libType
*/
Enum::libType Pacman::GetLibType()
{
    return Enum::libType::GAME;
}

/**
 * @brief get the objects
 * @details get the objects
 * @return std::map<int, std::pair<Enum::ObjectType, std::pair<int, int>>>
*/
std::map<int, std::pair<Enum::ObjectType, std::pair<int, int>>> Pacman::getObjects()
{
    return _ObjectData;
}
