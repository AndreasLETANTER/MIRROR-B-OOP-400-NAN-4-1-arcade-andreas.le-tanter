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
    std::map<int, std::pair<ObjectType, std::pair<int, int>>> _ObjectData;                      //create a map of objects with their positions
    (void)(keypressed);

    _ObjectData[0] = std::make_pair(ObjectType::PLAYER, std::make_pair(20, 10));               //create a player at position 10, 20
    _ObjectData[1] = std::make_pair(ObjectType::ENEMY, std::make_pair(20, 5));                  //create an enemy at position 5, 20
    _ObjectData[3] = std::make_pair(ObjectType::ITEM, std::make_pair(30, 8));                   //create an item at position 8, 30
    _ObjectData[4] = std::make_pair(ObjectType::ITEM, std::make_pair(60, 10));                  //create an item at position 10, 60

    return _ObjectData;                                                                         //return the map
}

int main(int argc, char **argv)
{
    (void)argc;
    (void)argv;
    char keypressed = 0;
    std::shared_ptr<IInit> _Init = std::make_shared<Init>("lib/");                              //create init class with the path to the libraries
    std::cout << _Init->getGraphicalInstances()[0]->getInstance()->GetLibType() << std::endl;   //display lib type

    _Init->getGraphicalInstances()[0]->getInstance()->InitWindow();                             //init window properties
    do {
        _Init->getGraphicalInstances()[0]->getInstance()->displayObjects(GameSimulation(0));    //display objects with their positions based on the simulation
        _Init->getGraphicalInstances()[0]->getInstance()->displayScore(0, 0, 0);                //display score
        keypressed = getchar();                                                                 //get key pressed
    } while (keypressed != 'q');                                                                //quit if q is pressed
}
