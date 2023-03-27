/*
** EPITECH PROJECT, 2023
** MIRROR-B-OOP-400-NAN-4-1-arcade-andreas.le-tanter [WSL : Ubuntu]
** File description:
** snake
*/

#include "Snake.hpp"

extern "C"
{
    IGameEngine *entryPoint()
    {
        return new Snake();
    }
}

void Snake::InitPlayer()
{
    int x = 100;
    int y = 25;

    _PlayerData[last_player_idx] = std::make_pair(Enum::ObjectType::PLAYER, std::make_pair(x, y));
    last_player_idx++;
    for (int i = 1; i != 4; i++) {
        _PlayerData[last_player_idx] = std::make_pair(Enum::ObjectType::PLAYER_PART, std::make_pair(x - i, y));
        last_player_idx++;
    }
}

Snake::Snake()
{
    _score = 0;
    _is_ended = false;
    InitPlayer();
    CreateBoxCase(23, 1, 160, 50);
    for (int i = 0; i < 10; i++) {
        GenerateFruit();
    }
}

void Snake::CreateBoxCase(int x, int y, int x_length, int y_length)
{
    for (int i = x; i <= x_length + x; i++, last_idx++) {
        _ObjectData[last_idx] = std::make_pair(Enum::ObjectType::BORDER, std::make_pair(i, y));
        last_idx++;
        _ObjectData[last_idx] = std::make_pair(Enum::ObjectType::BORDER, std::make_pair(i, y_length + y));
    }
    for (int i = y; i <= y_length + y; i++, last_idx++) {
        _ObjectData[last_idx] = std::make_pair(Enum::ObjectType::BORDER, std::make_pair(x, i));
        last_idx++;
        _ObjectData[last_idx] = std::make_pair(Enum::ObjectType::BORDER, std::make_pair(x_length + x, i));
    }
}

bool Snake::CheckSnakeCollision(std::pair<int, int> player_pos)
{
    for (int i = 0; i < last_player_idx; i++) {
        if (_PlayerData[i].first == Enum::ObjectType::PLAYER_PART && (_PlayerData[i].second.first == player_pos.first && _PlayerData[i].second.second == player_pos.second)) {
            return true;
        }
    }
    return false;
}

void Snake::MoveSnakeTail()
{
    for (int i = last_player_idx - 1; i >= 0; i--) {
        if (_PlayerData[i].first == Enum::ObjectType::PLAYER_PART) {
            _PlayerData[i].second.first = _PlayerData[i - 1].second.first;
            _PlayerData[i].second.second = _PlayerData[i - 1].second.second;
        }
    }
}

void Snake::handlePlayerMovement(char key)
{
    if (key == 'z' && _PlayerData[0].second.second > 1 + 1) {
        MoveSnakeTail();
        _PlayerData[0].second.second -= 1;
    } else if (key == 's' && _PlayerData[0].second.second < 50 + 1 - 1) {
        MoveSnakeTail();
        _PlayerData[0].second.second += 1;
    } else if(key == 'q' && _PlayerData[0].second.first > 23 + 1) {
        MoveSnakeTail();
        _PlayerData[0].second.first -= 1;
    } else if (key == 'd' && _PlayerData[0].second.first < 160 + 23 - 1) {
        MoveSnakeTail();
        _PlayerData[0].second.first += 1;
    }
    if (CheckSnakeCollision(GetPlayerPos())) {
        _is_ended = true;
    }
}

void Snake::GenerateFruit()
{
    int x = rand() % 160 + 23;
    int y = rand() % 50 + 1;
    _ObjectData[last_idx] = std::make_pair(Enum::ObjectType::ITEM, std::make_pair(x, y));
    last_idx++;
}

std::pair<int, int> Snake::GetPlayerPos()
{
    for(int i = 0; i < last_player_idx; i++) {
        if (_PlayerData[i].first == Enum::ObjectType::PLAYER)
            return _PlayerData[i].second;
    }
    return std::make_pair(0, 0);
}

void Snake::erase_element(int idx)
{
    for (int i = idx; i < last_idx - 1; i++) {
        _ObjectData[i] = _ObjectData[i + 1];
        _ObjectData.erase(i + 1);
    }
}

void Snake::AddPlayerPart()
{
    _PlayerData[last_player_idx] = std::make_pair(Enum::ObjectType::PLAYER_PART, std::make_pair(_PlayerData[last_player_idx - 1].second.first, _PlayerData[last_player_idx - 1].second.second));
    last_player_idx++;
}

void Snake::UpdateGameEvent()
{
    std::pair<int, int> player_pos = GetPlayerPos();
    for (int i = 0; i < last_idx; i++) {
        if (_ObjectData[i].first == Enum::ObjectType::ITEM) {
            if (_ObjectData[i].second.first == player_pos.first && _ObjectData[i].second.second == player_pos.second) {
                erase_element(i);
                last_idx--;
                AddPlayerPart();
                GenerateFruit();
                _score++;
            }
        }
    }
}

void Snake::AddPlayerToGame()
{
    for (int i = 0; i < last_player_idx; i++) {
        _ObjectData[last_idx] = _PlayerData[i];
        last_idx++;
    }
}

void Snake::RemoveAllPlayerToGame()
{
    for (int i = 0; i < last_player_idx; i++) {
        _ObjectData.erase(last_idx);
        last_idx--;
    }
}

void Snake::handleUserInput(char key)
{
    RemoveAllPlayerToGame();
    handlePlayerMovement(key);
    UpdateGameEvent();
    AddPlayerToGame();
}

int Snake::getScore()
{
    return _score;
}

bool Snake::getStatus()
{
    return _is_ended;
}

Enum::libType Snake::GetLibType()
{
    return Enum::libType::GAME;
}

std::map<int, std::pair<Enum::ObjectType, std::pair<int, int>>> Snake::getObjects()
{
    return _ObjectData;
}
