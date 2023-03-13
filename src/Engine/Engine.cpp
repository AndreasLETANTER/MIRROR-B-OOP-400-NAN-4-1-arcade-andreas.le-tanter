/*
** EPITECH PROJECT, 202_file_count
** BOOTSTRAP_Arcade [WSL : Ubuntu]
** File description:
** Engine
*/

#include "Engine.hpp"
#include <dirent.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stddef.h>
#include <fcntl.h>
#include <stdlib.h>
#include <dlfcn.h>
#include <iostream>
#include <filesystem>
#include "../../library/IDisplayModule.hpp"

int Engine::get_nb_files(std::string filepath)
{
    int count = 0;

    std::filesystem::path fp = filepath;
    for (auto p : std::filesystem::directory_iterator(fp)) {
        p = p;
        count++;
    }
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
    typedef IDisplayModule *(*entryPoint_t)(void);
    IDisplayModule *module;

    for (int i = 0; i != _file_count; i++) {
        entryPoint_t entryPoint = (entryPoint_t) dlsym(_libraries[i], "entryPoint");
        module = entryPoint();
        module->init();
        module->stop();
    }
}

void Engine::openLibraries(const std::string &libraryName)
{
    void *handle;

    get_all_filepath(libraryName);
    for (int i = 0; i != _file_count; i++) {
        handle = dlopen(_libraryFilesPath[i].c_str(), RTLD_LAZY);
        if (!handle) {
            fprintf(stderr, "%s\n", dlerror());
            exit(84);
        } else {
            _libraries[i] = handle;
        }
    }
}

void Engine::closeLibraries()
{
    for (int i = 0; i != _file_count; i++) {
        dlclose(_libraries[i]);
    }
}

void Engine::get_all_filepath(const std::string &path)
{
    int file_count = 0;
    DIR *dirp;
    struct dirent *entry;

    dirp = opendir(path.c_str());
    while ((entry = readdir(dirp)) != NULL) {
        if (entry->d_type == DT_REG) {
            _libraryFilesPath[file_count] = path + entry->d_name;
            file_count++;
        }
    }
    _libraryFilesPath[file_count] = "";
    closedir(dirp);
}
