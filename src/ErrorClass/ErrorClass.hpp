/*
** EPITECH PROJECT, 2023
** MIRROR-B-OOP-400-NAN-4-1-arcade-andreas.le-tanter [WSL : Ubuntu]
** File description:
** ErrorClass
*/

#pragma once
#include <string>

class Error : public std::exception
{
    public:
        Error(std::string message) { this->_message = message; };
        const char *what() const noexcept;

    protected:
        std::string _message;
    private:
};
