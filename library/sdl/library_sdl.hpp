/*
** EPITECH PROJECT, 2023
** BOOTSTRAP_Arcade [WSL : Ubuntu]
** File description:
** library_bar
*/

#pragma once
#include "../IDisplayModule.hpp"
#include <iostream>

class LibrarySdl : public IDisplayModule {
    public:
        void init();
        void stop();
        const std::string &getName() const;

    protected:
    private:
};
