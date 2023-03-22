/*
** EPITECH PROJECT, 2023
** MIRROR-B-OOP-400-NAN-4-1-arcade-andreas.le-tanter [WSL : Ubuntu]
** File description:
** Init
*/

#pragma once
#include "IInit.hpp"

class Init : public IInit {
    public:
        Init();
        Init(const std::string &path);
        void loadInstances(const std::string &path);
        inline std::map<int, DLLoader<IGameEngine> *> getGamesInstances() { return _GamesInstances; };
        inline std::map<int, DLLoader<IDisplayModule> *> getGraphicalInstances() { return _GraphicalInstances; };

    protected:
        std::map<int, DLLoader<IGameEngine> *> _GamesInstances;
        std::map<int, DLLoader<IDisplayModule> *> _GraphicalInstances;
    private:
        int getNbFiles(const std::string &path);
        void getAllFilePaths(const std::string &path);
        std::map<int, std::string> _libraryFilesPath;
};
