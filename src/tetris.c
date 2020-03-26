/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** tetris.c
*/

#include <curses.h>
#include "tetris.h"
#include "my.h"

static bool init_curs_module(void)
{
    initscr();
    if (!has_colors()) {
        endwin();
        return (false);
    }
    noecho();
    cbreak();
    curs_set(FALSE);
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    start_color();
    return (true);
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

static void remove_non_valid_tetriminos(list_t **list)
{
    int node_index = 0;
    list_t *node = *list;
    tetrimino_t *tetrimino = NULL;

    while (node != NULL) {
        tetrimino = (tetrimino_t *)(node->data);
        if (tetrimino->array == NULL) {
            destroy_tetrimino(tetrimino);
            my_delete_node(list, node_index, 0);
        } else {
            node_index += 1;
        }
        node = my_node(*list, node_index);
    }
}

int tetris_game(tetris_t tetris)
{
    list_t *tetriminos = load_tetriminos();

    remove_null_pointers_from_list(&tetriminos);
    sort_tetriminos(tetriminos);
    if (tetris.debug)
        show_debug(tetris, tetriminos);
    remove_non_valid_tetriminos(&tetriminos);
    if (!init_curs_module())
        return (84);
    tetris_gameloop(tetris, tetriminos);
    stop_curs_module();
    destroy_tetrimino_list(&tetriminos);
    return (0);
}