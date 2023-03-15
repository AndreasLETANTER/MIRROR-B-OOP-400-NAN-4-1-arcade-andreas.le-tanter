/*
** EPITECH PROJECT, 2023
** BOOTSTRAP_Arcade [WSL : Ubuntu]
** File description:
** main
*/

#include <iostream>
#include <memory>
#include "InitClass/Init.hpp"

static std::map<int, std::pair<ObjectType, std::pair<int, int>>> GameSimulation(int keypressed)
{
    std::map<int, std::pair<ObjectType, std::pair<int, int>>> _ObjectData;
    (void)(keypressed);

    _ObjectData[0] = std::make_pair(ObjectType::PLAYER, std::make_pair(10,  20));
    _ObjectData[1] = std::make_pair(ObjectType::ENEMY, std::make_pair(5, 20));
    _ObjectData[3] = std::make_pair(ObjectType::ITEM, std::make_pair(8, 30));
    _ObjectData[4] = std::make_pair(ObjectType::ITEM, std::make_pair(10, 60));

    return _ObjectData;
}

int main(int argc, char **argv)
{
    (void)argc;
    (void)argv;
    std::shared_ptr<IInit> _Init = std::make_shared<Init>("lib/");
    std::cout << _Init->getGraphicalInstances()[0]->getInstance()->getName() << std::endl;
    _Init->getGraphicalInstances()[0]->getInstance()->init();
    _Init->getGraphicalInstances()[0]->getInstance()->displayObjects(GameSimulation(0));
    _Init->getGraphicalInstances()[0]->getInstance()->displayScore(0);
    getchar();
}
