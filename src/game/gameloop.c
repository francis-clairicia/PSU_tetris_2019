/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** gameloop.c
*/

#include <time.h>
#include <curses.h>
#include "tetris.h"

static void init_game(tetris_t *tetris)
{
    tetris->clock_start = time(NULL);
    tetris->highscore = get_highscore(HIGHSCORE_SAVE);
}

void tetris_gameloop(tetris_t tetris, list_t *tetriminos)
{
    int key = 0;

    if (show_menu(tetris) == false)
        return;
    init_game(&tetris);
    while ((key = getch()) != tetris.keys[QUIT]) {
        my_usleep(50000);
        print_game(tetris, tetriminos);
    }
}