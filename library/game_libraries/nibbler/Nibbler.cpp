/*
** EPITECH PROJECT, 20BOX_POS_X
** MIRROR-B-OOP-400-NAN-4-1-arcade-andreas.le-tanter [WSL : Ubuntu]
** File description:
** Nibbler
*/

#include "Nibbler.hpp"
#include <ostream>
#include <iostream>

/**
 * @brief Construct a new Nibbler:: Nibbler object
*/
extern "C"
{
    IGameEngine *entryPoint()
    {
        return new Nibbler();
    }
}

/**
 * @brief Init the data needed for displaying the player and its parts
*/
void Nibbler::InitPlayer()
{
    int x = PLAYER_INIT_X;
    int y = PLAYER_INIT_Y;
    _PlayerData[last_player_idx] = std::make_pair(Enum::ObjectType::PLAYER, std::make_pair(x, y));
    last_player_idx++;
    for (int i = 1; i != 4; i++) {
        _PlayerData[last_player_idx] = std::make_pair(Enum::ObjectType::PLAYER_PART, std::make_pair(x - i, y));
        last_player_idx++;
    }
}

/**
 * @brief Chose the direction to carve
 * @details Chose the direction to carve in the _map between North and West
 * @param i Current height
 * @param x Current width
*/
void Nibbler::NorthOrWestPath(int i, int x)
{
    (void)i;
    (void)x;
    _map[i + 1][x + 1] = '*';
    if (rand() > RAND_MAX / 2) {
        _map[i + 1][x] = '*';
        _map[i][x + 1] = 'X';
    } else {
        _map[i][x + 1] = '*';
        _map[i + 1][x] = 'X';
    }
}

/**
 * @brief Carve the path in the _map
 * @details Carve the path in the _map
 * @param height Height of the _map
 * @param width Width of the _map
 * @param i Current height
*/

void Nibbler::CarvePath(int height, int width, int i)
{
    for (int x = 0; x <= width - 1; x++) {
        if (i == 0 || x == 0) {
            _map[i][x] = '*';
            continue;
        }
        if ((_map[i][x] == 'X') && (rand() > RAND_MAX / 2)) {
            _map[i][x] = '*';
        }
        if (_map[i][x] == 'X' || _map[i][x] == '*') {
            continue;
        }
        if (_map[i][x] != '*') {
            _map[i][x] = 'X';
        }
        if (x < width - 1 && i != height) {
            NorthOrWestPath(i, x);
        }
    }
}

/**
 * @brief Destroy Dead Ends in the _map
 * @details Destroy all angular dead end
*/
void Nibbler::DestroyDeadEnds()
{
    for (int i = 0; i <= WIDTH; i++) {
        for (int x = 0; x <= HEIGHT; x++) {
            if (_map[i][x] == 'X' && ((i >= 1 && x == 1) || (i == 1 && x >= 1) || (i >= 1 && x == HEIGHT - 1) || (i == WIDTH - 1 && x >= 1))) {
                _map[i][x] = '*';
                continue;
            }
            if (i != 0 && x != 0) {
                if (_map[i - 1][x] == 'X' && _map[i - 1][x + 1] == 'X' && _map[i][x + 1] == 'X') {
                    if (rand() > RAND_MAX / 2) {
                        _map[i][x] = '*';
                    } else {
                        _map[i][x + 1] = '*';
                    }
                }
                if (_map[i - 1][x] == 'X' && _map[i - 1][x - 1] == 'X' && _map[i][x - 1] == 'X') {
                    if (rand() > RAND_MAX / 2) {
                        _map[i][x] = '*';
                    } else {
                        _map[i][x - 1] = '*';
                    }
                }
                if (_map[i][x - 1] == 'X' && _map[i + 1][x - 1] == 'X' && _map[i + 1][x] == 'X') {
                    _map[i][x] = '*';
                    if (rand() > RAND_MAX / 2) {
                        _map[i][x] = '*';
                    } else {
                        _map[i + 1][x] = '*';
                    }
                }
                if (_map[i][x + 1] == 'X' && _map[i + 1][x + 1] == 'X' && _map[i + 1][x] == 'X') {
                    _map[i][x] = '*';
                    if (rand() > RAND_MAX / 2) {
                        _map[i][x + 1] = '*';
                    } else {
                        _map[i][x] = '*';
                    }
                }
            }
        }
    }
}

/**
 * @brief Generate a random map
*/
void Nibbler::GenerateRandomMap()
{
    for (int i = 0; i <= WIDTH; i++) {
        for (int j = 0; j <= HEIGHT; j++) {
            _map[i][j] = ' ';
        }
    }
    for (int i = 0; i <= WIDTH; i++) {
        CarvePath(WIDTH, HEIGHT, i);
    }
    if (WIDTH % 2 == 0) {
        _map[WIDTH - 1][HEIGHT - 2] = '*';
    }
    if (_map[WIDTH - 1][HEIGHT - 2] == '*' &&
    _map[WIDTH - 2][HEIGHT - 1] == '*') {
        _map[WIDTH - 2][HEIGHT - 1] = 'X';
    }
    _map[WIDTH - 1][HEIGHT - 1] = '*';
   DestroyDeadEnds();
   for (int i = 0; i <= WIDTH; i++) {
        for (int j = 0; j <= HEIGHT; j++) {
            if (_map[i][j] == 'X') {
                _ObjectData[last_idx] = std::make_pair(Enum::ObjectType::BORDER, std::make_pair(i + BOX_POS_X, j + BOX_POS_Y));
                last_idx++;
            }
        }
    }
}

/**
 * @brief Construct a new Nibbler:: Nibbler object
 * @details Init the game and create the border
*/
Nibbler::Nibbler()
{
    _score = 0;
    _is_ended = false;
    InitPlayer();
    CreateBoxCase(BOX_POS_X, BOX_POS_Y, WIDTH, HEIGHT);
    GenerateRandomMap();
    for (int i = 0; i < 10; i++) {
        GenerateFruit();
    }
}

/**
 * @brief Create the border of the game
*/
void Nibbler::CreateBoxCase(int x, int y, int x_length, int y_length)
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
 * @brief check the position of an object
 * @details check if an object is at a specific position
 * @param _type type of the object
 * @param _pos position of the object
 * @return true if the object is at the position
*/
bool Nibbler::CheckObjectPosition(Enum::ObjectType _type, std::pair<int, int> _pos)
{
    for (int i = 0; i < last_idx; i++) {
        if (_ObjectData[i].first == _type && _ObjectData[i].second == _pos) {
            return true;
        }
    }
    return false;
}

/**
 * @brief Restore the player data
 * @details Restore the player data from the previous player data (used for undo)
*/
void Nibbler::RestorePlayerData()
{
    for (int i = 0; i < last_player_idx; i++) {
        _PlayerData[i] = _PreviousPlayerData[i];
    }
}

/**
 * @brief Copy the player data
 * @details Copy the player data to the previous player data (used for undo)
*/
void Nibbler::CopyPlayerData()
{
    for (int i = 0; i < last_player_idx; i++) {
        _PreviousPlayerData[i] = _PlayerData[i];
    }
}

/**
 * @brief Function for redirecting the Nibbler
 * @details This function redirect the nibbler if he is colliding with a wall
*/
void Nibbler::RedirectNibblerIfColliding()
{
    if (_last_key == 'd' && CheckObjectPosition(Enum::ObjectType::BORDER, std::make_pair(_PlayerData[0].second.first, _PlayerData[0].second.second))
                         && CheckObjectPosition(Enum::ObjectType::BORDER, std::make_pair(_PlayerData[0].second.first - 1, _PlayerData[0].second.second + 1))
                         && CheckObjectPosition(Enum::ObjectType::BORDER, std::make_pair(_PlayerData[0].second.first - 1, _PlayerData[0].second.second - 1)) == false) {
        _last_key = 'z';
        _PlayerData[0].second.first -= 1;
        _PlayerData[0].second.second -= 1;
        return;
    }
    if (_last_key == 'd' && CheckObjectPosition(Enum::ObjectType::BORDER, std::make_pair(_PlayerData[0].second.first, _PlayerData[0].second.second))
                         && CheckObjectPosition(Enum::ObjectType::BORDER, std::make_pair(_PlayerData[0].second.first - 1, _PlayerData[0].second.second - 1))
                         && CheckObjectPosition(Enum::ObjectType::BORDER, std::make_pair(_PlayerData[0].second.first + 1, _PlayerData[0].second.second + 1)) == false) {
        _last_key = 's';
        _PlayerData[0].second.first -= 1;
        _PlayerData[0].second.second += 1;
        return;
    }
    if (_last_key == 'd' && CheckObjectPosition(Enum::ObjectType::BORDER, std::make_pair(_PlayerData[0].second.first, _PlayerData[0].second.second))
                         && CheckObjectPosition(Enum::ObjectType::BORDER, std::make_pair(_PlayerData[0].second.first - 1, _PlayerData[0].second.second - 1)) == false
                         && CheckObjectPosition(Enum::ObjectType::BORDER, std::make_pair(_PlayerData[0].second.first + 1, _PlayerData[0].second.second + 1)) == false) {
        RestorePlayerData();
        return;
    }
    if (_last_key == 'z' && CheckObjectPosition(Enum::ObjectType::BORDER, std::make_pair(_PlayerData[0].second.first, _PlayerData[0].second.second))
                         && CheckObjectPosition(Enum::ObjectType::BORDER, std::make_pair(_PlayerData[0].second.first + 1, _PlayerData[0].second.second + 1))
                         && CheckObjectPosition(Enum::ObjectType::BORDER, std::make_pair(_PlayerData[0].second.first + 1, _PlayerData[0].second.second - 1)) == false) {
        _last_key = 'q';
        _PlayerData[0].second.first -= 1;
        _PlayerData[0].second.second += 1;
        return;
    }
    if (_last_key == 'z' && CheckObjectPosition(Enum::ObjectType::BORDER, std::make_pair(_PlayerData[0].second.first, _PlayerData[0].second.second))
                         && CheckObjectPosition(Enum::ObjectType::BORDER, std::make_pair(_PlayerData[0].second.first - 1, _PlayerData[0].second.second + 1))
                         && CheckObjectPosition(Enum::ObjectType::BORDER, std::make_pair(_PlayerData[0].second.first + 1, _PlayerData[0].second.second + 1)) == false) {
        _last_key = 'd';
        _PlayerData[0].second.first += 1;
        _PlayerData[0].second.second += 1;
        return;
    }
    if (_last_key == 'z' && CheckObjectPosition(Enum::ObjectType::BORDER, std::make_pair(_PlayerData[0].second.first, _PlayerData[0].second.second))
                         && CheckObjectPosition(Enum::ObjectType::BORDER, std::make_pair(_PlayerData[0].second.first - 1, _PlayerData[0].second.second + 1)) == false
                         && CheckObjectPosition(Enum::ObjectType::BORDER, std::make_pair(_PlayerData[0].second.first + 1, _PlayerData[0].second.second + 1)) == false) {
        RestorePlayerData();
        return;
    }
    if (_last_key == 'q' && CheckObjectPosition(Enum::ObjectType::BORDER, std::make_pair(_PlayerData[0].second.first, _PlayerData[0].second.second))
                         && CheckObjectPosition(Enum::ObjectType::BORDER, std::make_pair(_PlayerData[0].second.first + 1, _PlayerData[0].second.second - 1))
                         && CheckObjectPosition(Enum::ObjectType::BORDER, std::make_pair(_PlayerData[0].second.first + 1, _PlayerData[0].second.second + 1)) == false) {
        _last_key = 's';
        _PlayerData[0].second.first += 1;
        _PlayerData[0].second.second += 1;
        return;
    }
    if (_last_key == 'q' && CheckObjectPosition(Enum::ObjectType::BORDER, std::make_pair(_PlayerData[0].second.first, _PlayerData[0].second.second))
                         && CheckObjectPosition(Enum::ObjectType::BORDER, std::make_pair(_PlayerData[0].second.first + 1, _PlayerData[0].second.second + 1))
                         && CheckObjectPosition(Enum::ObjectType::BORDER, std::make_pair(_PlayerData[0].second.first + 1, _PlayerData[0].second.second - 1)) == false) {
        _last_key = 'z';
        _PlayerData[0].second.first += 1;
        _PlayerData[0].second.second -= 1;
        return;
    }
    if (_last_key == 'q' && CheckObjectPosition(Enum::ObjectType::BORDER, std::make_pair(_PlayerData[0].second.first, _PlayerData[0].second.second))
                         && CheckObjectPosition(Enum::ObjectType::BORDER, std::make_pair(_PlayerData[0].second.first + 1, _PlayerData[0].second.second - 1)) == false
                         && CheckObjectPosition(Enum::ObjectType::BORDER, std::make_pair(_PlayerData[0].second.first + 1, _PlayerData[0].second.second + 1)) == false) {
        RestorePlayerData();
        return;
    }
    if (_last_key == 's' && CheckObjectPosition(Enum::ObjectType::BORDER, std::make_pair(_PlayerData[0].second.first, _PlayerData[0].second.second))
                         && CheckObjectPosition(Enum::ObjectType::BORDER, std::make_pair(_PlayerData[0].second.first - 1, _PlayerData[0].second.second - 1))
                         && CheckObjectPosition(Enum::ObjectType::BORDER, std::make_pair(_PlayerData[0].second.first + 1, _PlayerData[0].second.second - 1)) == false) {
        _last_key = 'd';
        _PlayerData[0].second.first += 1;
        _PlayerData[0].second.second -= 1;
        return;
    }
    if (_last_key == 's' && CheckObjectPosition(Enum::ObjectType::BORDER, std::make_pair(_PlayerData[0].second.first, _PlayerData[0].second.second))
                         && CheckObjectPosition(Enum::ObjectType::BORDER, std::make_pair(_PlayerData[0].second.first + 1, _PlayerData[0].second.second - 1))
                         && CheckObjectPosition(Enum::ObjectType::BORDER, std::make_pair(_PlayerData[0].second.first - 1, _PlayerData[0].second.second - 1)) == false) {
        _last_key = 'q';
        _PlayerData[0].second.first -= 1;
        _PlayerData[0].second.second -= 1;
        return;
    }
    if (_last_key == 's' && CheckObjectPosition(Enum::ObjectType::BORDER, std::make_pair(_PlayerData[0].second.first, _PlayerData[0].second.second))
                         && CheckObjectPosition(Enum::ObjectType::BORDER, std::make_pair(_PlayerData[0].second.first + 1, _PlayerData[0].second.second - 1)) == false
                         && CheckObjectPosition(Enum::ObjectType::BORDER, std::make_pair(_PlayerData[0].second.first - 1, _PlayerData[0].second.second - 1)) == false) {
        RestorePlayerData();
        return;
    }

}

/**
 * @brief Check if Nibbler is colliding with a wall
 * @return False if he didnt true if he did
*/
bool Nibbler::CheckNibblerCollisionOnGameWalls()
{
    for (int i = 0; i <= last_idx; i++) {
        if (_ObjectData[i].first == Enum::ObjectType::BORDER && _PlayerData[0].second.first == _ObjectData[i].second.first && _PlayerData[0].second.second == _ObjectData[i].second.second) {
            return true;
        }
    }
    return false;
}

/**
 * @brief Check if the player is colliding with the border or itself
 * @param player_pos
 * @return true
 * @return false
*/
bool Nibbler::CheckNibblerCollision(std::pair<int, int> player_pos)
{
    for (int i = 0; i < last_player_idx; i++) {
        if (_PlayerData[i].first == Enum::ObjectType::PLAYER_PART && (_PlayerData[i].second.first == player_pos.first && _PlayerData[i].second.second == player_pos.second)) {
            return true;
        }
    }
    if (CheckNibblerCollisionOnGameWalls() == true) {
        RedirectNibblerIfColliding();
    }
    return false;
}

/**
 * @brief Move the Nibbler tail
 * @details Move the Nibbler tail to the position of the previous part
*/
void Nibbler::MoveNibblerTail()
{
    for (int i = last_player_idx - 1; i >= 0; i--) {
        if (_PlayerData[i].first == Enum::ObjectType::PLAYER_PART) {
            _PlayerData[i].second.first = _PlayerData[i - 1].second.first;
            _PlayerData[i].second.second = _PlayerData[i - 1].second.second;
        }
    }
}

/**
 * @brief Move the Nibbler
 * @details Move the Nibbler to the position asked by the player
*/
void Nibbler::MoveWithLastKey()
{
    if (_last_key == 'z' && _PlayerData[0].second.second > BOX_POS_Y) {
        MoveNibblerTail();
        _PlayerData[0].second.second -= 1;
    } else if (_last_key == 's' && _PlayerData[0].second.second < HEIGHT + BOX_POS_Y) {
        MoveNibblerTail();
        _PlayerData[0].second.second += 1;
    } else if(_last_key == 'q' && _PlayerData[0].second.first > BOX_POS_X) {
        MoveNibblerTail();
        _PlayerData[0].second.first -= 1;
    } else if (_last_key == 'd' && _PlayerData[0].second.first < WIDTH + BOX_POS_X) {
        MoveNibblerTail();
        _PlayerData[0].second.first += 1;
    }
}

/**
 * @brief Move the Nibbler
 * @details Move the Nibbler to the position asked by the player
*/
void Nibbler::handlePlayerMovement(char key)
{
    bool keep_key = true;

    CopyPlayerData();
    if (key == 'z' && _last_key != 's' && _PlayerData[0].second.second > BOX_POS_Y) {
        MoveNibblerTail();
        _PlayerData[0].second.second -= 1;
        _last_key = key;
    } else if (key == 's' && _last_key != 'z' && _PlayerData[0].second.second < HEIGHT + BOX_POS_Y) {
        MoveNibblerTail();
        _PlayerData[0].second.second += 1;
        _last_key = key;
    } else if(key == 'q' && _last_key != 'd' && _PlayerData[0].second.first > BOX_POS_X) {
        MoveNibblerTail();
        _PlayerData[0].second.first -= 1;
        _last_key = key;
    } else if (key == 'd' && _last_key != 'q' && _PlayerData[0].second.first < WIDTH + BOX_POS_X) {
        MoveNibblerTail();
        _PlayerData[0].second.first += 1;
        _last_key = key;
    } else if (key == -1) {
        MoveWithLastKey();
    } else {
        MoveWithLastKey();
        keep_key = false;
    }
    if (CheckNibblerCollision(GetPlayerPos())) {
        _is_ended = true;
    }
    if (key != -1 && keep_key == true)
        _last_key = key;
}

/**
 * @brief Generate a fruit
 * @details Generate a fruit at a random position
*/
void Nibbler::GenerateFruit()
{
    int x = rand() % (WIDTH - 1) + BOX_POS_X + 1;
    int y = rand() % (HEIGHT - 1) + BOX_POS_Y + 1;
    for (int i = 0; i < last_idx; i++) {
        if (_ObjectData[i].second.first == x && _ObjectData[i].second.second == y) {
            GenerateFruit();
            return;
        }
    }
    _ObjectData[last_idx] = std::make_pair(Enum::ObjectType::ITEM, std::make_pair(x, y));
    last_idx++;
}

/**
 * @brief Get the Player Position
 * @return std::pair<int, int>
*/
std::pair<int, int> Nibbler::GetPlayerPos()
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
void Nibbler::erase_element(int idx)
{
    for (int i = idx; i < last_idx; i++) {
        _ObjectData[i] = _ObjectData[i + 1];
        _ObjectData.erase(i + 1);
    }
}

/**
 * @brief Add a player part
*/
void Nibbler::AddPlayerPart()
{
    _PlayerData[last_player_idx] = std::make_pair(Enum::ObjectType::PLAYER_PART, std::make_pair(_PlayerData[last_player_idx - 1].second.first, _PlayerData[last_player_idx - 1].second.second));
    last_player_idx++;
}

/**
 * @brief Update the game event
 * @details Update the game event (check if the player eat a fruit)
*/
void Nibbler::UpdateGameEvent()
{
    int _NbItems = 0;
    std::pair<int, int> player_pos = GetPlayerPos();
    double _time = _timer.GetElapsedTime();

    for (int i = 0; i < last_idx; i++) {
        if (_ObjectData[i].first == Enum::ObjectType::ITEM) {
            _NbItems++;
            if (_ObjectData[i].second.first == player_pos.first && _ObjectData[i].second.second == player_pos.second) {
                erase_element(i);
                last_idx--;
                AddPlayerPart();
                _score += 10;
                _NbItems--;
                _timer.ResetTimer();
                _timer.StartTimer();
            }
        }
    }
    if (_NbItems == 0) {
        PartialReset();
    }
    if (_time >= MAX_TIME) {
        _is_ended = true;
        _timer.ResetTimer();
    }
}

/**
 * @brief Create a Player
*/
void Nibbler::AddPlayerToGame()
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
void Nibbler::RemoveAllPlayerToGame()
{
    int tem = last_idx - 1;
    for (int i = 0; i <= tem; i++) {
        if (_ObjectData[i].first == Enum::ObjectType::PLAYER || _ObjectData[i].first == Enum::ObjectType::PLAYER_PART) {
            erase_element(i);
            last_idx--;
        }
    }
}

/**
 * @brief Reset the map of the game
 * @details Reset entirely the map for the next game party
*/
void Nibbler::ResetMap()
{
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            _map[i][j] = 0;
        }
    }
}

/**
 * @brief Reset the game
 * @details Reset the game to the initial state
*/
void Nibbler::ResetGame()
{
    _score = 0;
    _last_key = 'd';
    last_idx = 0;
    last_player_idx = 0;
    _is_ended = false;
    _ObjectData.clear();
    _PlayerData.clear();
    _PreviousPlayerData.clear();
    ResetMap();
    InitPlayer();
    GenerateRandomMap();
    CreateBoxCase(BOX_POS_X, BOX_POS_Y, WIDTH, HEIGHT);
    for (int i = 0; i < 10; i++) {
        GenerateFruit();
    }
}

/**
 * @brief Partially reset the game
 * @brief reset the everything except the score of the player
*/
void Nibbler::PartialReset()
{
    _last_key = 'd';
    last_idx = 0;
    last_player_idx = 0;
    _is_ended = false;
    _ObjectData.clear();
    _PlayerData.clear();
    _timer.ResetTimer();
    ResetMap();
    InitPlayer();
    GenerateRandomMap();
    CreateBoxCase(BOX_POS_X, BOX_POS_Y, WIDTH, HEIGHT);
    for (int i = 0; i < 10; i++) {
        GenerateFruit();
    }
}

/**
 * @brief Handle the user input
 * @details Handle the user input and update the game
*/
void Nibbler::handleUserInput(char key)
{
    _timer.StartTimer();
    _InputTimer.StartTimer();
    while (_InputTimer.GetElapsedTimeInMilliSeconds() < 100 && key == -1) {
        return;
    }
    _InputTimer.ResetTimer();
    if (key == 'r') {
        ResetGame();
        return;
    }
    handlePlayerMovement(key);
    UpdateGameEvent();
    if (_is_ended == false) {
        RemoveAllPlayerToGame();
        AddPlayerToGame();
    }
}

/**
 * @brief Get the Score
 * @return int
*/
int Nibbler::getScore()
{
    return _score;
}

/**
 * @brief Get the Status
 * @details Get the status of the game (if the game is ended or not)
 * @return bool
*/
bool Nibbler::getStatus()
{
    return _is_ended;
}

/**
 * @brief Get the Lib Type
 * @return Enum::libType
*/
Enum::libType Nibbler::GetLibType()
{
    return Enum::libType::GAME;
}

/**
 * @brief Get the Object Data
 * @return std::map<int, std::pair<Enum::ObjectType, std::pair<int, int>>>
*/
std::map<int, std::pair<Enum::ObjectType, std::pair<int, int>>> Nibbler::getObjects()
{
    return _ObjectData;
}
