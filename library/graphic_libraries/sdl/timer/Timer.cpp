/*
** EPITECH PROJECT, 2023
** MIRROR-B-OOP-400-NAN-4-1-arcade-andreas.le-tanter [WSL: Ubuntu]
** File description:
** Timer
*/

#include "Timer.hpp"

void Timer::StartTimer() {
    if (_is_started)
        return;
    _start = std::chrono::system_clock::now();
    _is_started = true;
}

double Timer::GetElapsedTime() {
    std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();
    return std::chrono::duration_cast<std::chrono::seconds>(end - _start).count();
}

double Timer::GetElapsedTimeInMilliSeconds() {
    std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();
    return std::chrono::duration_cast<std::chrono::milliseconds>(end - _start).count();
}

double Timer::GetElapsedTimeInMicroSeconds() {
    std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();
    return std::chrono::duration_cast<std::chrono::microseconds>(end - _start).count();
}

void Timer::ResetTimer() {
    _start = std::chrono::system_clock::now();
    _is_started = false;
}
