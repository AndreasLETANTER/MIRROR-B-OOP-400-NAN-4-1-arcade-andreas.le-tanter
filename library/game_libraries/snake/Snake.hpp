/*
** EPITECH PROJECT, 2023
** MIRROR-B-OOP-400-NAN-4-1-arcade-andreas.le-tanter [WSL : Ubuntu]
** File description:
** snake
*/

#pragma once

#include "../IGameEngine.hpp"
#include "timer/Timer.hpp"

#define MAX_X 120
#define MAX_Y 49
#define STEP_X 45
#define STEP_Y 2

class Snake : public IGameEngine {
    public:
        Snake();
        ~Snake() = default;
        void handleUserInput(char key) override;
        int getScore() override;
        bool getStatus() override;
        Enum::libType GetLibType() override;
        std::map<int, std::pair<Enum::ObjectType, std::pair<int, int>>> getObjects() override;
        void ResetGame() override;
        
    protected:
        int _score;
        bool _is_ended;
        int last_idx = 0;
        int last_player_idx = 0;
        char _last_key = 'd';
        std::map<int, std::pair<Enum::ObjectType, std::pair<int, int>>> _ObjectData;
        std::map<int, std::pair<Enum::ObjectType, std::pair<int, int>>> _PlayerData;
        Timer _timer;
    private:
        void CreateBoxCase(int x, int y, int x_length, int y_length);
        void handlePlayerMovement(char key);
        void GenerateFruit();
        void UpdateGameEvent();
        std::pair<int, int> GetPlayerPos();
        void InitPlayer();
        void erase_element(int idx);
        void AddPlayerPart();
        void AddPlayerToGame();
        void RemoveAllPlayerToGame();
        bool CheckSnakeCollision(std::pair<int, int> player_pos);
        void MoveSnakeTail();
        void MoveWithLastKey();
};
