/*
** EPITECH PROJECT, 2023
** BOOTSTRAP_Arcade [WSL : Ubuntu]
** File description:
** library_gra
*/

#pragma once
#include "../IDisplayModule.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

class LibrarySFML : public IDisplayModule {
    public:
        LibrarySFML() = default;
        ~LibrarySFML() = default;
        void InitWindow() override;
        void FiniWindow() override;
        void displayObjects(std::map<int, std::pair<Enum::ObjectType, std::pair<int, int>>> _ObjectData) override;
        void displayScore(int _Score, int x, int y) override;
        void displayText(std::string _String, std::pair<int, int> _Pos, Enum::Color FrontFont, Enum::Color BackFont) override;
        Enum::libType GetLibType() override;
        std::pair<int, int> GetWindowSize() override;
        char getUserInput() override;
        void display() override;

    protected:
        sf::RenderWindow _CurrentWindow;
        std::map <Enum::Color, sf::Color> _ColorDefinition;
        std::map <Enum::ObjectType, sf::Color> _ObjectDefinition;
        sf::Font _Font;
        sf::Text _Text;
    private:
};
