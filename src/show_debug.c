/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** show_debug.c
*/

#include <curses.h>
#include "tetris.h"
#include "my.h"

static char *ascii_value(int c)
{
    if (c == ' ')
        return ("(space)");
    return ((char []){c, '\0'});
}

static void print_flags(tetris_flags_t tetris_flags)
{
    my_printf("Key Left :  %s\n", ascii_value(tetris_flags.keys[LEFT]));
    my_printf("Key Right :  %s\n", ascii_value(tetris_flags.keys[RIGHT]));
    my_printf("Key Turn :  %s\n", ascii_value(tetris_flags.keys[TURN]));
    my_printf("Key Drop :  %s\n", ascii_value(tetris_flags.keys[DROP]));
    my_printf("Key Quit :  %s\n", ascii_value(tetris_flags.keys[QUIT]));
    my_printf("Key Pause :  %s\n", ascii_value(tetris_flags.keys[PAUSE]));
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