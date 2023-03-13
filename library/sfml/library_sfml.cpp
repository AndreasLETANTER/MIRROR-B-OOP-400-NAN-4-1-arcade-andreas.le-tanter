/*
** EPITECH PROJECT, 2023
** BOOTSTRAP_Arcade [WSL : Ubuntu]
** File description:
** library_sfml
*/

#include "library_sfml.hpp"
#include <unistd.h>

__attribute__((constructor))
static void create() {
    write(1, "[libsfml] Loading sfml library...\n", 35);
}

__attribute__((destructor))
static void destroy() {
    write(1, "[libsfml] sfml closing...\n", 27);
}

extern "C"
{
    IDisplayModule *entryPoint()
    {
        write(1, "[libsfml] Entry point for sfml!\n", 33);
        return new LibrarySfml();
    }
}

void LibrarySfml::init()
{
    write(1, "[libsfml] Init sfml library...\n", 32);
}

void LibrarySfml::stop()
{
    write(1, "[libsfml] Stopping sfml...\n", 28);
}

const std::string &LibrarySfml::getName() const
{
    static std::string name = "sfml";
    return name;
}
