/*
** EPITECH PROJECT, 2023
** BOOTSTRAP_Arcade [WSL : Ubuntu]
** File description:
** library_ncurses
*/

#include <unistd.h>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include "library_sfml.hpp"

extern "C"
{
    IDisplayModule *entryPoint()
    {
        return new LibrarySFML();
    }
}

void LibrarySFML::InitWindow()
{
    _CurrentWindow = nullptr;
    _CurrentWindow = new sf::RenderWindow(sf::VideoMode(1920, 1080), "Arcade");

    _CurrentWindow->setFramerateLimit(120);
    _CurrentWindow->setVerticalSyncEnabled(false);
    _CurrentWindow->setKeyRepeatEnabled(false);
    _CurrentWindow->setActive(false);
    _CurrentWindow->setMouseCursorVisible(false);
    _CurrentWindow->setMouseCursorGrabbed(true);
    _CurrentWindow->setPosition(sf::Vector2i(0, 0));
    if (_font.loadFromFile("library/graphic_libraries/sfml/arial.ttf") == false) {
        std::cout << "Error loading font" << std::endl;
    }
    _ColorDefinition[Enum::Color::RED] = sf::Color::Red;
    _ColorDefinition[Enum::Color::GREEN] = sf::Color::Green;
    _ColorDefinition[Enum::Color::BLUE] = sf::Color::Blue;
    _ColorDefinition[Enum::Color::YELLOW] = sf::Color::Yellow;
    _ColorDefinition[Enum::Color::WHITE] = sf::Color::White;
    _ColorDefinition[Enum::Color::BLACK] = sf::Color::Black;
}

void LibrarySFML::FiniWindow()
{
    _CurrentWindow->setActive(false);
    _CurrentWindow->close();
    delete _CurrentWindow;
    _ColorDefinition.clear();
}

void LibrarySFML::displayObjects(std::map<int, std::pair<Enum::ObjectType, std::pair<int, int>>> _ObjectData)
{
    _CurrentWindow->clear(sf::Color(44, 102, 110, 255));
    std::map<Enum::ObjectType, std::string> _ObjectTypeDefinition;
    _ObjectTypeDefinition[Enum::ObjectType::PLAYER] = "P";
    _ObjectTypeDefinition[Enum::ObjectType::ENEMY] = "E";
    _ObjectTypeDefinition[Enum::ObjectType::ITEM] = "I";
    _ObjectTypeDefinition[Enum::ObjectType::BORDER] = "#";
    _ObjectTypeDefinition[Enum::ObjectType::PLAYER_PART] = "X";

    for (auto &it : _ObjectData) {
        sf::RectangleShape rectangle(sf::Vector2f(10, 10));

        if (_ObjectData[it.first].first == Enum::ObjectType::PLAYER) {
            rectangle.setFillColor(sf::Color::Green);
        } else if (_ObjectData[it.first].first == Enum::ObjectType::BORDER) {
            rectangle.setFillColor(sf::Color::White);
        } else if (_ObjectData[it.first].first == Enum::ObjectType::ENEMY) {
            rectangle.setFillColor(sf::Color::Red);
        } else if (_ObjectData[it.first].first == Enum::ObjectType::ITEM) {
            rectangle.setFillColor(sf::Color::Yellow);
        } else if (_ObjectData[it.first].first == Enum::ObjectType::PLAYER_PART) {
            rectangle.setFillColor(sf::Color::Blue);
        }
        rectangle.setPosition(_ObjectData[it.first].second.first * 10, _ObjectData[it.first].second.second * 10);
        _CurrentWindow->draw(rectangle);
    }
}

void LibrarySFML::displayScore(int _Score, int x, int y)
{
    (void)_Score;
    (void)x;
    (void)y;
}

void LibrarySFML::displayText(std::string _String, std::pair<int, int> _Pos, Enum::Color FrontFont, Enum::Color BackFont)
{
    _text.setFont(_font);
    _text.setString(_String);
    _text.setCharacterSize(28);
    _text.setFillColor(_ColorDefinition[FrontFont]);
    _text.setPosition(_Pos.first, _Pos.second * 35);
    _CurrentWindow->draw(_text);
    _CurrentWindow->display();
    (void)BackFont;
}

Enum::libType LibrarySFML::GetLibType()
{
    return Enum::libType::GRAPHIC;
}

std::pair<int, int> LibrarySFML::GetWindowSize()
{
    sf::Vector2u size = _CurrentWindow->getSize();

    return (std::pair<int, int>(size.x, size.y));
}

char LibrarySFML::getUserInput()
{
    sf::Event event;

    _CurrentWindow->pollEvent(event);
    if (event.type == sf::Event::Closed) {
        _CurrentWindow->close();
        return -1;
    }
    if (event.type == sf::Event::TextEntered) {
        if (event.text.unicode < 128) {
            return static_cast<char>(event.text.unicode);
        }
    }
    return -1;
}
