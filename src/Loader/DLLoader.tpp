/*
** EPITECH PROJECT, 2023
** BOOTSTRAP_Arcade [WSL : Ubuntu]
** File description:
** DLoader
*/

#include "DLLoader.hpp"
#include "../ErrorClass/ErrorClass.hpp"
#include <dlfcn.h>

template <typename T>
class DLLoader;

/**
 * @brief Open a library with the given path
 * @param libraryPath The path of the library
*/
template <typename T>
void DLLoader<T>::openLibrary(const std::string &libraryPath)
{
    void *handle;

    handle = dlopen(libraryPath.c_str(), RTLD_LAZY);
    if (!handle) {
        throw Error("Error: " + std::string(dlerror()));
    } else {
        _OpenedLibrary = handle;
    }
}

/**
 * @brief Close the opened library
 * @param libraryPath The path of the library
*/
template <typename T>
void DLLoader<T>::closeLibrary(void)
{
    int return_value = dlclose(_OpenedLibrary);

    if (return_value != 0) {
        throw Error("Error: " + std::string(dlerror()));
    }
}

/**
 * @brief Open the instance of the library
*/
template <typename T>
void DLLoader<T>::openInstance(void)
{
    typedef T *(*entryPoint_t)(void);

    entryPoint_t _entryPoint = (entryPoint_t) dlsym(_OpenedLibrary, "entryPoint");

    if (!_entryPoint) {
        fprintf(stderr, "%s\n", dlerror());
        throw Error("Error: " + std::string(dlerror()));
    }
    _instance = _entryPoint();
}

/**
 * @brief Get the instance of the library
*/
template <typename T>
T *DLLoader<T>::getInstance(void)
{
    return _instance;
}
