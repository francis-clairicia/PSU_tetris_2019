/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** print_game.c
*/

#include <curses.h>
#include "tetris.h"

void print_game(tetris_flags_t options, list_t *tetriminos UNUSED)
{
    clear();
    print_map(options.nb_rows, options.nb_cols);
    refresh();
}