/*
** EPITECH PROJECT, 2023
** MIRROR-B-OOP-400-NAN-4-1-arcade-andreas.le-tanter [WSL : Ubuntu]
** File description:
** Menu
*/

#pragma once
#include "IMenu.hpp"
#include "../InitClass/Init.hpp"

class Menu : public IMenu {
    public:
        Menu();
        ~Menu() {};
        void displayMenu();

    protected:
        IInit *_Init;
        DLLoader<IDisplayModule> *currentGraphicLibrary;
        DLLoader<IDisplayModule> *currentGameLibrary;
        std::string _currentUserName;
    private:
        std::map<int, std::pair<ObjectType, std::pair<int, int>>> CreateMenuObjectsData(char key);
        void displayGamesMenu();
        void displayGraphicalMenu();
        void displayMenuText();
        std::map<int, std::pair<ObjectType, std::pair<int, int>>> _MenuObjectsData;
        std::pair<int, int> _WindowMaxSize;
};
