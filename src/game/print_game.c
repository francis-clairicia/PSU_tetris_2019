/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** print_game.c
*/

#include <curses.h>
#include "tetris.h"

void print_game(tetris_t tetris, list_t *tetriminos UNUSED)
{
    clear();
    print_map(tetris.nb_rows, tetris.nb_cols);
    print_gameboard(tetris);
    key_options(tetris);
    refresh();
}