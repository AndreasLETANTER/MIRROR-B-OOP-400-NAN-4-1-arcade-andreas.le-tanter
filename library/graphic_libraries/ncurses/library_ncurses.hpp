/*
** EPITECH PROJECT, 2023
** BOOTSTRAP_Arcade [WSL : Ubuntu]
** File description:
** library_gra
*/

#pragma once
#include "../IDisplayModule.hpp"
#include <iostream>

/**
 * @brief Ncurses library
*/
class LibraryNcurses : public IDisplayModule {
    public:
        LibraryNcurses() = default;
        ~LibraryNcurses() = default;
        void InitWindow() override;
        void FiniWindow() override;
        void displayObjects(std::map<int, std::pair<Enum::ObjectType, std::pair<int, int>>> _ObjectData) override;
        void displayScore(int _Score, int x, int y) override;
        void displayText(std::string _String, std::pair<int, int> _Pos, Enum::Color FrontFont, Enum::Color BackFont) override;
        Enum::libType GetLibType();
        std::pair<int, int> GetWindowSize() override;
        char getUserInput() override;
        void display() override;

    protected:
        int idx = 0;
        WINDOW *_CurrentWindow;
        std::map <Enum::Color, int> _ColorDefinition;
        std::map <std::pair<Enum::Color, Enum::Color>, int> _KnownColors;
    private:
};
