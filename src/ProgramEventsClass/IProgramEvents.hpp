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
        virtual DLLoader<IDisplayModule> *getCurrentGraphicLibrary() = 0;
        virtual DLLoader<IDisplayModule> *getCurrentGameLibrary() = 0;
        virtual std::string getCurrentUserName() = 0;
        virtual IInit *getInit() = 0;
        virtual void handleEvents() = 0;

    protected:
    private:
};
