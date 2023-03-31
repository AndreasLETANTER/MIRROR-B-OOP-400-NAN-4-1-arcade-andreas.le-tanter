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
#include "ErrorClass/ErrorClass.hpp"

/**
 * @brief Main function
 * @details Create the Core object and run it
*/
int main(int argc, char **argv)
{
    if (argc != 2) {
        std::cerr << "Usage: ./arcade [lib]" << std::endl;
        return 84;
    }

    try {
        std::shared_ptr<ICore> _Core = std::make_shared<Core>(argv[1]);
        _Core->Run();
    } catch (Error &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
}
