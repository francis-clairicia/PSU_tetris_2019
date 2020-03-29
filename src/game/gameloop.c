/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** gameloop.c
*/

#include <time.h>
#include <curses.h>
#include "tetris.h"

static bool init_game(tetris_t *tetris)
{
    tetris->clock_start = time(NULL);
    tetris->highscore = get_highscore(HIGHSCORE_SAVE);
    tetris->map = my_malloc_array(tetris->nb_cols, tetris->nb_rows, 1);
    return (tetris->map != NULL);
}

static void stop_game(tetris_t *tetris)
{
    my_free_array(tetris->map);
}

static void get_actual_and_next_tetrimino(tetrimino_t **tetrimino,
    list_t *list, bool increment)
{
    static int index = 0;
    list_t *node = NULL;

    index += increment;
    node = my_node(list, index);
    if (node == NULL) {
        index = 0;
        node = list;
    }
    tetrimino[NEXT] = (tetrimino_t *)(node->data);
    tetrimino[ACTUAL] = (tetrimino_t *)(node->previous->data);
}

int tetris_gameloop(tetris_t tetris, list_t *tetriminos)
{
    tetrimino_t *tetrimino[2] = {NULL, NULL};
    bool new = true;
    int key = 0;
    int frames_fall = 5;

    if (show_menu(tetris) == false)
        return (0);
    if (!init_game(&tetris))
        return (84);
    while ((key = getch()) != tetris.keys[QUIT]) {
        my_usleep(50 * 1000);
        get_actual_and_next_tetrimino(tetrimino, tetriminos, new);
        print_game(&tetris, tetrimino, new);
        new = tetris_key_event(key, &tetris, tetrimino[ACTUAL], frames_fall);
    }
    stop_game(&tetris);
    return (0);
}