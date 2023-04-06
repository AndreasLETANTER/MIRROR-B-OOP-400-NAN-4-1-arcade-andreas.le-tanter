/*
** EPITECH PROJECT, 2023
** MIRROR-B-OOP-400-NAN-4-1-arcade-andreas.le-tanter [WSL : Ubuntu]
** File description:
** ILibrary
*/

#pragma once

/**
 * @brief Enum class for the different object types
*/
namespace Enum {
    enum class ObjectType {
        PLAYER,
        PLAYER_PART,
        ENEMY,
        ITEM,
        BORDER
    };

    enum class Color {
        RED,
        GREEN,
        BLUE,
        YELLOW,
        WHITE,
        BLACK
    };

    enum libType {
        GRAPHIC,
        GAME
    };
}

/**
 * @brief Interface class for the different libraries
*/
class ILibrary {
    public:
        virtual ~ILibrary() = default;
        virtual Enum::libType GetLibType() = 0;

    protected:
    private:
};
