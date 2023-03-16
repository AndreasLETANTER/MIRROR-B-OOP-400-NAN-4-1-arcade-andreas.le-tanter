/*
** EPITECH PROJECT, 2023
** BOOTSTRAP_Arcade [WSL : Ubuntu]
** File description:
** library_gra
*/

#pragma once
#include "../IDisplayModule.hpp"
#include <iostream>

class LibraryNcurses : public IDisplayModule {
    public:
        LibraryNcurses();
        ~LibraryNcurses();
        void InitWindow() override;
        void displayObjects(std::map<int, std::pair<ObjectType, std::pair<int, int>>> _ObjectData) override;
        void displayScore(int _Score) override;
        const std::string &GetLibType() const;

    protected:
        WINDOW *_CurrentWindow;
    private:
};
