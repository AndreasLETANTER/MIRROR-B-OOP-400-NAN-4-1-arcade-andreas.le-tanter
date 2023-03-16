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

Test(InitClass, basic_test)
{
    std::shared_ptr<IInit> _Init = std::make_shared<Init>("lib/");
    bool worked = false;

    if (_Init->getGraphicalInstances().size() > 0)
        worked = true;

    cr_assert_eq(worked, true);
}

Test(InitClass, no_lib_game_test)
{
    std::shared_ptr<IInit> _Init = std::make_shared<Init>("lib/");
    bool worked = false;

    if (_Init->getGamesInstances().size() == 0)
        worked = true;

    cr_assert_eq(worked, true);
}

Test(InitClass, no_folder_lib_test)
{
    bool worked = false;
    int return_value = 0;
    int child_pid = 0;
    int child_status = 0;

    child_pid = fork();

    if (child_pid == 0) {  
        std::shared_ptr<IInit> _Init = std::make_shared<Init>("dqzdqzq");
        exit(0);
    } else {
        waitpid(child_pid, &child_status, 0);
        if (WEXITSTATUS(child_status) != 0)  {
            return_value = WEXITSTATUS(child_status);
        }
    }

    if (return_value == 84)
        worked = true;

    cr_assert_eq(worked, true);
}

Test(InitClass, folder_containing_bad_file_test)
{
    bool worked = false;
    int return_value = 0;
    int child_pid = 0;
    int child_status = 0;

    child_pid = fork();

    if (child_pid == 0) {  
        std::shared_ptr<IInit> _Init = std::make_shared<Init>("src");
        exit(0);
    } else {
        waitpid(child_pid, &child_status, 0);
        if (WEXITSTATUS(child_status) != 0)  {
            return_value = WEXITSTATUS(child_status);
        }
    }

    if (return_value == 84)
        worked = true;

    cr_assert_eq(worked, true);
}

Test(InitClass, empty_folder_test)
{
    bool worked = false;
    int return_value = 0;
    int child_pid = 0;
    int child_status = 0;

    child_pid = fork();
    mkdir("temp", 0777);
    if (child_pid == 0) {  
        std::shared_ptr<IInit> _Init = std::make_shared<Init>("temp");
        exit(0);
    } else {
        waitpid(child_pid, &child_status, 0);
        if (WEXITSTATUS(child_status) != 0)  {
            return_value = WEXITSTATUS(child_status);
        }
    }
    rmdir("temp");
    if (return_value == 0)
        worked = true;

    cr_assert_eq(worked, true);
}