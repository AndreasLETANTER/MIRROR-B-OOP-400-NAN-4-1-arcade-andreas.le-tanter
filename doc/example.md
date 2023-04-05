---
module:			B-OOP-400
title:			Arcade
subtitle:		Documentation

binary: 		arcade
repository:   arcade
language:		#allLanguages
compilation:	#makfile
build:			no need here

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




**Graphic libraries needs to contain the following functions:**#br

A function that defines the entry point of the library. This function must return a pointer to a class that inherits from IDisplayModule.#br

#terminal(#br extern "C" #br IDisplayModule *entryPoint()#br {#br#space(1) return new MyDisplayModule();#br }#br)

**This function initializes the window.**#br

#terminal(#br void Library::InitWindow()#br {#br#space(1)#br}#br)

**This function closes the window.**#br

#terminal(#br void Library::FiniWindow()#br {#br#space(1)#br}#br)

**This function displays objects on the screen.**#br

#terminal(#br void Library::displayObjects(std::map<int, std::pair<Enum::ObjectType, std::pair<int, int>>> _ObjectData)#br {#br#space(1)#br}#br)

**This function displays the score on the screen.**#br

#terminal(#br void Library::displayScore(int _Score, int x, int y)#br {#br#space(1)#br}#br)

**This function displays a text on the screen.**#br

#terminal(#br void Library::displayText(std::string _String, std::pair<int, int> _Pos, Enum::Color FrontFont, Enum::Color BackFont)#br {#br#space(1)#br}#br)

**This function gets the type of the library.**#br

#terminal(#br Enum::libType Library::GetLibType()#br {#br#space(1)#br}#br)

**This function gets the type of the library.**#br

#terminal(#br std::pair<int, int> LibrarySFML::GetWindowSize()#br {#br#space(1)#br}#br)

**This function gets user input.**#br

#terminal(#br char Library::getUserInput()#br {#br#space(1)#br}#br)

**This function displays drawed objects on the screen.**#br

#terminal(#br void Library::display()#br {#br#space(1)#br}#br)

