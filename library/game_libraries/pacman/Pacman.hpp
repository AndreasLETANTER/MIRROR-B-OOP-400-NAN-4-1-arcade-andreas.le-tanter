/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** handle Pacman
*/

#pragma once

#include "../IGameEngine.hpp"

class Pacman : public IGameEngine {
public:
    Pacman();
    ~Pacman();
    void handleUserInput(char key) override;
    int getScore() const override;
    bool getStatus() const override;
    std::map<int, std::pair<Enum::ObjectType, std::pair<int, int>>> getObjects() const override;
protected:
    int _score;
    bool _is_ended;
    std::map<int, std::pair<Enum::ObjectType, std::pair<int, int>>> test; // <index, <Enum::ObjectType, <x, y>>>
};
