/*
** EPITECH PROJECT, 2023
** MIRROR-B-OOP-400-NAN-4-1-arcade-andreas.le-tanter [WSL : Ubuntu]
** File description:
** Menu
*/

#pragma once
#include "IMenu.hpp"
#include <map>
#include <memory>

/**
 * @brief Menu class
*/
class Menu : public IMenu {
    public:
        Menu();
        ~Menu() {};
        void DisplayMenu();
        void setProgramEvents(std::shared_ptr<IProgramEvents> ProgramEvents) {_ProgramEvents = ProgramEvents;};

    protected:
    private:
        std::shared_ptr<IProgramEvents> _ProgramEvents;
        std::map<int, std::pair<Enum::ObjectType, std::pair<int, int>>> CreateMenuObjectsData(char key);
        void displayGamesMenu();
        void displayGraphicalMenu();
        void DisplayMenuText();
        std::map<int, std::pair<Enum::ObjectType, std::pair<int, int>>> _MenuObjectsData;
        std::pair<int, int> _WindowMaxSize;
};
