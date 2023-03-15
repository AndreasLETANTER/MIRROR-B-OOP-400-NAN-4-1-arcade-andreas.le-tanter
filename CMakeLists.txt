#base information
cmake_minimum_required(VERSION 3.12)
project("arcade" VERSION 0.1.0 LANGUAGES CXX)

#set custom variables
set(NAME "arcade")
set(TEST_NAME "unit_tests")
set(CXX_FLAGS -ldl -fno-gnu-unique -Wall -Wextra -Werror)
set(NCURSES_FLAGS -Wall -Werror -fpic --shared -lncurses)

#set the CXX compiler options
add_compile_options(${CXX_FLAGS})

#set the source files
set(SRC
    src/InitClass/Init.cpp 
)
#set the main file
set(MAIN
    src/main.cpp
)
#set the tests files
set(TESTS
    tests/InitClassTests.cpp
)
#set the ncurses files
set(NCURSES
    library/ncurses/library_ncurses.cpp
)

#create the executable
add_executable(${NAME} ${SRC} ${MAIN})

#set the output of the library
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY lib/)
#set the compilation flags for the library
add_compile_options(${NCURSES_FLAGS})
#find the ncurses library
find_package(Curses REQUIRED)
#set the include directories for the library
include_directories(${CURSES_INCLUDE_DIR})
#compile the library
add_library(ncurses SHARED ${NCURSES})
#link the library with the ncurses library
target_link_libraries(ncurses ${CURSES_LIBRARIES})

#set the target to clean the project
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
    COMMENT "Running unit tests"
)
