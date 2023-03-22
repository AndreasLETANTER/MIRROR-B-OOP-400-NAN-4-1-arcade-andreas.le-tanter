/*
** EPITECH PROJECT, 2023
** MIRROR-B-OOP-400-NAN-4-1-arcade-andreas.le-tanter [WSL : Ubuntu]
** File description:
** ProgramEvents
*/

#pragma once
#include "../InitClass/Init.hpp"
#include "IProgramEvents.hpp"
#include <map>
#include <functional>

class ProgramEvents : public IProgramEvents {
    public:
        ProgramEvents();
        ~ProgramEvents();
        char handleEvents();
        inline DLLoader<IDisplayModule> *getCurrentGraphicLibrary() { return currentGraphicLibrary; };
        inline DLLoader<IDisplayModule> *getCurrentGameLibrary() { return currentGameLibrary; };
        inline std::string getCurrentUserName() { return _currentUserName; };
        inline IInit *getInit() { return _Init; };
        State getCurrentState() { return _currentState; };

    protected:  
        IInit *_Init;
        std::map<int, std::function<void(ProgramEvents *)>> _keyMap;
        DLLoader<IDisplayModule> *currentGraphicLibrary;
        DLLoader<IDisplayModule> *currentGameLibrary;
        std::string _currentUserName;
    private:
        State _currentState;
        void SwapGraphicLib();
        void SwapGameLib();
        void ChangeUserName();
        void GoToMenu();
        void GoToGame();
        void Exit();
};
