/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** gameloop.c
*/

#include <curses.h>
#include "tetris.h"

void tetris_gameloop(tetris_flags_t options, list_t *tetriminos)
{
    int key = 0;

    while ((key = getch()) != options.keys[QUIT]) {
        my_usleep(10000);
        print_game(options, tetriminos);
    }
}