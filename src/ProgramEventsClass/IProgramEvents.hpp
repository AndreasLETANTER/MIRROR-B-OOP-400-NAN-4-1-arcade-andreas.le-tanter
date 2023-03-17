/*
** EPITECH PROJECT, 2023
** MIRROR-B-OOP-400-NAN-4-1-arcade-andreas.le-tanter [WSL : Ubuntu]
** File description:
** IProgramEvents
*/

#pragma once

class IProgramEvents {
    public:
        virtual ~IProgramEvents() = default;
        virtual char handleEvent(int key) = 0;

    protected:
    private:
};
