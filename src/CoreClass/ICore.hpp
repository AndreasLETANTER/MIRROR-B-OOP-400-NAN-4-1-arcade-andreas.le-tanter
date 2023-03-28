/*
** EPITECH PROJECT, 2023
** MIRROR-B-OOP-400-NAN-4-1-arcade-andreas.le-tanter [WSL : Ubuntu]
** File description:
** ICore
*/

#pragma once

/**
 * @brief Core interface
 */
class ICore {
    public:
        virtual ~ICore() = default;
        virtual void Run() = 0;

    protected:
    private:
};
