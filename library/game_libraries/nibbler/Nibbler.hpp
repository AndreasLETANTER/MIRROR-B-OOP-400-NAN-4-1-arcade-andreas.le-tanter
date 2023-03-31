/*
** EPITECH PROJECT, 2023
** MIRROR-B-OOP-400-NAN-4-1-arcade-andreas.le-tanter [WSL : Ubuntu]
** File description:
** Nibbler
*/

#pragma once
#include "../IGameEngine.hpp"

#define HEIGHT 25
#define BOX_POS_X 80
#define BOX_POS_Y 15
#define WIDTH 50
#define PLAYER_INIT_Y 39
#define PLAYER_INIT_X 107

enum DIRECTION {
    NORTH,
    WEST,
    EAST,
    SOUTH
};

class Nibbler : public IGameEngine {
    public:
        Nibbler();
        ~Nibbler() = default;
        void handleUserInput(char key) override;
        int getScore() override;
        bool getStatus() override;
        Enum::libType GetLibType() override;
        std::map<int, std::pair<Enum::ObjectType, std::pair<int, int>>> getObjects() override;
        void ResetGame();
        
    protected:
        int _score;
        bool _is_ended;
        int last_idx = 0;
        int last_player_idx = 0;
        DIRECTION _currentDirection;
        char _last_key = 'd';

        std::map<int, std::pair<Enum::ObjectType, std::pair<int, int>>> _ObjectData;
        std::map<int, std::pair<Enum::ObjectType, std::pair<int, int>>> _PlayerData;
        char _map[160][50];
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
        bool CheckNibblerCollision(std::pair<int, int> player_pos);
        void MoveNibblerTail();
        void MoveWithLastKey();
        void GenerateRandomMap();
        void CarvePath(int height, int width, int i);
        void NorthOrWestPath(int i, int x);
        void DestroyDeadEnds();
        void ResetMap();
        void RedirectNibblerIfColliding();
};
