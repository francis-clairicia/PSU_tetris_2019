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

static void remove_null_pointers_from_list(list_t **list)
{
    int index = 0;
    list_t *node = *list;

    while (node != NULL) {
        if (node->data == 0)
            my_delete_node(list, index, 0);
        else
            index += 1;
        node = my_node(*list, index);
    }
}

int tetris_game(tetris_flags_t options)
{
    list_t *tetriminos = load_tetriminos();

    remove_null_pointers_from_list(&tetriminos);
    sort_tetriminos(tetriminos);
    if (options.debug)
        show_debug(options, tetriminos);
    init_curs_module();
    tetris_gameloop(options, tetriminos);
    stop_curs_module();
    destroy_tetrimino_list(&tetriminos);
    return (0);
}