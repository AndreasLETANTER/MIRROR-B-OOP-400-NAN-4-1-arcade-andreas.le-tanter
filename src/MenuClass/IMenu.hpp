/*
** EPITECH PROJECT, 2023
** MIRROR-B-OOP-400-NAN-4-1-arcade-andreas.le-tanter [WSL : Ubuntu]
** File description:
** IMenu
*/

#pragma once

class IMenu {
    public:
        virtual ~IMenu() = default;
        virtual void displayMenu() = 0;

    protected:
    private:
};
