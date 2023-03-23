/*
** EPITECH PROJECT, 2023
** MIRROR-B-OOP-400-NAN-4-1-arcade-andreas.le-tanter [WSL : Ubuntu]
** File description:
** IProgramEvents
*/

#pragma once
#include "../Loader/DLLoader.hpp"
#include "../InitClass/IInit.hpp"

/**
 * @brief State enum
*/
enum State {
    MENU,
    GAME,
    STOP
};

/**
 * @brief ProgramEvents interface
*/
class IProgramEvents {
    public:
        virtual ~IProgramEvents() = default;
        virtual DLLoader<IDisplayModule> *getCurrentGraphicLibrary() = 0;
        virtual DLLoader<IGameEngine> *getCurrentGameLibrary() = 0;
        virtual std::string getCurrentUserName() = 0;
        virtual IInit *getInit() = 0;
        virtual char handleEvents() = 0;
        virtual State getCurrentState() = 0;

    protected:
    private:
};
