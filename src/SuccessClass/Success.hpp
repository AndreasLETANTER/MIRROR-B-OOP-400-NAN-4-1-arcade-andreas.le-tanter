/*
** EPITECH PROJECT, 2023
** MIRROR-B-OOP-400-NAN-4-1-arcade-andreas.le-tanter [WSL : Ubuntu]
** File description:
** Success
*/

#pragma once
#include <string>

class Success : public std::exception
{
    public:
        Success(std::string message) { this->_message = message; };
        const char *what() const noexcept;

    protected:
        std::string _message;
    private:
};
