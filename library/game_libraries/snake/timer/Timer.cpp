/*
** EPITECH PROJECT, 2023
** MIRROR-B-OOP-400-NAN-4-1-arcade-andreas.le-tanter [WSL: Ubuntu]
** File description:
** Timer
*/

#include "Timer.hpp"

/**
 * @brief Start the timer
 * @details Start the timer and set the _is_started boolean to true
*/
void Timer::StartTimer() {
    if (_is_started)
        return;
    _start = std::chrono::system_clock::now();
    _is_started = true;
}

/**
 * @brief Get the Elapsed Time object
 * @details Get the elapsed time in seconds
 * @return double
*/
double Timer::GetElapsedTime() {
    std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();
    return std::chrono::duration_cast<std::chrono::seconds>(end - _start).count();
}

/**
 * @brief Get the Elapsed Time In Milli Seconds object
 * @details Get the elapsed time in milliseconds
 * @return double
*/
double Timer::GetElapsedTimeInMilliSeconds() {
    std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();
    return std::chrono::duration_cast<std::chrono::milliseconds>(end - _start).count();
}

/**
 * @brief Get the Elapsed Time In Micro Seconds object
 * @details Get the elapsed time in microseconds
 * @return double
*/
double Timer::GetElapsedTimeInMicroSeconds() {
    std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();
    return std::chrono::duration_cast<std::chrono::microseconds>(end - _start).count();
}

/**
 * @brief Reset the timer
 * @details Reset the timer and set the _is_started boolean to false
*/
void Timer::ResetTimer() {
    _start = std::chrono::system_clock::now();
    _is_started = false;
}
