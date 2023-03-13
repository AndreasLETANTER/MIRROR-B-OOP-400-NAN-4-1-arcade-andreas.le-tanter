/*
** EPITECH PROJECT, 202_file_count
** BOOTSTRAP_Arcade [WSL : Ubuntu]
** File description:
** Engine
*/

#include "Engine.hpp"
#include <dirent.h>
#include <iostream>
#include <filesystem>

int Engine::get_nb_files(std::string filepath)
{
    int count = 0;

    std::filesystem::path fp = filepath;
    for (auto p : std::filesystem::directory_iterator(fp)) {
        if (p.is_regular_file())
            count++;
    }
    std::cout << "<---------------------------------------------------------------->" << std::endl;
    std::cout << "Number of library opened in " << filepath << "folder : " << count << ";" << std::endl;
    return count;
}

Engine::Engine(std::string filepath)
{
    _file_count = get_nb_files(filepath);
    openLibraries(filepath);
    run();
    closeLibraries();
}

void Engine::run()
{
    IDisplayModule *module;

    for (int i = 0; i != _file_count; i++) {
        _instances[i]->openInstance();
        module = _instances[i]->getInstance();
        module->init();
        module->stop();
    }
}

void Engine::openLibraries(const std::string &libraryName)
{
    get_all_filepath(libraryName);
    for (int i = 0; i != _file_count; i++) {
        _instances[i] = new DLLoader<IDisplayModule>(_libraryFilesPath[i].c_str());
    }
}

void Engine::closeLibraries()
{
    for (int i = 0; i != _file_count; i++) {
        _instances[i]->closeLibrary();
    }
}

void Engine::get_all_filepath(const std::string &path)
{
    int file_count = 0;
    DIR *dirp;
    struct dirent *entry;

    dirp = opendir(path.c_str());
    std::cout << "Libraries opened in " << path << " folder :" << std::endl;
    while ((entry = readdir(dirp)) != NULL) {
        if (entry->d_type == DT_REG) {
            std::cout << "\t" << entry->d_name << std::endl;
            _libraryFilesPath[file_count] = path + entry->d_name;
            file_count++;
        }
    }
    std::cout << "<---------------------------------------------------------------->" << std::endl;
    _libraryFilesPath[file_count] = "";
    closedir(dirp);
}
