##
## EPITECH PROJECT, 2023
## BOOTSTRAP_Arcade [WSL : Ubuntu]
## File description:
## Makefile
##

#################ALL SRC##################

SRC			=	src/Engine/Engine.cpp \

MAIN 		=	src/main.c \

TESTS_SRC 	=	tests/test.c \

#################ALL OBJ##################

OBJ			=	$(SRC:%.c=%.o)

OBJ_MAIN	=	$(MAIN:%.c=%.o)

OBJT		=	$(TESTS_SRC:%.c=%.o)

#################ALL NAMES##################

NAME		=	bsArcade

TEST_NAME	=	unit_test

#################ALL FLAGS##################

CXX			=	g++

CFLAGS 		= 	 -I./include -ldl -fno-gnu-unique -Wall -Wextra -Werror

TESTS_FLAGS = 	--coverage -lcriterion

#################ALL##################

all:	$(NAME) libraries

$(NAME): 		$(OBJ) $(OBJ_MAIN)
	$(CXX) -o $(NAME) $(CFLAGS) $(OBJ) $(OBJ_MAIN)

libraries: ncurses_lib sfml_lib sdl_lib

ncurses_lib:
	g++ -Wall -Werror -fpic library/ncurses/library_ncurses.cpp  --shared -o library_ncurses.so && mv library_ncurses.so lib/library_ncurses.so

sfml_lib:
	g++ -Wall -Werror -fpic library/sfml/library_sfml.cpp  --shared -o library_sfml.so && mv library_sfml.so lib/library_sfml.so

sdl_lib:
	g++ -Wall -Werror -fpic library/sdl/library_sdl.cpp  --shared -o library_sdl.so && mv library_sdl.so lib/library_sdl.so

#################CLEAN##################

clean:
	find . -name "*~" -delete
	find . -name "*.gcno" -delete
	find . -name "*.gcda" -delete
	find . -name "unit_test" -delete
	find . -name "#*#" -delete
	find . -name "*.o" -delete
	find . -name "*.so" -delete

fclean: clean
	rm -f $(NAME)
	rm -f unit_tests

#################TESTS##################

tests_run: fclean $(OBJT) $(OBJ)
	$(CC) -o $(TEST_NAME) $(OBJT) $(OBJ) $(CFLAGS) $(TESTS_FLAGS)
	./$(TEST_NAME)

coverage:
	gcovr --exclude tests

branch_coverage:
	gcovr -b --exclude tests

#################PUSH##################

push:
	make fclean
	git add -A
	@read -p "Give a commit message " TAG \
    && git commit -m "$${TAG}"
	git push

#################RE##################

re: fclean all

.PHONY: clean fclean re all tests_run coverage
