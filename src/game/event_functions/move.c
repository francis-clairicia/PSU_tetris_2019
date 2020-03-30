/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** move.c
*/

#include "tetris.h"

void move_left(tetris_t *tetris, tetrimino_t *tetrimino)
{
    int x_left = tetris->frame.x;
    int new_x = tetrimino->pos.x - 1;
    int x = 0;
    int y = 0;
    int row = 0;

    if (new_x <= x_left)
        return;
    x = new_x - tetris->frame.x - 1;
    if (x < 0 || x >= tetris->nb_cols)
        return;
    for (row = 0; row < tetrimino->height; row += 1) {
        y = (tetrimino->pos.y + row) - tetris->frame.y - 1;
        if (y < 0 || y == tetris->nb_rows)
            break;
        if (tetris->map[y][x] != 0)
            return;
    }
    tetrimino->pos.x = new_x;
}

void move_right(tetris_t *tetris, tetrimino_t *tetrimino)
{
    int x_right = tetris->frame.x + tetris->frame.width;
    int new_x = tetrimino->pos.x + 1;
    int new_pos_right = new_x + tetrimino->width;
    int x = 0;
    int y = 0;
    int row = 0;

    if (new_pos_right >= x_right)
        return;
    x = new_pos_right - tetris->frame.x - 1;
    if (x < 0 || x >= tetris->nb_cols)
        return;
    for (row = 0; row < tetrimino->height; row += 1) {
        y = (tetrimino->pos.y + row) - tetris->frame.y - 1;
        if (y < 0 || y == tetris->nb_rows)
            break;
        if (tetris->map[y][x] != 0)
            return;
    }
    tetrimino->pos.x = new_x;
}