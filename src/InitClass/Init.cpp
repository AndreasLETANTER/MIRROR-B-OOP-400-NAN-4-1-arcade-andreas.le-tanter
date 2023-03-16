/*
** EPITECH PROJECT, 2023
** MIRROR-B-OOP-400-NAN-4-1-arcade-andreas.le-tanter [WSL : Ubuntu]
** File description:
** Init
*/

#include "Init.hpp"
#include <iostream>
#include <filesystem>

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

void Init::loadInstances(const std::string  &path)
{
    int nb_files = getNbFiles(path);
    DLLoader<IDisplayModule> *tempInstance;
    IDisplayModule *module;
    int nb_graphical = 0;
    int nb_games = 0;

    getAllFilePaths(path);
    for (int i = 0; i !=  nb_files; i++) {
        tempInstance = new DLLoader<IDisplayModule>(_libraryFilesPath[i].c_str());
        tempInstance->openInstance();
        module = tempInstance->getInstance();
        if (module->GetLibType() == "Graphic") {
            _GraphicalInstances[i] = tempInstance;
            nb_graphical++;
        }
        else if (module->GetLibType() == "Game") {
            _GraphicalInstances[i] = tempInstance;
            nb_games++;
        }    
    }
    std::cout << "Number of graphical libraries opened : " << nb_graphical << ";" << std::endl;
    std::cout << "Number of games libraries opened : " << nb_games << ";" << std::endl;
    std::cout << "<---------------------------------------------------------------->" << std::endl;
}

Init::Init()
{
}

Init::Init(const std::string &path)
{
    loadInstances(path);
}
