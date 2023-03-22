/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** Game Engine header file
*/
#ifndef ARCADE_IGAMEENGINE_HPP
    #define ARCADE_IGAMEENGINE_HPP
    #include <map>
enum class ObjectType {
    PLAYER,
    PLAYER_PART,
    ENEMY,
    ITEM,
    BORDER
};

class IGameEngine {
public:
    virtual ~IGameEngine() = default;
    virtual void handleUserInput(char key) = 0;
    virtual int getScore() const = 0;
    virtual bool getStatus() const = 0;
    virtual std::map<int, std::pair<ObjectType, std::pair<int, int>>> getObjects() const = 0;
};
#endif //ARCADE_IGAMEENGINE_HPP
