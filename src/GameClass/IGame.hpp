/*
** EPITECH PROJECT, 2023
** MIRROR-B-OOP-400-NAN-4-1-arcade-andreas.le-tanter [WSL : Ubuntu]
** File description:
** IGame
*/

#pragma once

class IGame {
    public:
        virtual ~IGame() = default;
        virtual void DisplayGame() = 0;

    protected:
    private:
};
