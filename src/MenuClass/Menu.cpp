#include "Menu.hpp"
#include <unistd.h>
#include <filesystem>

Menu::Menu()
{
    _Init = new Init("lib/");
    currentGraphicLibrary = _Init->getGraphicalInstances()[0];
    if (_Init->getGamesInstances().size() > 0)
        currentGameLibrary = _Init->getGamesInstances()[0];
    _currentUserName = "UserName: ";
}

void Menu::displayMenu()
{
    char keypressed = 0;
    currentGraphicLibrary->getInstance()->InitWindow();
    _WindowMaxSize = currentGraphicLibrary->getInstance()->GetWindowSize();

    do {
        _MenuObjectsData = CreateMenuObjectsData(keypressed);
        currentGraphicLibrary->getInstance()->displayObjects(_MenuObjectsData);
        displayMenuText();
        currentGraphicLibrary->getInstance()->displayScore(0, _WindowMaxSize.first / 1.35, _WindowMaxSize.second / 1.10);
        keypressed = getchar();
    } while (keypressed != 'q');
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

void Menu::displayMenuText()
{
    displayGamesMenu();
    displayGraphicalMenu();
    currentGraphicLibrary->getInstance()->displayText(_currentUserName, std::pair<int, int>(_WindowMaxSize.first / 20, _WindowMaxSize.second / 1.10), Color::WHITE, Color::BLACK);
}

void Menu::displayGraphicalMenu()
{
    currentGraphicLibrary->getInstance()->displayText("Graphics Libraries", std::pair<int, int>(_WindowMaxSize.first / 1.37, 3), Color::WHITE, Color::BLACK);
    int idx = 5;
    std::string name;
    std::string current_name = typeid(*currentGraphicLibrary->getInstance()).name();
    current_name.erase(0, 2);

    for (auto &p : _Init->getGraphicalInstances()) {
        name = typeid(*p.second->getInstance()).name();
        name.erase(0, 2);
        if (current_name == name)
            currentGraphicLibrary->getInstance()->displayText(name, std::pair<int, int>(_WindowMaxSize.first / 1.73, idx), Color::BLACK, Color::WHITE);
        else
            currentGraphicLibrary->getInstance()->displayText(name, std::pair<int, int>(_WindowMaxSize.first / 1.73, idx), Color::WHITE, Color::BLACK);
        idx += 2;
    }
}

void Menu::displayGamesMenu()
{
    currentGraphicLibrary->getInstance()->displayText("Games Libraries", std::pair<int, int>(_WindowMaxSize.first / 4.5, 3), Color::WHITE, Color::BLACK);
    int idx = 5;
    std::string name;
    std::string current_name = typeid(*currentGraphicLibrary->getInstance()).name();
    current_name.erase(0, 2);

    for (auto &p : _Init->getGamesInstances()) {
        name = typeid(*p.second->getInstance()).name();
        name.erase(0, 2);
        if (current_name == name)
            currentGraphicLibrary->getInstance()->displayText(name, std::pair<int, int>(_WindowMaxSize.first / 20, idx), Color::BLACK, Color::WHITE);
        else
            currentGraphicLibrary->getInstance()->displayText(name, std::pair<int, int>(_WindowMaxSize.first / 20, idx), Color::WHITE, Color::BLACK);
        idx += 2;
    }

}