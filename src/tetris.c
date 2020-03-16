/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** tetris.c
*/

#include <curses.h>
#include "tetris.h"
#include "my.h"

static void init_curs_module(void)
{
    initscr();
    noecho();
    cbreak();
    curs_set(FALSE);
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
}

static void stop_curs_module(void)
{
    clrtoeol();
    refresh();
    echo();
    nocbreak();
    curs_set(TRUE);
    endwin();
}

int tetris_game(tetris_flags_t options)
{
    list_t *tetriminos = load_tetriminos();

    if (options.debug)
        show_debug(options, tetriminos);
    init_curs_module();
    tetris_gameloop(options, tetriminos);
    stop_curs_module();
    destroy_tetrimino_list(&tetriminos);
    return (0);
}