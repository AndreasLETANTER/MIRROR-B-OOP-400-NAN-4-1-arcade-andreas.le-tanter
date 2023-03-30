#include "Menu.hpp"
#include <unistd.h>
#include <filesystem>

/**
 * @brief Construct a new Menu:: Menu object
*/
Menu::Menu()
{
}

/**
 * @brief Display the Menu
*/
void Menu::DisplayMenu()
{
    char keypressed = 0;
    _ProgramEvents->getCurrentGraphicLibrary()->getInstance()->InitWindow();

    do {
        _WindowMaxSize = _ProgramEvents->getCurrentGraphicLibrary()->getInstance()->GetWindowSize();
        _MenuObjectsData = CreateMenuObjectsData(keypressed);
        _ProgramEvents->getCurrentGraphicLibrary()->getInstance()->displayObjects(_MenuObjectsData);
        DisplayMenuText();
        _ProgramEvents->getCurrentGraphicLibrary()->getInstance()->displayScore(0, _WindowMaxSize.first / 1.20, _WindowMaxSize.second / 1.10);
        _ProgramEvents->getCurrentGraphicLibrary()->getInstance()->display();
        _ProgramEvents->handleEvents();
    } while (_ProgramEvents->getCurrentState() == State::MENU);
}

/**
 * @brief Create the menu objects data
*/
std::map<int, std::pair<Enum::ObjectType, std::pair<int, int>>> Menu::CreateMenuObjectsData(char keypressed)
{
    (void)(keypressed);
    std::map<int, std::pair<Enum::ObjectType, std::pair<int, int>>> _ObjectData;
    int nb_objects = 0;

    for (int i = 0; i <= _WindowMaxSize.first; nb_objects++, i++) {
        _ObjectData[nb_objects] = std::make_pair(Enum::ObjectType::BORDER, std::make_pair(i, 0));
    }
    for (int i = 0; i <= _WindowMaxSize.second; nb_objects++, i++) {
        _ObjectData[nb_objects] = std::make_pair(Enum::ObjectType::BORDER, std::make_pair(0, i));
    }
    for (int i = 0; i <= _WindowMaxSize.first; nb_objects++, i++) {
        _ObjectData[nb_objects] = std::make_pair(Enum::ObjectType::BORDER, std::make_pair(i, _WindowMaxSize.second));
    }
    for (int i = 0; i <= _WindowMaxSize.second; nb_objects++, i++) {
        _ObjectData[nb_objects] = std::make_pair(Enum::ObjectType::BORDER, std::make_pair(_WindowMaxSize.first, i));
    }
    for (int i = 0; i <= _WindowMaxSize.second; nb_objects++, i++) {
        _ObjectData[nb_objects] = std::make_pair(Enum::ObjectType::BORDER, std::make_pair(_WindowMaxSize.first / 2, i));
    }
    for (int i = 0; i <= _WindowMaxSize.first; nb_objects++, i++) {
        _ObjectData[nb_objects] = std::make_pair(Enum::ObjectType::BORDER, std::make_pair(i, _WindowMaxSize.second / 1.25));
    }

    return _ObjectData;
}

/**
 * @brief Display the menu text
*/
void Menu::DisplayMenuText()
{
    _ProgramEvents->getCurrentGraphicLibrary()->getInstance()->displayText("Games Libraries", std::pair<int, int>(_WindowMaxSize.first / 5.5, 2.5), Enum::Color::WHITE, Enum::Color::BLACK);
    if (_ProgramEvents->getInit()->getGamesInstances().size() > 0) {
        displayGamesMenu();
    }
    _ProgramEvents->getCurrentGraphicLibrary()->getInstance()->displayText("Graphics Libraries", std::pair<int, int>(_WindowMaxSize.first / 1.37, 2.5), Enum::Color::WHITE, Enum::Color::BLACK);
    if (_ProgramEvents->getInit()->getGraphicalInstances().size() > 0) {
        displayGraphicalMenu();
    }
    _ProgramEvents->getCurrentGraphicLibrary()->getInstance()->displayText(_ProgramEvents->getCurrentUserName(), std::pair<int, int>(_WindowMaxSize.first / 20, _WindowMaxSize.second / 1.10), Enum::Color::WHITE, Enum::Color::BLACK);
}

/**
 * @brief Display the graphical menu part
*/
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
            _ProgramEvents->getCurrentGraphicLibrary()->getInstance()->displayText(name, std::pair<int, int>(_WindowMaxSize.first / 1.35, idx), Enum::Color::BLACK, Enum::Color::WHITE);
        else
            _ProgramEvents->getCurrentGraphicLibrary()->getInstance()->displayText(name, std::pair<int, int>(_WindowMaxSize.first / 1.35, idx), Enum::Color::WHITE, Enum::Color::BLACK);
        idx += 2;
    }
}

/**
 * @brief Display the games menu part
*/
void Menu::displayGamesMenu()
{
    int idx = 5;
    std::string name;
    std::string current_name = typeid(*_ProgramEvents->getCurrentGameLibrary()->getInstance()).name();
    current_name.erase(0, 1);

    for (auto &p : _ProgramEvents->getInit()->getGamesInstances()) {
        name = typeid(*p.second->getInstance()).name();
        name.erase(0, 1);
        if (current_name == name)
            _ProgramEvents->getCurrentGraphicLibrary()->getInstance()->displayText(name, std::pair<int, int>(_WindowMaxSize.first / 5, idx), Enum::Color::BLACK, Enum::Color::WHITE);
        else
            _ProgramEvents->getCurrentGraphicLibrary()->getInstance()->displayText(name, std::pair<int, int>(_WindowMaxSize.first / 5, idx), Enum::Color::WHITE, Enum::Color::BLACK);
        idx += 2;
    }
}
