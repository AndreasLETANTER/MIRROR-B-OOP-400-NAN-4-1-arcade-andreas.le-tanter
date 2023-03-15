/*
** EPITECH PROJECT, 2023
** BOOTSTRAP_Arcade [WSL : Ubuntu]
** File description:
** IDisplayModule
*/

#pragma once
#include <string>
#include <string>
#include <ncurses.h>
#include <map>

enum class ObjectType {
    PLAYER,
    PLAYER_PART,
    ENEMY,
    ITEM,
    BORDER
};

class IDisplayModule {
    public:
        virtual ~IDisplayModule() = default;
        virtual void init() = 0;
        virtual void displayObjects(std::map<int, std::pair<ObjectType, std::pair<int, int>>> _ObjectData) = 0;
        virtual void displayScore(int _Score) = 0;
        virtual const std::string &getName() const = 0;

    protected:
    private:
};
