###############################BASE INFORMATION####################################
cmake_minimum_required(VERSION 3.1  )
project("arcade" VERSION 0.1.0 LANGUAGES CXX)

###############################COMPILATION VARIABLES###############################
set(NAME "arcade")
set(TEST_NAME "unit_tests")
set(GAMES_FLAGS -Wall -Werror -fpic --shared -g)
set(CXX_FLAGS -ldl -fno-gnu-unique -Wall -Wextra -Werror -g)
set(NCURSES_FLAGS -Wall -Werror -fpic --shared -lncurses -g)
set(SDL_FLAGS -Wall -Werror -fpic --shared -lSDL2 -lSDL2_ttf -g)
set(SFML_FLAGS -Wall -Werror -fpic --shared -lsfml-graphics -lsfml-window -lsfml-system -g)
set(LIB_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib/)
file(MAKE_DIRECTORY lib)
###############################DIRECTORIES SRC###################################
set(SRC
    src/InitClass/Init.cpp
    src/MenuClass/Menu.cpp
    src/ProgramEventsClass/ProgramEvents.cpp
    src/GameClass/Game.cpp
    src/CoreClass/Core.cpp
    src/ErrorClass/ErrorClass.cpp
    src/SuccessClass/Success.cpp
)
set(MAIN
    src/main.cpp
)
set(TESTS
    tests/Unit_tests/InitClassTests.cpp
)
set(NCURSES
    library/graphic_libraries/ncurses/library_ncurses.cpp
)
set(SFML
    library/graphic_libraries/sfml/library_sfml.cpp
)
set(SDL
    library/graphic_libraries/sdl/library_sdl.cpp
)
set(PACMAN
    library/game_libraries/pacman/Pacman.cpp
)
set(SNAKE
    library/game_libraries/snake/Snake.cpp 
    library/game_libraries/snake/timer/Timer.cpp   
)
set(NIBBLER
    library/game_libraries/nibbler/Nibbler.cpp
    library/game_libraries/nibbler/timer/Timer.cpp
)

###############################COMPILATION MAIN PROGRAM##########################
add_compile_options(${CXX_FLAGS})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
add_executable(${NAME} ${SRC} ${MAIN})
add_custom_target(core
    COMMAND make ${NAME}
)

###############################COMPILATION LIBRARIES#############################
###############################NCURSES###########################################
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${LIB_DIRECTORY})
#find the ncurses library
find_package(Curses REQUIRED)
#set the include directories for the library
include_directories(${CURSES_INCLUDE_DIR})
#compile the library
add_library(ncurses SHARED ${NCURSES})
#set the prefix and suffix for the library
set_target_properties(ncurses PROPERTIES PREFIX "arcade_")
#link the library with the ncurses library
target_link_libraries(ncurses ${CURSES_LIBRARIES})
###############################SFML##############################################
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${LIB_DIRECTORY})
# find the SFML library
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)
# compile the library
add_library(sfml SHARED ${SFML})
#set the prefix and suffix for the library
set_target_properties(sfml PROPERTIES PREFIX "arcade_")
# link the library with the SFML library
target_link_libraries(sfml sfml-graphics sfml-window sfml-system)
###############################SDL##############################################
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${LIB_DIRECTORY})
#find the ncurses library
find_package(SDL2 REQUIRED)
#set the include directories for the library
include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_TTF_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS} ${SDL2_MIXER_INCLUDE_DIRS})
#compile the library
add_library(sdl2 SHARED ${SDL})
#set the prefix and suffix for the library
set_target_properties(sdl2 PROPERTIES PREFIX "arcade_")
#link the library with the ncurses library
target_link_libraries(sdl2 ${SDL_FLAGS} ${SDL2_LIBRARIES} ${SDL2_TTF_LIBRARIES} ${SDL2_IMAGE_LIBRARIES} ${SDL2_MIXER_LIBRARIES})

add_custom_target(graphicals
    COMMAND make ncurses
    COMMAND make sfml
    COMMAND make sdl2
)

###############################COMPILATION GAMES#################################
##############################PACMAN#############################################
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${LIB_DIRECTORY})
add_library(pacman SHARED ${PACMAN})
#set the prefix and suffix for the library
set_target_properties(pacman PROPERTIES PREFIX "arcade_")
##############################Snake##############################################
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${LIB_DIRECTORY})
add_library(snake SHARED ${SNAKE})
#set the prefix and suffix for the library
set_target_properties(snake PROPERTIES PREFIX "arcade_")
##############################Nibbler############################################
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${LIB_DIRECTORY})
add_library(nibbler SHARED ${NIBBLER})
#set the prefix and suffix for the library
set_target_properties(nibbler PROPERTIES PREFIX "arcade_")

add_custom_target(games
    COMMAND make pacman
    COMMAND make snake
)

###############################COMPILATION TESTS#################################
#create the tests executable
add_executable(${TEST_NAME} ${SRC} ${TESTS})
#link the tests with the criterion library
target_link_libraries(${TEST_NAME} criterion)

###############################COMPILATION TARGETS###############################
add_custom_target(fclean
    COMMAND make clean
    COMMAND find . -name "*~" -delete
    COMMAND find . -name "*.gcno" -delete
    COMMAND find . -name "*.gcda" -delete
    COMMAND find . -name "unit_test" -delete
    COMMAND find . -name "*.o" -delete
    COMMAND find . -name "*.so" -delete
    COMMAND find . -name "CMakeCache.txt" -delete
    COMMAND find . -name "cmake_install.cmake" -delete
    COMMAND find . -name "Makefile" -delete
    COMMAND find . -name ${NAME} -delete
    COMMAND find . -name "*.a" -delete
    COMMAND find . -name "lib" -delete
    COMMENT "Clean the project and the binary"
)

#set the target to recompile the project
add_custom_target(re
    COMMAND make clean
    COMMAND make
    COMMENT "Recompiling the project"
)

#set the target to run the tests
add_custom_target(tests_run
    COMMAND make ${TEST_NAME}
    COMMAND ./${TEST_NAME}
    COMMENT "Running unit tests"
)
