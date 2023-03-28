/*
** EPITECH PROJECT, 2023
** BOOTSTRAP_Arcade [WSL : Ubuntu]
** File description:
** DLoader
*/

#pragma once
#include <iostream>
#include <string>

/**
 * @brief DLLoader class
*/
template <typename T>
class DLLoader
{
    public:
        DLLoader() {};
        DLLoader(const std::string &libraryName) { openLibrary(libraryName); };
        ~DLLoader() { closeLibrary(); };
        void openLibrary(const std::string &libraryName);
        void openInstance(void);
        void closeLibrary(void);
        T *getInstance(void);
    protected:
        void *_OpenedLibrary;
        T *_instance;
};

#include "DLLoader.tpp"
