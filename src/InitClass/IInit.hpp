/*
** EPITECH PROJECT, 2023
** MIRROR-B-OOP-400-NAN-4-1-arcade-andreas.le-tanter [WSL : Ubuntu]
** File description:
** IInit
*/

#pragma once
#include "../../library/IDisplayModule.hpp"
#include "../Loader/DLLoader.hpp"
#include <memory>
#include <map>

class IInit {
    public:
        virtual ~IInit() = default;
        virtual void loadInstances(const std::string &path) = 0;
        virtual std::map<int, DLLoader<IDisplayModule> *> getGamesInstances() = 0;
        virtual std::map<int, DLLoader<IDisplayModule> *> getGraphicalInstances() = 0;

    protected:
    private:
};
