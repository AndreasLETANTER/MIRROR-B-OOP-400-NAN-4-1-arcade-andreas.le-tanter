---
module:			B-OOP-400
title:			Arcade
subtitle:		Documentation

binary: 		arcade
language:		C++
compilation:	#makefile

author:			Andréas Le Tanter Hugo Noury Louis Barreteau
version:		1.0
---

#imageLeft(arcade.png, 90px, 25)

#space(1)
Arcade is a gaming platform that lets the user choose a game to play and keeps a register of
player scores.
The elements of our gaming plate-form, our graphics libraries and our games dynamic libraries was loaded at run-time.
Each GUI available for the program are shared libraries that are loaded at run-time.#br

#space(1)
#br
#br
#br
#br
#br
#br
#br
#br
#br
#br
#br
#br
#br
#br
#br
#br
#br
#br
#br

## Compilation

**You need to compile your grahic library and game so it create a shared library (.so) and only a shared library (.so) for each of them.**#br#br

#warn(All the assets of the graphic library need to be stored in the memory of the library to avoid multiple files for a single library)

#warn(All the libraries need to be in a lib folder at the root of the arcade binary)

## Information

**Here are all the enum used in the arcade project:**#br#br

```c++
namespace Enum {
    enum class ObjectType {
        PLAYER,
        PLAYER_PART,
        ENEMY,
        ITEM,
        BORDER
    };

    enum class Color {
        RED,
        GREEN,
        BLUE,
        YELLOW,
        WHITE,
        BLACK
    };

    enum libType {
        GRAPHIC,
        GAME
    };
}
```

#space(1)

**The ObjectType enum is used to know what kind of object is displayed.**
**The Color enum is used to know what color is used for the background and the foreground of the text.**
**The libType enum is used to know what kind of library is loaded.**

## Graphic Libraries

#hint(You should clear the window at the start of the displayObjects function and only render your objects in the display function to avoid graphical bugs)

#space(1)
#br

**Graphic libraries needs to contain the following functions for working properly:**#br#br

entryPoint function that return a IDisplayModule object (object of your current library class), the function need to be wrapped in a extern "C":#br

#terminal(#br extern "C" #br IDisplayModule *entryPoint()#br {#br#space(1) return new MyGraphicLibObject();#br }#br)#br

InitWindow function that initialize the window, and all the need to the graphical library to run correctly, such as font, or sprite:#br

#terminal(#br void GraphicName::InitWindow()#br {#br#space(1)#br}#br)#br

FiniWindow function that close and free all elements used by the graphical library and the window (basically it returns in the state before the InitWindow function):#br

#terminal(#br void GraphicName::FiniWindow()#br {#br#space(1)#br}#br)

displayObjects function that display all the object  in the map based on the ObjectType enum at the position given by the pair of int (x, y):#br

#terminal(#br void GraphicName::displayObjects(std::map<int, std::pair<Enum::ObjectType, std::pair<int, int>>> _ObjectData)#br {#br#space(1)#br}#br)#br

displayScore function that display a integer at the pos given in parameter:#br

#terminal(#br void GraphicName::displayScore(int _Score, int x, int y)#br {#br#space(1)#br}#br)#br

displayText function that display a string at a given position with the front color and back color given by the enum Color:#br

#terminal(#br void GraphicName::displayText(std::string _String, std::pair<int, int> _Pos, Enum::Color FrontFont, Enum::Color BackFont)#br {#br#space(1)#br}#br)#br#br#br#br#br#br#br#br#br

GetLibType function that return the type of the library stored in a libType enum for letting the core know if its a graphic library or a game library:#br

#terminal(#br Enum::libType GraphicName::GetLibType()#br {#br#space(1)#br}#br)

GetWindowSize function that return a pair of the height and width of the window:#br

#terminal(#br std::pair<int, int> LibrarySFML::GetWindowSize()#br {#br#space(1)#br}#br)#br

getUserInput function that based on the current graphic library get the user input (key pressed by the user) and return it:#br

#terminal(#br char GraphicName::getUserInput()#br {#br#space(1)#br}#br)#br

display function that render all current drawed object to the window (do not render object in other function it could cause blinking screen):#br

#terminal(#br void GraphicName::display()#br {#br#space(1)#br}#br)#br

## Game Libraries

#warn(Do not make infinite loop, the core already make it)

#hint(It the handleUserInput function job to slow down the game loop)

#space(1)
#br

**Here is the Objects map that need to be filled by the handleUserInput function:**#br

```c++
std::map<int, std::pair<Enum::ObjectType, std::pair<int, int>>> _ObjectData;
```

#space(1)
#br

**Game libraries need to contain the following functions for working properly:**#br

handleUserInput function that take a key in parameter (the key got by the getUserInput function from the current graphic library) and do action based on this key, like moving the player. This function should modify the score, the status of the game (game over) and filling the Objects map (a main function like for the Game library):#br

#terminal(#br void GameName::handleUserInput(char key)#br {#br#space(1)#br}#br)#br

getScore function that return the current score of the game:#br

#terminal(#br int GameName::getScore()#br {#br#space(1)#br}#br)#br

getStatus function that return the current status of the game (true for game over):#br

#terminal(#br bool GameName::getStatus()#br {#br#space(1)#br}#br)#br

GetLibType function that return the type of the library stored in a libType enum for letting the core know if its a graphic library or a game library:#br

#terminal(#br Enum::libType GameName::GetLibType()#br {#br#space(1)#br}#br)#br

ResetGame function that resets the game to it's initial state:#br

#terminal(#br void GameName::ResetGame()#br {#br#space(1)#br}#br)#br

#hint(You can use the base graphic and base game library to make your own graphic and game library !)