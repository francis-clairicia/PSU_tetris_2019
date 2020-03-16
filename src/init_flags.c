/*
** EPITECH PROJECT, 2019
** Visual Studio Live Share (Workspace)
** File description:
** init_flags.c
*/

#include <curses.h>
#include "tetris.h"

tetris_flags_t init_flags(void)
{
    tetris_flags_t flags;

    flags.level = 1;
    flags.keys[LEFT] = KEY_LEFT;
    flags.keys[RIGHT] = KEY_RIGHT;
    flags.keys[TURN] = KEY_UP;
    flags.keys[DROP] = KEY_DOWN;
    flags.keys[QUIT] = 'q';
    flags.keys[PAUSE] = ' ';
    flags.nb_rows = 20;
    flags.nb_cols = 10;
    flags.show_next = true;
    flags.debug = false;
    return (flags);
}