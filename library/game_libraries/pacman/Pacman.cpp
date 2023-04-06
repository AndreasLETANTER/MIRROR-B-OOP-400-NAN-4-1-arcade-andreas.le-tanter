/*
** EPITECH PROJECT, 2023
** MIRROR-B-OOP-400-NAN-4-1-arcade-andreas.le-tanter [WSL : Ubuntu]
** File description:
** Pacman
*/

#include "Pacman.hpp"
#include <iostream>
#include <fstream>

extern "C"
{
    IGameEngine *entryPoint()
    {
        return new Pacman();
    }
}

Pacman::Pacman()
{
    _Score = 0;
    _is_ended = false;
    createPacman(_PacmanStartPos.first, _PacmanStartPos.second);
    createGhosts();
    createMaze();
    createGums();
}

void Pacman::handleUserInput(char key)
{
    handlePacmanMovement(key);
    handleGhostMovement();
    concatDataMaps();
}

int Pacman::getScore()
{
    return _Score;
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

void Pacman::emptyObjectsData()
{
    _ObjectsData.clear();
    _ObjectIndex = 0;
}

void Pacman::concatDataMaps()
{
    emptyObjectsData();
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

void Pacman::createMaze()
{
    std::string filename = "library/game_libraries/pacman/map_models/map_1.txt";
    std::string line;
    std::ifstream file(filename);
    std::pair <int, int> pos = _MapBorderStartPos;
    int lineCount = 0;

    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        exit(84);
    }
    while (getline(file, line)) {
        for (int i = 0; i < (int)line.length(); i++) {
            if (line[i] == '#') {
                _MazeData[_MazeIndex] = std::make_pair(Enum::ObjectType::BORDER, std::make_pair(pos.first + i, pos.second + lineCount));
                _MazeIndex++;
            }
        }
        lineCount++;
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

void Pacman::createPacman(int x, int y)
{
    _Pacman = std::make_pair(Enum::ObjectType::PLAYER, std::make_pair(x, y));
}

void Pacman::createGhosts()
{
    _GhostSpawnPos = {
        {0, std::make_pair(_GhostSpawnAreaStartPos.first + 2, _GhostSpawnAreaStartPos.second + 1)},
        {1, std::make_pair(_GhostSpawnAreaStartPos.first + 2, _GhostSpawnAreaStartPos.second + 4)},
        {2, std::make_pair(_GhostSpawnAreaStartPos.first + 4, _GhostSpawnAreaStartPos.second + 1)},
        {3, std::make_pair(_GhostSpawnAreaStartPos.first + 4, _GhostSpawnAreaStartPos.second + 4)}
    };
    for (int ghostIndex = 0; ghostIndex < 4; ghostIndex++) {
        _GhostData[ghostIndex] = std::make_pair(Enum::ObjectType::ENEMY, _GhostSpawnPos[ghostIndex]);
    }
}

void Pacman::moveGhostToSpawnAreaExit(int i)
{
    if (_GhostData[i].second.first != _GhostSpawnAreaStartPos.first + 3) {
        if (_GhostData[i].second.first < _GhostSpawnAreaStartPos.first + 3) {
            _GhostData[i].second.first++;
        } else {
            _GhostData[i].second.first--;
        }
    }
    if (_GhostData[i].second.second != _GhostSpawnAreaStartPos.second - 1) {
        if (_GhostData[i].second.second < _GhostSpawnAreaStartPos.second - 1) {
            _GhostData[i].second.second++;
        } else {
            _GhostData[i].second.second--;
        }
    }
}

void Pacman::handleGhostMovement()
{
    if (std::chrono::system_clock::now() >= _GhostTimer) {
        for (int i = 0; i < 4; i++) {
            moveGhostToSpawnAreaExit(i);
        }
    }
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
        case -1:
            handlePacmanMovement(_LastKey);
            return;
        default:
            break;
    }
    checkPacmanCollision(key);
    _LastKey = key;
}

void Pacman::handlePacmanWallCollision(char last_key)
{
    for (int i = 0; i < (int)_MazeData.size(); i++) {
        if (_Pacman.second.first == _MazeData[i].second.first && _Pacman.second.second == _MazeData[i].second.second) {
            switch (last_key) {
                case 'z':
                    _Pacman.second.second += 1;
                    break;
                case 's':
                    _Pacman.second.second -= 1;
                    break;
                case 'd':
                    _Pacman.second.first -= 1;
                    break;
                case 'q':
                    _Pacman.second.first += 1;
                    break;
                default:
                    break;
            }
        }
    }
}

void Pacman::handlePacmanGhostsAreaCollision(void)
{
    if (_Pacman.second.first == _GhostSpawnAreaStartPos.first + 3 && _Pacman.second.second == _GhostSpawnAreaStartPos.second) {
        _Pacman.second.second -= 1;
    }
}

void Pacman::handlePacmanGumCollision()
{
    for (int i = 0; i < (int)_GumData.size(); i++) {
        if (_Pacman.second.first == _GumData[i].second.first && _Pacman.second.second == _GumData[i].second.second) {
            _GumData.erase(i);
            _Score += 10;
        }
    }
}

void Pacman::checkPacmanCollision(char last_key) {
    if (_Pacman.second.first > _MapBorderStartPos.first + (_MapBorderSize.first - 1) - 1) {
        _Pacman.second.first = _MapBorderStartPos.first + 1;
    } else if (_Pacman.second.first < _MapBorderStartPos.first + 1) {
        _Pacman.second.first = _MapBorderStartPos.first + (_MapBorderSize.first - 1) - 1;
    } else if (_Pacman.second.second > _MapBorderStartPos.second + (_MapBorderSize.second - 1) - 1) {
        _Pacman.second.second = _MapBorderStartPos.second + 1;
    } else if (_Pacman.second.second < _MapBorderStartPos.second + 1) {
        _Pacman.second.second = _MapBorderStartPos.second + (_MapBorderSize.second - 1) - 1;
    } else {
        handlePacmanGhostsAreaCollision();
        handlePacmanWallCollision(last_key);
        handlePacmanGumCollision();
    }
}

void Pacman::createGums()
{
    int _GumIndex = 0;

    for (int y = _MapBorderStartPos.second + 2; y < _MapBorderStartPos.second + _MapBorderSize.second - 2; y++) {
        for (int x = _MapBorderStartPos.first + 2; x < _MapBorderStartPos.first + _MapBorderSize.first - 2; x++) {
            if (isEmptySpace(x, y) && ((x < _GhostSpawnAreaStartPos.first || x > _GhostSpawnAreaStartPos.first + 6)
            || (y < _GhostSpawnAreaStartPos.second || y > _GhostSpawnAreaStartPos.second + 5))) {
                _GumData[_GumIndex] = std::make_pair(Enum::ObjectType::ITEM, std::make_pair(x, y));
                _GumIndex++;
            }
        }
    }
}

bool Pacman::isEmptySpace(int x, int y)
{
    for (int i = 0; i < (int)_MazeData.size(); i++) {
        if (_MazeData[i].second.first == x && _MazeData[i].second.second == y) {
            return false;
        }
    }
    return true;
}
