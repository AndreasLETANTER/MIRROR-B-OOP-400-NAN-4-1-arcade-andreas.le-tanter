/*
** EPITECH PROJECT, 2023
** BOOTSTRAP_Arcade [WSL : Ubuntu]
** File description:
** library_gra
*/

#pragma once
#include "../IDisplayModule.hpp"
#include <iostream>

class LibrarySFML : public IDisplayModule {
    public:
        LibrarySFML();
        ~LibrarySFML();
        void InitWindow() override;
        void FiniWindow() override;
        void displayObjects(std::map<int, std::pair<ObjectType, std::pair<int, int>>> _ObjectData) override;
        void displayScore(int _Score, int x, int y) override;
        void displayText(std::string _String, std::pair<int, int> _Pos, Color FrontFont, Color BackFont) override;
        const std::string &GetLibType() const;
        std::pair<int, int> GetWindowSize() override;
        char getUserInput() override;

    protected:
        int idx = 0;
        WINDOW *_CurrentWindow;
        std::map <Color, int> _ColorDefinition;
    private:
};
