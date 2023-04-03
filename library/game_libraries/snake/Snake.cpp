/*
** EPITECH PROJECT, 2023
** MIRROR-B-OOP-400-NAN-4-1-arcade-andreas.le-tanter [WSL : Ubuntu]
** File description:
** snake
*/

#include "Snake.hpp"

/**
 * @brief Construct a new Snake:: Snake object
*/
extern "C"
{
    IGameEngine *entryPoint()
    {
        return new Snake();
    }
}

/**
 * @brief Init the data needed for displaying the player and its parts
*/
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

/**
 * @brief Construct a new Snake:: Snake object
 * @details Init the game and create the border
*/
Snake::Snake()
{
    _score = 0;
    _is_ended = false;
    InitPlayer();
    CreateBoxCase(STEP_X, STEP_Y, MAX_X, MAX_Y);
    for (int i = 0; i < 10; i++) {
        GenerateFruit();
    }
}

/**
 * @brief Create the border of the game
*/
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

/**
 * @brief Check if the player is colliding with the border or itself
 * @param player_pos
 * @return true
 * @return false
*/
bool Snake::CheckSnakeCollision(std::pair<int, int> player_pos)
{
    for (int i = 0; i < last_player_idx; i++) {
        if (_PlayerData[i].first == Enum::ObjectType::PLAYER_PART && (_PlayerData[i].second.first == player_pos.first && _PlayerData[i].second.second == player_pos.second)) {
            return true;
        }
    }
    if (!(_PlayerData[0].second.second > STEP_Y + 1 && _PlayerData[0].second.second < MAX_Y + STEP_Y - 1 && _PlayerData[0].second.first > STEP_X + 1 && _PlayerData[0].second.first < MAX_X + STEP_X - 1)) {
        return true;
    }
    return false;
}

/**
 * @brief Move the snake tail
 * @details Move the snake tail to the position of the previous part
*/
void Snake::MoveSnakeTail()
{
    for (int i = last_player_idx - 1; i >= 0; i--) {
        if (_PlayerData[i].first == Enum::ObjectType::PLAYER_PART) {
            _PlayerData[i].second.first = _PlayerData[i - 1].second.first;
            _PlayerData[i].second.second = _PlayerData[i - 1].second.second;
        }
    }
}

/**
 * @brief Move the snake
 * @details Move the snake to the position asked by the player
*/
void Snake::MoveWithLastKey()
{
    if (_last_key == 'z' && _PlayerData[0].second.second > STEP_Y + 1) {
        MoveSnakeTail();
        _PlayerData[0].second.second -= 1;
    } else if (_last_key == 's' && _PlayerData[0].second.second < MAX_Y + STEP_Y - 1) {
        MoveSnakeTail();
        _PlayerData[0].second.second += 1;
    } else if(_last_key == 'q' && _PlayerData[0].second.first > STEP_X + 1) {
        MoveSnakeTail();
        _PlayerData[0].second.first -= 1;
    } else if (_last_key == 'd' && _PlayerData[0].second.first < MAX_X + STEP_X - 1) {
        MoveSnakeTail();
        _PlayerData[0].second.first += 1;
    }
}

/**
 * @brief Move the snake
 * @details Move the snake to the position asked by the player
*/
void Snake::handlePlayerMovement(char key)
{
    bool keep_key = true;

    if (key == 'z' && _last_key != 's' && _PlayerData[0].second.second > STEP_Y + 1) {
        MoveSnakeTail();
        _PlayerData[0].second.second -= 1;
    } else if (key == 's' && _last_key != 'z' && _PlayerData[0].second.second < MAX_Y + STEP_Y - 1) {
        MoveSnakeTail();
        _PlayerData[0].second.second += 1;
    } else if(key == 'q' && _last_key != 'd' && _PlayerData[0].second.first > STEP_X + 1) {
        MoveSnakeTail();
        _PlayerData[0].second.first -= 1;
    } else if (key == 'd' && _last_key != 'q' && _PlayerData[0].second.first < MAX_X + STEP_X - 1) {
        MoveSnakeTail();
        _PlayerData[0].second.first += 1;
    } else if (key == -1) {
        MoveWithLastKey();
    } else {
        MoveWithLastKey();
        keep_key = false;
    }
    if (CheckSnakeCollision(GetPlayerPos())) {
        _is_ended = true;
    }
    if (key != -1 && keep_key == true)
        _last_key = key;
}

/**
 * @brief Generate a fruit
 * @details Generate a fruit at a random position
*/
void Snake::GenerateFruit()
{
    int x = rand() % (MAX_X - 1) + STEP_X + 1;
    int y = rand() % (MAX_Y - 1) + STEP_Y + 1;
    _ObjectData[last_idx] = std::make_pair(Enum::ObjectType::ITEM, std::make_pair(x, y));
    last_idx++;
}

/**
 * @brief Get the Player Position
 * @return std::pair<int, int>
*/
std::pair<int, int> Snake::GetPlayerPos()
{
    for(int i = 0; i < last_player_idx; i++) {
        if (_PlayerData[i].first == Enum::ObjectType::PLAYER)
            return _PlayerData[i].second;
    }
    return std::make_pair(0, 0);
}

/**
 * @brief Delete an element from the object list
 * @details Delete an element from the object list at the given index
 * @param idx
*/
void Snake::erase_element(int idx)
{
    for (int i = idx; i < last_idx - 1; i++) {
        _ObjectData[i] = _ObjectData[i + 1];
        _ObjectData.erase(i + 1);
    }
}

/**
 * @brief Add a player part
*/
void Snake::AddPlayerPart()
{
    _PlayerData[last_player_idx] = std::make_pair(Enum::ObjectType::PLAYER_PART, std::make_pair(_PlayerData[last_player_idx - 1].second.first, _PlayerData[last_player_idx - 1].second.second));
    last_player_idx++;
}

/**
 * @brief Update the game event
 * @details Update the game event (check if the player eat a fruit)
*/
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
                _score += 10;
            }
        }
    }
}

/**
 * @brief Create a Player
*/
void Snake::AddPlayerToGame()
{
    for (int i = 0; i < last_player_idx; i++) {
        _ObjectData[last_idx] = _PlayerData[i];
        last_idx++;
    }
}

/**
 * @brief Remove all player to game
 * @details Remove all player to game and its parts
*/
void Snake::RemoveAllPlayerToGame()
{
    for (int i = 0; i < last_player_idx; i++) {
        _ObjectData.erase(last_idx);
        last_idx--;
    }
}

/**
 * @brief Reset the game
 * @details Reset the game to the initial state
*/
void Snake::ResetGame()
{
    _score = 0;
    _last_key = 'd';
    last_idx = 0;
    last_player_idx = 0;
    _is_ended = false;
    _ObjectData.clear();
    _PlayerData.clear();
    InitPlayer();
    CreateBoxCase(STEP_X, STEP_Y, MAX_X, MAX_Y);
    for (int i = 0; i < 10; i++) {
        GenerateFruit();
    }
}

/**
 * @brief Handle the user input
 * @details Handle the user input and update the game
*/
void Snake::handleUserInput(char key)
{
    if (key == 'r') {
        ResetGame();
        return;
    }
    RemoveAllPlayerToGame();
    handlePlayerMovement(key);
    UpdateGameEvent();
    AddPlayerToGame();
}

/**
 * @brief Get the Score
 * @return int
*/
int Snake::getScore()
{
    return _score;
}

/**
 * @brief Get the Status
 * @details Get the status of the game (if the game is ended or not)
 * @return bool
*/
bool Snake::getStatus()
{
    return _is_ended;
}

/**
 * @brief Get the Lib Type
 * @return Enum::libType
*/
Enum::libType Snake::GetLibType()
{
    return Enum::libType::GAME;
}

/**
 * @brief Get the Object Data
 * @return std::map<int, std::pair<Enum::ObjectType, std::pair<int, int>>>
*/
std::map<int, std::pair<Enum::ObjectType, std::pair<int, int>>> Snake::getObjects()
{
    return _ObjectData;
}
