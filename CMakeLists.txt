cmake_minimum_required(VERSION 3.12)
project("arcade" VERSION 0.1.0 LANGUAGES CXX)
set(CMAKE_CXX_FLAGS "-ldl -fno-gnu-unique -Wall -Wextra -Werror")
add_executable(arcade src/main.cpp src/InitClass/Init.cpp)
add_custom_target(fclean
    COMMAND find . -name "*~" -delete
    COMMAND find . -name "*.gcno" -delete
    COMMAND find . -name "*.gcda" -delete
    COMMAND find . -name "unit_test" -delete
    COMMAND find . -name "*.o" -delete
    COMMAND find . -name "*.so" -delete
    COMMAND find . -name "CMakeCache.txt" -delete
    COMMAND find . -name "cmake_install.cmake" -delete
    COMMAND find . -name "Makefile" -delete
    COMMAND find . -name "arcade" -delete
    COMMENT "Clean the project and the binary"
)
add_custom_target(libraries
    COMMAND make ncurses_lib
    COMMAND make sfml_lib
    COMMAND make sdl_lib
    COMMENT "Compile the libraries"
)
add_custom_target(ncurses_lib
    COMMAND g++ -Wall -Werror -fpic library/ncurses/library_ncurses.cpp --shared -o library_ncurses.so -lncurses && mv library_ncurses.so lib/library_ncurses.so
    COMMENT "Compile the ncurses library"
)
add_custom_target(sfml_lib
    COMMAND g++ -Wall -Werror -fpic library/sfml/library_sfml.cpp  --shared -o library_sfml.so && mv library_sfml.so lib/library_sfml.so
    COMMENT "Compile the sfml library"
)
add_custom_target(sdl_lib
    COMMAND g++ -Wall -Werror -fpic library/sdl/library_sdl.cpp  --shared -o library_sdl.so && mv library_sdl.so lib/library_sdl.so
    COMMENT "Compile the sdl library"
)
add_custom_target(re
    COMMAND make clean
    COMMAND make
    COMMENT "Recompiling the project"
)
add_custom_target(tests_run
    COMMAND echo ""
    COMMENT "Running unit tests"
)