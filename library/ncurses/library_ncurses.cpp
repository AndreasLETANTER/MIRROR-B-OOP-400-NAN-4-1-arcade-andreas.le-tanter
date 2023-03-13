/*
** EPITECH PROJECT, 2023
** BOOTSTRAP_Arcade [WSL : Ubuntu]
** File description:
** library_ncurses
*/

#include <unistd.h>
#include "library_ncurses.hpp"

__attribute__((constructor))
static void create() {
    write(1, "[libncurses] Loading ncurses library...\n", 41);
}

__attribute__((destructor))
static void destroy() {
    write(1, "[libncurses] ncurses's getting out...\n", 39);
}

extern "C"
{
    IDisplayModule *entryPoint()
    {
        write(1, "[libncurses] Another entry point!\n", 35);
        return new LibraryNcurses();
    }
}

void LibraryNcurses::init()
{
    write(1, "[libncurses] Init ncurses library...\n", 38);
}

void LibraryNcurses::stop()
{
    write(1, "[libncurses] Stopping ncurses...\n", 34);
}

const std::string &LibraryNcurses::getName() const
{
    static std::string name = "ncurses";
    return name;
}
