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

static void print_flags(tetris_flags_t tetris_flags)
{
    print_key("Left", tetris_flags.keys[LEFT]);
    print_key("Right", tetris_flags.keys[RIGHT]);
    print_key("Turn", tetris_flags.keys[TURN]);
    print_key("Drop", tetris_flags.keys[DROP]);
    print_key("Quit", tetris_flags.keys[QUIT]);
    print_key("Pause", tetris_flags.keys[PAUSE]);
    my_printf("Next :  %s\n", (tetris_flags.show_next) ? "Yes" : "No");
    my_printf("Level :  %d\n", tetris_flags.level);
    my_printf("Size :  %d*%d\n", tetris_flags.nb_rows, tetris_flags.nb_cols);
}

static void print_tetriminos(list_t *tetriminos)
{
    my_printf("Tetriminos :  %d\n", my_list_size(tetriminos));
}

void show_debug(tetris_flags_t tetris_flags, list_t *tetriminos)
{
    my_putstr("*** DEBUG MODE ***\n");
    print_flags(tetris_flags);
    print_tetriminos(tetriminos);
    my_putstr("Press any key to start Tetris\n");
}