/*
** EPITECH PROJECT, 2023
** MIRROR-B-OOP-400-NAN-4-1-arcade-andreas.le-tanter [WSL : Ubuntu]
** File description:
** Game
*/

#pragma once
#include "IGame.hpp"
#include "../ProgramEventsClass/ProgramEvents.hpp"
#include <memory>

/**
 * @brief Game class
*/
class Game : public IGame {
    public:
        Game();
        ~Game();
        void DisplayGame();
        inline void setProgramEvents(std::shared_ptr<IProgramEvents> ProgramEvents) {_ProgramEvents = ProgramEvents;};

    protected:
        std::shared_ptr<IProgramEvents> _ProgramEvents;
    private:
};
