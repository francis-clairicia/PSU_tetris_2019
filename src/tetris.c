/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** tetris.c
*/

#include <curses.h>
#include "tetris.h"
#include "my.h"

int tetris_game(tetris_flags_t tetris_flags)
{
    list_t *tetriminos = load_tetriminos();

    if (tetris_flags.debug)
        show_debug(tetris_flags, tetriminos);
    destroy_tetrimino_list(&tetriminos);
    return (0);
}