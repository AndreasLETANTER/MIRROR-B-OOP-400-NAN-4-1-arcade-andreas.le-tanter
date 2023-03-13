/*
** EPITECH PROJECT, 2023
** BOOTSTRAP_Arcade [WSL : Ubuntu]
** File description:
** Engine
*/

#pragma once
#include "IEngine.hpp"
#include "../../library/IDisplayModule.hpp"
#include "../Loader/DLLoader.hpp"
#include <map>

class Engine : public IEngine {
    public:
        Engine() {};
        Engine(std::string filepath);
        void run();
        void openLibraries(const std::string &libraryName);
        void closeLibraries();

    protected:
        int _file_count = 0;
        std::map<int, DLLoader<IDisplayModule> *> _instances;
        std::map<int, std::string> _libraryFilesPath;
    private:
        void get_all_filepath(const std::string &path);
        int get_nb_files(std::string filepath);
};
