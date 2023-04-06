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
#include "../../../src/ErrorClass/ErrorClass.hpp"
#include "arial.cpp"

/**
 * @brief Entry point of the library
*/
extern "C"
{
    IDisplayModule *entryPoint()
    {
        return new LibrarySFML();
    }
}

/**
 * @brief constructor of the library
*/
LibrarySFML::LibrarySFML()
{
    if (!_Font.loadFromMemory(arial_ttf, arial_ttf_len)) {
        throw Error("Error: Font not found");
    };
}

/**
 * @brief Init the window
*/
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

    _Text.setCharacterSize(28);
    _Text.setFont(_Font);
}

/**
 * @brief fini the window
*/
void LibrarySFML::FiniWindow()
{
    _ObjectDefinition.clear();
    _ColorDefinition.clear();
    _CurrentWindow.close();
}

/**
 * @brief display the objects
 * @details display the objects on the screen
 * @param _ObjectData
*/
void LibrarySFML::displayObjects(std::map<int, std::pair<Enum::ObjectType, std::pair<int, int>>> _ObjectData)
{
    _CurrentWindow.clear(sf::Color(44, 102, 110, 255));

    for (auto &it : _ObjectData) {
        sf::RectangleShape rectangle(sf::Vector2f(CHAR_SIZE_X, CHAR_SIZE_Y));
        sf::Vector2f sfmlPos = sf::Vector2f((_ObjectData[it.first].second.first * CHAR_SIZE_X), (_ObjectData[it.first].second.second * CHAR_SIZE_Y));
        rectangle.setFillColor(_ObjectDefinition[_ObjectData[it.first].first]);
        rectangle.setPosition(sfmlPos.x, sfmlPos.y);
        _CurrentWindow.draw(rectangle);
    }
}

/**
 * @brief display the score
 * @details display the score on the screen
 * @param _Score
 * @param x
 * @param y
*/
void LibrarySFML::displayScore(int _Score, int x, int y)
{
    sf::Vector2f sfmlPos = sf::Vector2f(x * CHAR_SIZE_X, y * CHAR_SIZE_Y);
    _Text.setString("Score: " + std::to_string(_Score));
    _Text.setPosition(sfmlPos.x, sfmlPos.y);
    _Text.setFillColor(_ColorDefinition[Enum::Color::WHITE]);
    _Text.setOutlineColor(_ColorDefinition[Enum::Color::BLACK]);

    _CurrentWindow.draw(_Text);
}

/**
 * @brief display the text
 * @details display the text on the screen
 * @param _String
 * @param _Pos
 * @param FrontFont
 * @param BackFont
*/
void LibrarySFML::displayText(std::string _String, std::pair<int, int> _Pos, Enum::Color FrontFont, Enum::Color BackFont)
{
    sf::Vector2f sfmlPos = sf::Vector2f(_Pos.first * CHAR_SIZE_X, _Pos.second * CHAR_SIZE_Y);
    _Text.setString(_String);
    _Text.setPosition(sfmlPos.x, sfmlPos.y);
    _Text.setFillColor(_ColorDefinition[FrontFont]);
    _Text.setOutlineColor(_ColorDefinition[BackFont]);

    _CurrentWindow.draw(_Text);
}

/**
 * @brief get the lib type
 * @details get the lib type (graphic or game)
 * @return Enum::libType
*/
Enum::libType LibrarySFML::GetLibType()
{
    return Enum::libType::GRAPHIC;
}

/**
 * @brief get the window size
 * @return std::pair<int, int>
*/
std::pair<int, int> LibrarySFML::GetWindowSize()
{
    sf::Vector2u size = _CurrentWindow.getSize();

    return (std::pair<int, int>(size.x, size.y));
}

/**
 * @brief get the user input
 * @details get the user input
 * @return char
*/
char LibrarySFML::getUserInput()
{
    sf::Event event;

    _CurrentWindow.pollEvent(event);
    if (event.type == sf::Event::Closed) {
        _CurrentWindow.close();
        return -1;
    }
    if (event.type == sf::Event::TextEntered) {
        if (event.text.unicode == 13) {
            return 10;
        } else if (event.text.unicode < 128) {
            return static_cast<char>(event.text.unicode);
        }
    }
    return -1;
}

/**
 * @brief display the window
*/
void LibrarySFML::display()
{
    _CurrentWindow.display();
}
