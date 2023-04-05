/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** handle Pacman
*/

#pragma once

#include "../IGameEngine.hpp"
#include "../../ILibrary.hpp"
#include <vector>
#include <chrono>

class Pacman : public IGameEngine {
public:
    Pacman();
    ~Pacman() = default;
    void handleUserInput(char key) override;
    int getScore() override;
    bool getStatus() override;
    Enum::libType GetLibType() override;
    std::map<int, std::pair<Enum::ObjectType, std::pair<int, int>>> getObjects() override;
    
protected:
    int _score;
    int _MapBorderIndex = 0;
    int _ObjectIndex = 0;
    int _MazeIndex = 0;
    bool _is_ended;
    std::chrono::time_point<std::chrono::system_clock> _GhostTimer = std::chrono::system_clock::now() + std::chrono::seconds(10);
    std::pair<int, int> _MapBorderStartPos  = std::make_pair(60, 15);
    std::pair<int, int> _MapBorderSize = std::make_pair(37, 30);
    std::pair<int, int> _GhostSpawnAreaStartPos = std::make_pair(_MapBorderStartPos.first + _MapBorderSize.first / 2 - 7 / 2, _MapBorderStartPos.second + _MapBorderSize.second / 2 - 6 / 2);
    std::pair<int, int> _PacmanStartPos = std::make_pair(_GhostSpawnAreaStartPos.first + 3, _GhostSpawnAreaStartPos.second + 6);
    std::pair<Enum::ObjectType, std::pair<int, int>> _Pacman;
    std::map<int, std::pair<int, int>> _GhostSpawnPos;
    std::map<int, std::pair<Enum::ObjectType, std::pair<int, int>>> _ObjectsData;
    std::map<int, std::pair<Enum::ObjectType, std::pair<int, int>>> _GumData; // <index, <Enum::ObjectType, <x, y>>>
    std::map<int, std::pair<Enum::ObjectType, std::pair<int, int>>> _GhostData;
    std::map<int, std::pair<Enum::ObjectType, std::pair<int, int>>> _MazeData;
    std::map<int, std::pair<Enum::ObjectType, std::pair<int, int>>> _MapBorderData;
    std::map<int, std::pair<Enum::ObjectType, std::pair<int, int>>> _WallData;
    std::vector<std::map<int, std::pair<Enum::ObjectType, std::pair<int, int>>>> _DataArrays;
private:
    void concatDataMaps(void);
    void handlePacmanMovement(char key);
    void handlePacmanWallCollision(char last_key);
    void handlePacmanGhostsAreaCollision(void);
    void handleGhostMovement(void);
    void checkPacmanCollision(char last_key);
    void createMapBorder(int start_x, int start_y, int width, int height);
    void createMaze(void);
    void createPacman(int x, int y);
    void createGhosts(void);
    void moveGhostToSpawnAreaExit(int i);
    std::map<int, std::pair<Enum::ObjectType, std::pair<int, int>>> getMapBorderData(void);
    std::pair<int, int> getMapBorderStartPos(void);
    std::pair<int, int> getMapBorderSize(void);
};
