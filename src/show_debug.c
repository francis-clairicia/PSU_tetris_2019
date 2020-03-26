/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** show_debug.c
*/

#include <curses.h>
#include "tetris.h"
#include "my.h"

static void print_key(char const *str_key, int key)
{
    if (key == ' ')
        my_printf("Key %s :  (space)\n", str_key);
    else
        my_printf("Key %s :  %c\n", str_key, key);
}

static void print_flags(tetris_t tetris)
{
    print_key("Left", tetris.keys[LEFT]);
    print_key("Right", tetris.keys[RIGHT]);
    print_key("Turn", tetris.keys[TURN]);
    print_key("Drop", tetris.keys[DROP]);
    print_key("Quit", tetris.keys[QUIT]);
    print_key("Pause", tetris.keys[PAUSE]);
    my_printf("Next :  %s\n", (tetris.show_next) ? "Yes" : "No");
    my_printf("Level :  %d\n", tetris.level);
    my_printf("Size :  %d*%d\n", tetris.nb_rows, tetris.nb_cols);
}

void show_debug(tetris_t tetris, list_t *tetriminos)
{
    char *buffer = NULL;

    my_putstr("*** DEBUG MODE ***\n");
    print_flags(tetris);
    print_tetriminos(tetriminos);
    my_putstr("Press any key to start Tetris");
    if (get_next_line(&buffer, 0))
        free(buffer);
}