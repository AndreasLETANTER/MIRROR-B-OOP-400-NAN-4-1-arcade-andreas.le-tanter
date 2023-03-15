/*
** EPITECH PROJECT, 2023
** BOOTSTRAP_Arcade [WSL : Ubuntu]
** File description:
** main
*/

#include <iostream>
#include <memory>
#include "InitClass/Init.hpp"

int main(int argc, char **argv)
{
    (void)argc;
    (void)argv;
    std::shared_ptr<IInit> _Init = std::make_shared<Init>("lib/");
    std::cout << _Init->getGraphicalInstances()[0]->getInstance()->getName() << std::endl;
}
