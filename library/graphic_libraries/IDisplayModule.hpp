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
#include "../ILibrary.hpp"

/**
 * @brief Interface for the display module
*/
class IDisplayModule : public ILibrary {
    public:
        virtual ~IDisplayModule() = default;
        virtual void InitWindow() = 0;
        virtual void FiniWindow() = 0;
        virtual void displayObjects(std::map<int, std::pair<Enum::ObjectType, std::pair<int, int>>> _ObjectData) = 0;
        virtual void displayText(std::string _String, std::pair<int, int> _Pos, Enum::Color FrontFont, Enum::Color BackFont) = 0;
        virtual void displayScore(int _Score, int x, int y) = 0;
        virtual Enum::libType GetLibType() = 0;
        virtual std::pair<int, int> GetWindowSize() = 0;
        virtual char getUserInput() = 0;
        virtual void display() = 0;

    protected:
    private:
};
