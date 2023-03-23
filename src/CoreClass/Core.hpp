/*
** EPITECH PROJECT, 2023
** MIRROR-B-OOP-400-NAN-4-1-arcade-andreas.le-tanter [WSL : Ubuntu]
** File description:
** Core
*/

#pragma once
#include "ICore.hpp"
#include "../MenuClass/Menu.hpp"
#include "../GameClass/Game.hpp"

/**
 * @brief Core class
*/
class Core : public ICore {
    public:
        Core();
        ~Core();
        void Run();

    protected:
        std::shared_ptr<IMenu> _Menu;
        std::shared_ptr<IGame> _Game;
        std::shared_ptr<IProgramEvents> _ProgramEvents;
    private:
};
