##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

SRC_NO_TEST			=	src/main.c								\
						src/tetris.c							\
						src/game/gameloop.c						\
						src/game/show_menu.c					\
						src/game/print_game.c					\
						src/game/print_frame.c					\
						src/game/print_map.c					\
						src/game/next_tetriminos.c				\
						src/game/print_gameboard.c				\
						src/game/print_keys.c					\
						src/tetriminos/print_tetrimino.c		\
						src/game/event.c						\
						src/game/event_functions/move.c			\
						src/game/event_functions/turn.c			\
						src/game/check_map.c

SRC_TEST			=	src/init_flags.c						\
						src/show_debug.c						\
						src/print_help.c						\
						src/parsing/flags.c						\
						src/parsing/flags_map.c					\
						src/parsing/flags_keys.c				\
						src/tetriminos/load_tetriminos.c		\
						src/tetriminos/destroy_tetrimino_list.c	\
						src/tetriminos/create_tetrimino.c		\
						src/tetriminos/parse_tetrimino.c		\
						src/tetriminos/sort_tetriminos.c		\
						src/tetriminos/print_tetriminos_debug.c	\
						src/tetriminos/destroy_tetrimino.c		\
						src/tetriminos/move_tetrimino.c			\
						src/my_usleep.c							\
						src/highscore.c

SRC					=	$(SRC_NO_TEST) $(SRC_TEST)

CFLAGS				=	-Wall -Wextra

CPPFLAGS			=	-I./include/

override LDFLAGS	=	-L./lib

override LDLIBS		+=	-lmy -lncurses

OBJ					=	$(SRC:.c=.o)

NAME				=	tetris

all:	$(NAME)

$(NAME):	CFLAGS += -O2
$(NAME):	$(LDLIBS) $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS) $(LDLIBS)

-lmy:
	$(MAKE) -s -C ./lib/my

tests_run:	CFLAGS += --coverage
tests_run:	LDLIBS += -lcriterion
tests_run:	$(LDLIBS)
	@find -name "*.gc*" -delete
	$(CC) -o unit_tests $(SRC_TEST) tests/*.c $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)
	./unit_tests
	$(RM) unit_tests test*.gc*
	mkdir -p coverage
	mv *.gc* coverage/

debug:	CFLAGS += -g
debug:	$(LDLIBS)
	$(CC) -o $(NAME) $(SRC) $(LDFLAGS) $(LDLIBS) $(CFLAGS) $(CPPFLAGS)

clean:
	$(RM) $(OBJ)
	$(RM) unit_tests *.gc*

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all -lmy tests_run debug clean fclean re
