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
    bool _is_ended;
    std::pair<int, int> _MapBorderStartPos  = std::make_pair(20, 20);
    std::pair<int, int> _MapBorderSize = std::make_pair(10, 6);
    std::pair<Enum::ObjectType, std::pair<int, int>> _Pacman;
    std::map<int, std::pair<Enum::ObjectType, std::pair<int, int>>> _ObjectsData;
    std::map<int, std::pair<Enum::ObjectType, std::pair<int, int>>> _GumData; // <index, <Enum::ObjectType, <x, y>>>
    std::map<int, std::pair<Enum::ObjectType, std::pair<int, int>>> _GhostData;
    std::map<int, std::pair<Enum::ObjectType, std::pair<int, int>>> _MazeData;
    std::map<int, std::pair<Enum::ObjectType, std::pair<int, int>>> _MapBorderData;
    std::vector<std::map<int, std::pair<Enum::ObjectType, std::pair<int, int>>>> _DataArrays;
private:
    void concatDataMaps(void);
    void createMapBorder(int start_x, int start_y, int width, int height);
    void createGhosts(int ghostCount);
    std::map<int, std::pair<Enum::ObjectType, std::pair<int, int>>> getMapBorderData(void);
    std::pair<int, int> getMapBorderStartPos(void);
    std::pair<int, int> getMapBorderSize(void);
};
