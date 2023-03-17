/*
** EPITECH PROJECT, 2023
** MIRROR-B-OOP-400-NAN-4-1-arcade-andreas.le-tanter [WSL : Ubuntu]
** File description:
** ProgramEvents
*/

#include "ProgramEvents.hpp"

ProgramEvents::ProgramEvents()
{
    _Init = new Init("lib/");
    currentGraphicLibrary = _Init->getGraphicalInstances()[0];
    if (_Init->getGamesInstances().size() > 0)
        currentGameLibrary = _Init->getGamesInstances()[0];
    _currentUserName = "UserName: ";

    _keyMap['l'] = [](ProgramEvents *_ProgramEvents) { _ProgramEvents->SwapGraphicLib(); };
    _keyMap['k'] = [](ProgramEvents *_ProgramEvents) { _ProgramEvents->SwapGameLib(); };
    _keyMap['u'] = [](ProgramEvents *_ProgramEvents) { _ProgramEvents->ChangeUserName(); };
    _keyMap['m'] = [](ProgramEvents *_ProgramEvents) { _ProgramEvents->GoToMenu(); };
    _keyMap['g'] = [](ProgramEvents *_ProgramEvents) { _ProgramEvents->GoToGame(); };
    _keyMap['e'] = [](ProgramEvents *_ProgramEvents) { _ProgramEvents->Exit(); };
}

ProgramEvents::~ProgramEvents()
{
}

void ProgramEvents::handleEvents()
{
    int keypressed = getchar();

    if (_keyMap.find(keypressed) != _keyMap.end())
        _keyMap[keypressed](this);
}

void ProgramEvents::SwapGraphicLib()
{

}

void ProgramEvents::SwapGameLib()
{

}

void ProgramEvents::ChangeUserName()
{
    _currentUserName = "UserName: Updated";
}

void ProgramEvents::GoToMenu()
{

}

void ProgramEvents::GoToGame()
{

}

void ProgramEvents::Exit()
{
    getCurrentGraphicLibrary()->getInstance()->FiniWindow();
    exit(0);
}
