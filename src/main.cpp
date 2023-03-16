/*
** EPITECH PROJECT, 2023
** BOOTSTRAP_Arcade [WSL : Ubuntu]
** File description:
** main
*/

#include <iostream>
#include <memory>
#include "MenuClass/Menu.hpp"
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char **argv)
{
    (void)argc;
    (void)argv;
    std::shared_ptr<IMenu> _Menu = std::make_shared<Menu>();

    _Menu->displayMenu();
}
