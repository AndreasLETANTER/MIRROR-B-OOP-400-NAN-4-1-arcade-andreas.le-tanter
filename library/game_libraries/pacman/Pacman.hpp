/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** handle Pacman
*/
#ifndef ARCADE_PACMAN_HPP
    #define ARCADE_PACMAN_HPP
    #include "../IGameEngine.hpp"

class Pacman : public IGameEngine {
public:
    Pacman();
    ~Pacman();
    void handleUserInput(char key) override;
    int getScore() const override;
    bool getStatus() const override;
    std::map<int, std::pair<ObjectType, std::pair<int, int>>> getObjects() const override;
protected:
    int _score;
    bool _is_ended;
    std::map<int, std::pair<ObjectType, std::pair<int, int>>> test; // <index, <ObjectType, <x, y>>>
};

#endif //ARCADE_PACMAN_HPP
