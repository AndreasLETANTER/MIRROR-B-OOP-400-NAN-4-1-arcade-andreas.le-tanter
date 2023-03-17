/*
** EPITECH PROJECT, 2023
** MIRROR-B-OOP-400-NAN-4-1-arcade-andreas.le-tanter [WSL : Ubuntu]
** File description:
** ProgramEvents
*/

#pragma once
#include "IProgramEvents.hpp"
#include "../InitClass/Init.hpp"
#include <map>
#include <functional>

class ProgramEvents : public IProgramEvents {
    public:
        ProgramEvents();
        ~ProgramEvents();
        char handleEvent(int key) override;

    protected:
        IInit *_Init;
        DLLoader<IDisplayModule> *currentGraphicLibrary;
        DLLoader<IDisplayModule> *currentGameLibrary;
        std::string _currentUserName;
        std::map<int, std::function<char(ProgramEvents *_ProgramEvents)>> _ProgramEventsMap;
    private:
        char SwapGraphicLib(void);
        char SwapGameLib(void);
        char RestartGame(void);
        char GoToMenu(void);
        char Exit(void);
};
