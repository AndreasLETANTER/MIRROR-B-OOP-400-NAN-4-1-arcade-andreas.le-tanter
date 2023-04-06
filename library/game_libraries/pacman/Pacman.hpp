/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** handle Pacman
*/

#pragma once

#include "../IGameEngine.hpp"

/**
 * @brief Pacman class
*/
class Pacman : public IGameEngine {
public:
    Pacman() = default;
    ~Pacman() = default;
    void handleUserInput(char key) override;
    int getScore() override;
    bool getStatus() override;
    Enum::libType GetLibType() override;
    std::map<int, std::pair<Enum::ObjectType, std::pair<int, int>>> getObjects() override;
    void ResetGame() {};
    
protected:
    int _score;
    bool _is_ended;
    std::map<int, std::pair<Enum::ObjectType, std::pair<int, int>>> _ObjectData; // <index, <Enum::ObjectType, <x, y>>>
};
