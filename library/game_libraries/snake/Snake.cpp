/*
** EPITECH PROJECT, 2023
** MIRROR-B-OOP-400-NAN-4-1-arcade-andreas.le-tanter [WSL : Ubuntu]
** File description:
** snake
*/

#include "Snake.hpp"

extern "C"
{
    IGameEngine *entryPoint()
    {
        return new Snake();
    }
}

void Snake::CreateBoxCase(int x, int y, int x_length, int y_length)
{
    for (int i = x; i <= x_length + x; i++, last_idx++) {
        _ObjectData[last_idx] = std::make_pair(Enum::ObjectType::BORDER, std::make_pair(i, y));
        last_idx++;
        _ObjectData[last_idx] = std::make_pair(Enum::ObjectType::BORDER, std::make_pair(i, y_length + y));
    }
    for (int i = y; i <= y_length + y; i++, last_idx++) {
        _ObjectData[last_idx] = std::make_pair(Enum::ObjectType::BORDER, std::make_pair(x, i));
        last_idx++;
        _ObjectData[last_idx] = std::make_pair(Enum::ObjectType::BORDER, std::make_pair(x_length + x, i));
    }
}

void Snake::handleUserInput(char key)
{
    (void)key;
    CreateBoxCase(23, 1, 160, 50);
}

int Snake::getScore()
{
    return 0;
}

bool Snake::getStatus()
{
    return false;
}

Enum::libType Snake::GetLibType()
{
    return Enum::libType::GAME;
}

std::map<int, std::pair<Enum::ObjectType, std::pair<int, int>>> Snake::getObjects()
{
    return _ObjectData;
}
