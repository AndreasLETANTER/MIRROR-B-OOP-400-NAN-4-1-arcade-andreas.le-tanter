/*
** EPITECH PROJECT, 2023
** BOOTSTRAP_Arcade [WSL : Ubuntu]
** File description:
** main
*/

#include <iostream>
#include <memory>
#include "CoreClass/Core.hpp"
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char **argv)
{
    (void)argc;
    (void)argv;
    std::shared_ptr<ICore> _Core = std::make_shared<Core>();

    _Core->Run();
}
