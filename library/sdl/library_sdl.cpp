/*
** EPITECH PROJECT, 2023
** BOOTSTRAP_Arcade [WSL : Ubuntu]
** File description:
** library_sdl
*/

#include <unistd.h>
#include "library_sdl.hpp"

extern "C"
{
    IDisplayModule *entryPoint()
    {
        write(1, "[libsdl] Entry point for sdl!\n", 31);
        return new LibrarySdl();
    }
}

__attribute__((constructor))
static void create() {
    write(1, "[libsdl] Loading sdl library...\n", 33);
}

__attribute__((destructor))
static void destroy() {
    write(1, "[libsdl] Closing sdl...\n", 25);
}

void LibrarySdl::init()
{
    write(1, "[libsdl] Init sdl library...\n", 30);
}

void LibrarySdl::stop()
{
    write(1, "[libsdl] Stopping sdl...\n", 26);
}

const std::string &LibrarySdl::getName() const
{
    static std::string name = "sdl";
    return name;
}
