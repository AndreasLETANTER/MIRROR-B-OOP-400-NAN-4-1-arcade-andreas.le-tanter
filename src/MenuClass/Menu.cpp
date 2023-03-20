#include "Menu.hpp"
#include <unistd.h>
#include <filesystem>

Menu::Menu()
{
}

void Menu::DisplayMenu()
{
    char keypressed = 0;
    _ProgramEvents->getCurrentGraphicLibrary()->getInstance()->InitWindow();

    do {
        _WindowMaxSize = _ProgramEvents->getCurrentGraphicLibrary()->getInstance()->GetWindowSize();
        _MenuObjectsData = CreateMenuObjectsData(keypressed);
        _ProgramEvents->getCurrentGraphicLibrary()->getInstance()->displayObjects(_MenuObjectsData);
        DisplayMenuText();
        _ProgramEvents->getCurrentGraphicLibrary()->getInstance()->displayScore(0, _WindowMaxSize.first / 1.35, _WindowMaxSize.second / 1.10);
        _ProgramEvents->handleEvents();
    } while (_ProgramEvents->getCurrentState() == State::MENU);
}

std::map<int, std::pair<ObjectType, std::pair<int, int>>> Menu::CreateMenuObjectsData(char keypressed)
{
    (void)(keypressed);
    std::map<int, std::pair<ObjectType, std::pair<int, int>>> _ObjectData;
    int nb_objects = 0;

    for (int i = 0; i <= _WindowMaxSize.first; nb_objects++, i++) {
        _ObjectData[nb_objects] = std::make_pair(ObjectType::BORDER, std::make_pair(i, 0));
    }
    for (int i = 0; i <= _WindowMaxSize.second; nb_objects++, i++) {
        _ObjectData[nb_objects] = std::make_pair(ObjectType::BORDER, std::make_pair(0, i));
    }
    for (int i = 0; i <= _WindowMaxSize.first; nb_objects++, i++) {
        _ObjectData[nb_objects] = std::make_pair(ObjectType::BORDER, std::make_pair(i, _WindowMaxSize.second));
    }
    for (int i = 0; i <= _WindowMaxSize.second; nb_objects++, i++) {
        _ObjectData[nb_objects] = std::make_pair(ObjectType::BORDER, std::make_pair(_WindowMaxSize.first, i));
    }
    for (int i = 0; i <= _WindowMaxSize.second; nb_objects++, i++) {
        _ObjectData[nb_objects] = std::make_pair(ObjectType::BORDER, std::make_pair(_WindowMaxSize.first / 2, i));
    }
    for (int i = 0; i <= _WindowMaxSize.first; nb_objects++, i++) {
        _ObjectData[nb_objects] = std::make_pair(ObjectType::BORDER, std::make_pair(i, _WindowMaxSize.second / 1.25));
    }

    return _ObjectData;
}

void Menu::DisplayMenuText()
{
    _ProgramEvents->getCurrentGraphicLibrary()->getInstance()->displayText("Games Libraries", std::pair<int, int>(_WindowMaxSize.first / 4.5, 3), Color::WHITE, Color::BLACK);
    if (_ProgramEvents->getCurrentGameLibrary() != nullptr) {
        displayGamesMenu();
    }
    _ProgramEvents->getCurrentGraphicLibrary()->getInstance()->displayText("Graphics Libraries", std::pair<int, int>(_WindowMaxSize.first / 1.37, 3), Color::WHITE, Color::BLACK);
    if (_ProgramEvents->getCurrentGraphicLibrary() != nullptr) {
        displayGraphicalMenu();
    }
    _ProgramEvents->getCurrentGraphicLibrary()->getInstance()->displayText(_ProgramEvents->getCurrentUserName(), std::pair<int, int>(_WindowMaxSize.first / 20, _WindowMaxSize.second / 1.10), Color::WHITE, Color::BLACK);
}

void Menu::displayGraphicalMenu()
{
    int idx = 5;
    std::string name;
    std::string current_name = typeid(*_ProgramEvents->getCurrentGraphicLibrary()->getInstance()).name();
    current_name.erase(0, 2);

    for (auto &p : _ProgramEvents->getInit()->getGraphicalInstances()) {
        name = typeid(*p.second->getInstance()).name();
        name.erase(0, 2);
        if (current_name == name)
            _ProgramEvents->getCurrentGraphicLibrary()->getInstance()->displayText(name, std::pair<int, int>(_WindowMaxSize.first / 1.73, idx), Color::BLACK, Color::WHITE);
        else
            _ProgramEvents->getCurrentGraphicLibrary()->getInstance()->displayText(name, std::pair<int, int>(_WindowMaxSize.first / 1.73, idx), Color::WHITE, Color::BLACK);
        idx += 2;
    }
}

void Menu::displayGamesMenu()
{
    int idx = 5;
    std::string name;
    std::string current_name = typeid(*_ProgramEvents->getCurrentGameLibrary()->getInstance()).name();
    current_name.erase(0, 2);

    for (auto &p : _ProgramEvents->getInit()->getGamesInstances()) {
        name = typeid(*p.second->getInstance()).name();
        name.erase(0, 2);
        if (current_name == name)
            _ProgramEvents->getCurrentGraphicLibrary()->getInstance()->displayText(name, std::pair<int, int>(_WindowMaxSize.first / 20, idx), Color::BLACK, Color::WHITE);
        else
            _ProgramEvents->getCurrentGraphicLibrary()->getInstance()->displayText(name, std::pair<int, int>(_WindowMaxSize.first / 20, idx), Color::WHITE, Color::BLACK);
        idx += 2;
    }

}
