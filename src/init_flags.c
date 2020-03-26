/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** init_flags.c
*/

#include <curses.h>
#include "tetris.h"

tetris_t init_tetris(void)
{
    tetris_t tetris;

    tetris.level = 1;
    tetris.keys[LEFT] = KEY_LEFT;
    tetris.keys[RIGHT] = KEY_RIGHT;
    tetris.keys[TURN] = KEY_UP;
    tetris.keys[DROP] = KEY_DOWN;
    tetris.keys[QUIT] = 'q';
    tetris.keys[PAUSE] = ' ';
    tetris.nb_rows = 20;
    tetris.nb_cols = 10;
    tetris.show_next = true;
    tetris.debug = false;
    tetris.score = 0;
    tetris.highscore = 0;
    tetris.clock_start = 0;
    tetris.lines_deleted = 0;
    return (tetris);
}