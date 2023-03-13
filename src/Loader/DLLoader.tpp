/*
** EPITECH PROJECT, 2023
** BOOTSTRAP_Arcade [WSL : Ubuntu]
** File description:
** DLoader
*/

#include "DLLoader.hpp"
#include <dlfcn.h>

template <typename T>
class DLLoader;

template <typename T>
void DLLoader<T>::openLibrary(const std::string &libraryPath)
{
    void *handle;

    handle = dlopen(libraryPath.c_str(), RTLD_LAZY);
    if (!handle) {
        fprintf(stderr, "%s\n", dlerror());
        exit(84);
    } else {
        _OpenedLibrary = handle;
    }
}

template <typename T>
void DLLoader<T>::closeLibrary(void)
{
    dlclose(_OpenedLibrary);
}

template <typename T>
void DLLoader<T>::openInstance(void)
{
    typedef T *(*entryPoint_t)(void);

    entryPoint_t _entryPoint = (entryPoint_t) dlsym(_OpenedLibrary, "entryPoint");
    _instance = _entryPoint();
}

template <typename T>
T *DLLoader<T>::getInstance(void)
{
    return _instance;
}
