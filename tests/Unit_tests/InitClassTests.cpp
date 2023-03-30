/*
** EPITECH PROJECT, 2023
** MIRROR-B-OOP-400-NAN-4-1-arcade-andreas.le-tanter [WSL : Ubuntu]
** File description:
** InitClassTests
*/

#include <criterion/criterion.h>
#include <iostream>
#include <memory>
#include "../../src/InitClass/Init.hpp"
#include<unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>

Test(Louis, test_1)
{
    cr_assert_eq(1, 1);
}