/*
** EPITECH PROJECT, 2023
** MIRROR-B-OOP-400-NAN-4-1-arcade-andreas.le-tanter [WSL : Ubuntu]
** File description:
** snake
*/

#pragma once

#include "../IGameEngine.hpp"

class Snake : public IGameEngine {
    public:
        Snake();
        ~Snake() = default;
        void handleUserInput(char key) override;
        int getScore() override;
        bool getStatus() override;
        Enum::libType GetLibType();
        std::map<int, std::pair<Enum::ObjectType, std::pair<int, int>>> getObjects() override;
        
    protected:
        int _score;
        bool _is_ended;
        int last_idx = 0;
        std::map<int, std::pair<Enum::ObjectType, std::pair<int, int>>> _ObjectData;
    private:
        void CreateBoxCase(int x, int y, int x_length, int y_length);
        void handlePlayerMovement(char key);
        void GenerateFruit();
};
