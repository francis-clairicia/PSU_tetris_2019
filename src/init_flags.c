/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** init_flags.c
*/

#include <curses.h>
#include "tetris.h"

static void init_keys(int *keys)
{
    keys[LEFT] = KEY_LEFT;
    keys[RIGHT] = KEY_RIGHT;
    keys[TURN] = KEY_UP;
    keys[DROP] = KEY_DOWN;
    keys[QUIT] = 'q';
    keys[PAUSE] = ' ';
}

tetris_t init_tetris(void)
{
    tetris_t tetris;

    tetris.level = 1;
    init_keys(tetris.keys);
    tetris.nb_rows = 20;
    tetris.nb_cols = 10;
    tetris.show_next = true;
    tetris.debug = false;
    tetris.score = 0;
    tetris.highscore = 0;
    tetris.clock_start = 0;
    tetris.lines_deleted = 0;
    tetris.map = NULL;
    return (tetris);
}