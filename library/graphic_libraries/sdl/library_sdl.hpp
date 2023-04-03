/*
** EPITECH PROJECT, 2023
** BOOTSTRAP_Arcade [WSL : Ubuntu]
** File description:
** library_gra
*/

#pragma once
#include "../IDisplayModule.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#define CHAR_SIZE_X 9.18
#define CHAR_SIZE_Y 19.7
#define BACKGROUND_COLOR 128, 123, 232, 0

class LibrarySDL : public IDisplayModule {
    public:
        LibrarySDL();
        ~LibrarySDL() = default;
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
        SDL_Window *_CurrentWindow;
        SDL_Renderer *_CurrentWindowRenderer;
        TTF_Font *_Font;
        std::map<Enum::Color, SDL_Color> _ColorDefinition;
    private:
};
