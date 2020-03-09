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
    if (tetris_flags.debug)
        show_debug(tetris_flags, NULL);
    return (0);
}