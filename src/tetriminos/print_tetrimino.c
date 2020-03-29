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
    for (row = 0; tetrimino->array[row] != NULL; row += 1) {
        x = tetrimino->pos.x;
        y = tetrimino->pos.y + row;
        if (y > frame.y)
            mvprintw(y, x, tetrimino->array[row]);
    }
    attroff(COLOR_PAIR(1));
}