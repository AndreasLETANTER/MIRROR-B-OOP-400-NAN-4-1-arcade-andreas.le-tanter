/*
** EPITECH PROJECT, 2023
** MIRROR-B-OOP-400-NAN-4-1-arcade-andreas.le-tanter [WSL : Ubuntu]
** File description:
** Init
*/

#include "Init.hpp"
#include <iostream>
#include <filesystem>

/**
 * @brief Get the number of files in a folder
 * @param path Path to the folder
*/
int Init::getNbFiles(const std::string &path)
{
    int count = 0;

    std::filesystem::path fp = path;
    if (!std::filesystem::exists(fp)) {
        std::cout << "Error: " << path << " folder doesn't exist." << std::endl;
        exit(84);
    }
    for (auto p : std::filesystem::directory_iterator(fp)) {
        if (p.is_regular_file())
            count++;
    }
    std::cout << "<---------------------------------------------------------------->" << std::endl;
    std::cout << "Number of library opened in " << path << " folder : " << count << ";" << std::endl;
    return count;
}


/**
 * @brief Get all files path in a folder
 * @param path Path to the folder
*/
void Init::getAllFilePaths(const std::string &path)
{
    int file_count = 0;

    std::cout << "Libraries opened in " << path << " folder :" << std::endl;
    std::filesystem::path fp = path;
    if (!std::filesystem::exists(fp)) {
        std::cout << "Error: " << path << " folder doesn't exist." << std::endl;
        exit(84);
    }
    for (auto p : std::filesystem::directory_iterator(fp)) {
        if (p.is_regular_file()) {
            std::cout << p.path() << std::endl;
            _libraryFilesPath[file_count] = p.path();
            file_count++;
        }
    }
    std::cout << "<---------------------------------------------------------------->" << std::endl;
    _libraryFilesPath[file_count] = "";
}

/**
 * @brief Load all instances of libraries in a folder
 * @param path Path to the folder
*/
void Init::loadInstances(const std::string  &path)
{
    int nb_files = getNbFiles(path);
    DLLoader<IDisplayModule> *tempInstanceGraphic;
    DLLoader<IGameEngine> *tempInstanceGame;
    ILibrary *module;
    int nb_graphical = 0;
    int nb_games = 0;

    getAllFilePaths(path);
    for (int i = 0; i != nb_files; i++) {
        tempInstanceGraphic = new DLLoader<IDisplayModule>(_libraryFilesPath[i].c_str());
        tempInstanceGame = new DLLoader<IGameEngine>(_libraryFilesPath[i].c_str());
        tempInstanceGraphic->openInstance();
        tempInstanceGame->openInstance();
        module = tempInstanceGraphic->getInstance();
        if (module->GetLibType() == Enum::GRAPHIC) {
            _GraphicalInstances[nb_graphical] = tempInstanceGraphic;
            nb_graphical++;
        } else if (module->GetLibType() == Enum::GAME) {
            _GamesInstances[nb_games] = tempInstanceGame;
            nb_games++;
        }
    }
    std::cout << "Number of graphical libraries opened : " << nb_graphical << ";" << std::endl;
    std::cout << "Number of games libraries opened : " << nb_games << ";" << std::endl;
    std::cout << "<---------------------------------------------------------------->" << std::endl;
}

/**
 * @brief Construct a new Init object
*/
Init::Init()
{
}

/**
 * @brief construct a new Init object with all the instances
 * @param path Path to the folder
*/
Init::Init(const std::string &path)
{
    loadInstances(path);
}
