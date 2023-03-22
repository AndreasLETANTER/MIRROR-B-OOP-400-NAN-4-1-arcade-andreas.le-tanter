/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** Game Engine header file
*/

#pragma once
#include <map>
#include "IGameEngine.hpp"

class IGameEngine {
    public:
        virtual ~IGameEngine() = default;
        virtual void handleUserInput(char key) = 0;
        virtual int getScore() const = 0;
        virtual bool getStatus() const = 0;
        virtual std::map<int, std::pair<ObjectType, std::pair<int, int>>> getObjects() const = 0;
        virtual const std::string &GetLibType() const = 0;
};
