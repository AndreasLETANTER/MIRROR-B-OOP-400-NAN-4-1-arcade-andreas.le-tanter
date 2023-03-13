/*
** EPITECH PROJECT, 2023
** BOOTSTRAP_Arcade [WSL : Ubuntu]
** File description:
** IEngine
*/

#pragma once
#include <string>

class IEngine {
    public:
        virtual ~IEngine() = default;
        virtual void run() = 0;
        virtual void openLibraries(const std::string &libraryName) = 0;
        virtual void closeLibraries() = 0;

    protected:
    private:
};
