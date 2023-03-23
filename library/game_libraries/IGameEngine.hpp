/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** Game Engine header file
*/

#pragma once
#include <map>
#include "../graphic_libraries/IDisplayModule.hpp"

class IGameEngine : public ILibrary {
    public:
        virtual ~IGameEngine() = default;
        virtual void handleUserInput(char key) = 0;
        virtual int getScore() = 0;
        virtual bool getStatus() = 0;
        virtual std::map<int, std::pair<Enum::ObjectType, std::pair<int, int>>> getObjects() = 0;
        virtual Enum::libType GetLibType() = 0;
};
