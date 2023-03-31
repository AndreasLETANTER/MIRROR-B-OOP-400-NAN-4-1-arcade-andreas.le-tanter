/*
** EPITECH PROJECT, 2023
** MIRROR-B-OOP-400-NAN-4-1-arcade-andreas.le-tanter [WSL : Ubuntu]
** File description:
** ErrorClass
*/

#include "ErrorClass.hpp"

const char *Error::what() const noexcept
{
    return this->_message.c_str();
}
