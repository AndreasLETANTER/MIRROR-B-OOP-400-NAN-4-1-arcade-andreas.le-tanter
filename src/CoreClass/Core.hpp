/*
** EPITECH PROJECT, 2023
** MIRROR-B-OOP-400-NAN-4-1-arcade-andreas.le-tanter [WSL : Ubuntu]
** File description:
** Core
*/

#pragma once
#include "ICore.hpp"
#include "../ProgramEventsClass/ProgramEvents.hpp"
#include <memory>

class Core : public ICore {
    public:
        Core();
        ~Core();
        void DisplayGame();
        inline void setProgramEvents(std::shared_ptr<IProgramEvents> ProgramEvents) {_ProgramEvents = ProgramEvents;};

    protected:
        std::shared_ptr<IProgramEvents> _ProgramEvents;
    private:
};
