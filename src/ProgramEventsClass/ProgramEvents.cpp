/*
** EPITECH PROJECT, 2023
** MIRROR-B-OOP-400-NAN-4-1-arcade-andreas.le-tanter [WSL : Ubuntu]
** File description:
** ProgramEvents
*/

#include "ProgramEvents.hpp"

ProgramEvents::ProgramEvents()
{
    _ProgramEventsMap['l'] = [](ProgramEvents *_ProgramEvents){ return _ProgramEvents->SwapGraphicLib(); };
    _ProgramEventsMap['k'] = [](ProgramEvents *_ProgramEvents){ return _ProgramEvents->SwapGameLib(); };
    _ProgramEventsMap['r'] = [](ProgramEvents *_ProgramEvents){ return _ProgramEvents->RestartGame(); };
    _ProgramEventsMap['m'] = [](ProgramEvents *_ProgramEvents){ return _ProgramEvents->GoToMenu(); };
    _ProgramEventsMap['e'] = [](ProgramEvents *_ProgramEvents){ return _ProgramEvents->Exit(); };
    _Init = new Init("lib/");
    currentGraphicLibrary = _Init->getGraphicalInstances()[0];
    if (_Init->getGamesInstances().size() > 0)
        currentGameLibrary = _Init->getGamesInstances()[0];
    _currentUserName = "UserName: ";
}

ProgramEvents::~ProgramEvents()
{

}

char ProgramEvents::handleEvent(int key)
{
    if (_ProgramEventsMap.find(key) == _ProgramEventsMap.end())
        return key;
    return _ProgramEventsMap[key](this);
}

char ProgramEvents::SwapGraphicLib(void)
{
    return 0;
}

char ProgramEvents::SwapGameLib(void)
{
    return 0;
}

char ProgramEvents::RestartGame(void)
{
    return 0;
}

char ProgramEvents::GoToMenu(void)
{
    return 0;
}

char ProgramEvents::Exit(void)
{
    currentGraphicLibrary->getInstance()->FiniWindow();
    exit(0);
}
