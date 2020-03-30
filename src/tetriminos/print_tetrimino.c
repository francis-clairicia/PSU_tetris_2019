/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** print_tetrimino.c
*/

#include <curses.h>
#include "tetris.h"

static void set_new_pos(tetrimino_t *tetrimino, rect_t frame)
{
    int x = frame.x + (frame.width / 2) - (tetrimino->width / 2);
    int y = frame.y - tetrimino->height;

    my_free_array(tetrimino->form);
    tetrimino->form = my_array_dup(tetrimino->array);
    tetrimino->width = my_strlen(tetrimino->array[0]);
    tetrimino->height = my_array_len(tetrimino->array);
    tetrimino->pos.x = x;
    tetrimino->pos.y = y;
}

void print_tetrimino(tetrimino_t *tetrimino, rect_t frame, bool new)
{
    int row = 0;
    int x = 0;
    int y = 0;

    if (new)
        set_new_pos(tetrimino, frame);
    init_pair(1, tetrimino->color, COLOR_BLACK);
    attron(COLOR_PAIR(1));
    for (row = 0; tetrimino->form[row] != NULL; row += 1) {
        x = tetrimino->pos.x;
        y = tetrimino->pos.y + row;
        if (y > frame.y)
            mvprintw(y, x, tetrimino->form[row]);
    }
    attroff(COLOR_PAIR(1));
}