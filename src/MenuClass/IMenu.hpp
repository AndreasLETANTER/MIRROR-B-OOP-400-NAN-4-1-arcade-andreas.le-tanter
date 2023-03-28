/*
** EPITECH PROJECT, 2023
** MIRROR-B-OOP-400-NAN-4-1-arcade-andreas.le-tanter [WSL : Ubuntu]
** File description:
** IMenu
*/

#pragma once
#include <memory>
#include "../ProgramEventsClass/IProgramEvents.hpp"

/**
 * @brief Menu interface
*/
class IMenu {
    public:
        virtual ~IMenu() = default;
        virtual void DisplayMenu() = 0;
        virtual void setProgramEvents(std::shared_ptr<IProgramEvents> ProgramEvents) = 0;

    protected:
    private:
};
