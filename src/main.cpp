/*
** EPITECH PROJECT, 2023
** BOOTSTRAP_Arcade [WSL : Ubuntu]
** File description:
** main
*/

#include <iostream>
#include <memory>
#include "Engine/Engine.hpp"

int main(int argc, char **argv)
{
    (void)argc;
    (void)argv;
    std::shared_ptr<Engine> engine = std::make_shared<Engine>("lib/");
}
