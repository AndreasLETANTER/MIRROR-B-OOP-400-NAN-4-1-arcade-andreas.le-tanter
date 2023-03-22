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

enum class Color {
    RED,
    GREEN,
    BLUE,
    YELLOW,
    WHITE,
    BLACK
};

class IDisplayModule {
    public:
        virtual ~IDisplayModule() = default;
        virtual void InitWindow() = 0;
        virtual void FiniWindow() = 0;
        virtual void displayObjects(std::map<int, std::pair<ObjectType, std::pair<int, int>>> _ObjectData) = 0;
        virtual void displayText(std::string _String, std::pair<int, int> _Pos, Color FrontFont, Color BackFont) = 0;
        virtual void displayScore(int _Score, int x, int y) = 0;
        virtual const std::string &GetLibType() const = 0;
        virtual std::pair<int, int> GetWindowSize() = 0;
        virtual char getUserInput() = 0;

    protected:
    private:
};
