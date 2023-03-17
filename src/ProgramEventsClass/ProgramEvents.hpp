/*
** EPITECH PROJECT, 2023
** MIRROR-B-OOP-400-NAN-4-1-arcade-andreas.le-tanter [WSL : Ubuntu]
** File description:
** ProgramEvents
*/

#pragma once
#include "../InitClass/Init.hpp"
#include "IProgramEvents.hpp"

class ProgramEvents : public IProgramEvents {
    public:
        ProgramEvents();
        ~ProgramEvents();
        inline DLLoader<IDisplayModule> *getCurrentGraphicLibrary() { return currentGraphicLibrary; };
        inline DLLoader<IDisplayModule> *getCurrentGameLibrary() { return currentGameLibrary; };
        inline std::string getCurrentUserName() { return _currentUserName; };
        inline IInit *getInit() { return _Init; };

    protected:  
        IInit *_Init;
        DLLoader<IDisplayModule> *currentGraphicLibrary;
        DLLoader<IDisplayModule> *currentGameLibrary;
        std::string _currentUserName;
    private:
};
