/*
** EPITECH PROJECT, 2023
** BOOTSTRAP_Arcade [WSL : Ubuntu]
** File description:
** library_foo
*/

#pragma once
#include "../IDisplayModule.hpp"
#include <iostream>

class LibrarySfml : public IDisplayModule {
    public:
        void init();
        void stop();
        const std::string &getName() const;

    protected:
    private:
};
