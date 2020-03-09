/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** tetris.c
*/

#include "tetris.h"
#include "my.h"

static void print_flags(tetris_flags_t tetris_flags)
{
    my_printf("Default level: %d\n", tetris_flags.level);
    my_printf("Key left: %d ('%c')\n", tetris_flags.keys[LEFT], tetris_flags.keys[LEFT]);
    my_printf("Key right: %d ('%c')\n", tetris_flags.keys[RIGHT], tetris_flags.keys[RIGHT]);
    my_printf("Key turn: %d ('%c')\n", tetris_flags.keys[TURN], tetris_flags.keys[TURN]);
    my_printf("Key drop: %d ('%c')\n", tetris_flags.keys[DROP], tetris_flags.keys[DROP]);
    my_printf("Key quit: %d ('%c')\n", tetris_flags.keys[QUIT], tetris_flags.keys[QUIT]);
    my_printf("Key pause: %d ('%c')\n", tetris_flags.keys[PAUSE], tetris_flags.keys[PAUSE]);
    my_printf("Map size: (%d, %d)\n", tetris_flags.nb_rows, tetris_flags.nb_cols);
    my_printf("Without next: %s\n", (tetris_flags.show_next) ? "False": "True");
    my_printf("Debug mode: %s\n", (tetris_flags.debug) ? "True": "False");
}

int tetris_game(tetris_flags_t tetris_flags)
{
    print_flags(tetris_flags);
    return (0);
}