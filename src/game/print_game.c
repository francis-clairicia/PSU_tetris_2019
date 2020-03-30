/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** print_game.c
*/

#include <curses.h>
#include "tetris.h"

void print_game(tetris_t *tetris, tetrimino_t **tetrimino, bool new)
{
    clear();
    print_tetrimino(tetrimino[ACTUAL], tetris->frame, new);
    print_map(tetris);
    next_tetriminos_frame(tetrimino[NEXT], tetris->frame);
    print_gameboard(*tetris);
    key_options(*tetris);
    refresh();
}