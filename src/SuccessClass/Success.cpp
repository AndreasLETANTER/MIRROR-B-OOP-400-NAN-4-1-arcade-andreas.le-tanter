/*
** EPITECH PROJECT, 2023
** MIRROR-B-OOP-400-NAN-4-1-arcade-andreas.le-tanter [WSL : Ubuntu]
** File description:
** Success
*/

#include "Success.hpp"

/**
 * @brief Return the success message
 */
const char *Success::what() const noexcept
{
    return this->_message.c_str();
}
