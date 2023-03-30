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
    _CurrentWindow.create(sf::VideoMode(1920, 1080), "Arcade", sf::Style::Fullscreen);

    _CurrentWindow.setVerticalSyncEnabled(false);

    _ColorDefinition[Enum::Color::RED] = sf::Color::Red;
    _ColorDefinition[Enum::Color::GREEN] = sf::Color::Green;
    _ColorDefinition[Enum::Color::BLUE] = sf::Color::Blue;
    _ColorDefinition[Enum::Color::YELLOW] = sf::Color::Yellow;
    _ColorDefinition[Enum::Color::WHITE] = sf::Color::White;
    _ColorDefinition[Enum::Color::BLACK] = sf::Color::Black;

    _ObjectDefinition[Enum::ObjectType::PLAYER] = sf::Color::Green;
    _ObjectDefinition[Enum::ObjectType::ENEMY] = sf::Color::Red;
    _ObjectDefinition[Enum::ObjectType::ITEM] = sf::Color::Yellow;
    _ObjectDefinition[Enum::ObjectType::BORDER] = sf::Color::White;
    _ObjectDefinition[Enum::ObjectType::PLAYER_PART] = sf::Color::Blue;

    if (!_Font.loadFromFile("library/graphic_libraries/sfml/arial.ttf")) {
        std::cout << "Error loading font" << std::endl;
        exit(84);
    }

    _Text.setCharacterSize(28);
    _Text.setFont(_Font);
}

void LibrarySFML::FiniWindow()
{
    _ObjectDefinition.clear();
    _ColorDefinition.clear();
    _CurrentWindow.close();
}

void LibrarySFML::displayObjects(std::map<int, std::pair<Enum::ObjectType, std::pair<int, int>>> _ObjectData)
{
    _CurrentWindow.clear(sf::Color(44, 102, 110, 255));

    for (auto &it : _ObjectData) {
        sf::RectangleShape rectangle(sf::Vector2f(10, 10));

        rectangle.setFillColor(_ObjectDefinition[_ObjectData[it.first].first]);
        rectangle.setPosition(_ObjectData[it.first].second.first * 10, _ObjectData[it.first].second.second * 10);
        _CurrentWindow.draw(rectangle);
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
    _Text.setString(_String);
    _Text.setPosition(_Pos.first, _Pos.second * 35);
    _Text.setFillColor(_ColorDefinition[FrontFont]);
    _Text.setOutlineColor(_ColorDefinition[BackFont]);

    _CurrentWindow.draw(_Text);
}

Enum::libType LibrarySFML::GetLibType()
{
    return Enum::libType::GRAPHIC;
}

std::pair<int, int> LibrarySFML::GetWindowSize()
{
    sf::Vector2u size = _CurrentWindow.getSize();

    return (std::pair<int, int>(size.x, size.y));
}

char LibrarySFML::getUserInput()
{
    sf::Event event;

    _CurrentWindow.pollEvent(event);
    if (event.type == sf::Event::Closed) {
        _CurrentWindow.close();
        return -1;
    }
    if (event.type == sf::Event::TextEntered) {
        if (event.text.unicode < 128) {
            return static_cast<char>(event.text.unicode);
        }
    }
    return -1;
}

void LibrarySFML::display()
{
    _CurrentWindow.display();
}
