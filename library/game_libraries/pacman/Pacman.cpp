/*
** EPITECH PROJECT, 2023
** MIRROR-B-OOP-400-NAN-4-1-arcade-andreas.le-tanter [WSL : Ubuntu]
** File description:
** Pacman
*/

#include "Pacman.hpp"
#include <iostream>

extern "C"
{
    IGameEngine *entryPoint()
    {
        return new Pacman();
    }
}

Pacman::Pacman()
{
    _score = 0;
    _is_ended = false;
    createPacman(_PacmanStartPos.first, _PacmanStartPos.second);
}

void Pacman::handleUserInput(char key)
{
    handlePacmanMovement(key);
    createMapBorder(_MapBorderStartPos.first, _MapBorderStartPos.second, _MapBorderSize.first, _MapBorderSize.second);
    createGhostSpawnArea();
    concatDataMaps();
}

int Pacman::getScore()
{
    return 0;
}

bool Pacman::getStatus()
{
    return false;
}

Enum::libType Pacman::GetLibType()
{
    return Enum::libType::GAME;
}

std::map<int, std::pair<Enum::ObjectType, std::pair<int, int>>> Pacman::getObjects()
{
    return _ObjectsData;
}

void Pacman::concatDataMaps()
{
    _DataArrays = {
            _GhostData,
            _GumData,
            _MazeData,
            _MapBorderData,
            _WallData
    };
    for (int arrayIndex = 0; arrayIndex < (int)_DataArrays.size(); arrayIndex++) {
        for (int dataIndex = 0; dataIndex < (int)_DataArrays[arrayIndex].size(); dataIndex++) {
            _ObjectsData[_ObjectIndex] = _DataArrays[arrayIndex][dataIndex];
            _ObjectIndex++;
        }
    }
    _ObjectsData[_ObjectIndex] = _Pacman;
}

void Pacman::createMapBorder(int start_x, int start_y, int width, int height)
{
    for (int x = start_x; x <= start_x + width; x++) {
        _MapBorderData[_MapBorderIndex] = std::make_pair(Enum::ObjectType::BORDER, std::make_pair(x, start_y));
        _MapBorderIndex++;
        _MapBorderData[_MapBorderIndex] = std::make_pair(Enum::ObjectType::BORDER, std::make_pair(x, start_y + height));
        _MapBorderIndex++;
    }
    for (int y = start_y; y < start_y + height; y++) {
        _MapBorderData[_MapBorderIndex] = std::make_pair(Enum::ObjectType::BORDER, std::make_pair(start_x, y));
        _MapBorderIndex++;
        _MapBorderData[_MapBorderIndex] = std::make_pair(Enum::ObjectType::BORDER, std::make_pair(start_x + width, y));
        _MapBorderIndex++;
    }
}

std::map<int, std::pair<Enum::ObjectType, std::pair<int, int>>> Pacman::getMapBorderData()
{
    return _MapBorderData;
}

std::pair<int, int> Pacman::getMapBorderStartPos()
{
    return _MapBorderStartPos;
}

std::pair<int, int> Pacman::getMapBorderSize()
{
    return _MapBorderSize;
}

void Pacman::createGhostSpawnArea()
{
    int wallIndex = 0;
    int width = 6;
    int height = 5;
    int x = _MapBorderStartPos.first + _MapBorderSize.first / 2 - width / 2;
    int y = _MapBorderStartPos.second + _MapBorderSize.second / 2 - height / 2;

    for (int i = x; i <= x + width; i++) {
        if (i != x + width / 2) {
            _WallData[wallIndex] = std::make_pair(Enum::ObjectType::BORDER, std::make_pair(i, y));
            wallIndex++;
        }
        _WallData[wallIndex] = std::make_pair(Enum::ObjectType::BORDER, std::make_pair(i, y + height));
        wallIndex++;
    }
    for (int i = y; i < y + height; i++) {
        _WallData[wallIndex] = std::make_pair(Enum::ObjectType::BORDER, std::make_pair(x, i));
        wallIndex++;
        _WallData[wallIndex] = std::make_pair(Enum::ObjectType::BORDER, std::make_pair(x + width, i));
        wallIndex++;
    }
}

void Pacman::createPacman(int x, int y)
{
    _Pacman = std::make_pair(Enum::ObjectType::PLAYER, std::make_pair(x, y));
}

void Pacman::handlePacmanMovement(char key)
{
    switch (key) {
        case 'z':
            _Pacman.second.second -= 1;
            break;
        case 's':
            _Pacman.second.second += 1;
            break;
        case 'q':
            _Pacman.second.first -= 1;
            break;
        case 'd':
            _Pacman.second.first += 1;
            break;
        default:
            break;
    }
    checkPacmanCollision();
}

void Pacman::checkPacmanCollision(void)
{
    if (_Pacman.second.first > _MapBorderStartPos.first + _MapBorderSize.first - 1)
        _Pacman.second.first = _MapBorderStartPos.first + 1;
    if (_Pacman.second.first < _MapBorderStartPos.first + 1)
        _Pacman.second.first = _MapBorderStartPos.first + _MapBorderSize.first - 1;
    if (_Pacman.second.second > _MapBorderStartPos.second + _MapBorderSize.second - 1)
        _Pacman.second.second = _MapBorderStartPos.second + 1;
    if (_Pacman.second.second < _MapBorderStartPos.second + 1)
        _Pacman.second.second = _MapBorderStartPos.second + _MapBorderSize.second - 1;
}
