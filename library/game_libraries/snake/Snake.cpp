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

Snake::Snake()
{
    _score = 0;
    _is_ended = false;
    _ObjectData[last_idx] = std::make_pair(Enum::ObjectType::PLAYER, std::make_pair(100, 25));
    last_idx++;
    CreateBoxCase(23, 1, 160, 50);
    for (int i =0; i < 5; i++)
        GenerateFruit();
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

void Snake::handlePlayerMovement(char key)
{
    if (key == 'z' && _ObjectData[0].second.second > 1 + 1)
        _ObjectData[0].second.second -= 1;
    if (key == 's' && _ObjectData[0].second.second < 50 + 1 - 1)
        _ObjectData[0].second.second += 1;
    if (key == 'q' && _ObjectData[0].second.first > 23 + 1)
        _ObjectData[0].second.first -= 1;
    if (key == 'd' && _ObjectData[0].second.first < 160 + 23 - 1)
        _ObjectData[0].second.first += 1;
}

void Snake::GenerateFruit()
{
    int x = rand() % 160 + 23;
    int y = rand() % 50 + 1;
    _ObjectData[last_idx] = std::make_pair(Enum::ObjectType::ITEM, std::make_pair(x, y));
    last_idx++;
}

void Snake::handleUserInput(char key)
{
    (void)key;
    handlePlayerMovement(key);
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
