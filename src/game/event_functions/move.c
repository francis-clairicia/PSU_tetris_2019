/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** move.c
*/

#include "tetris.h"

bool move_left(tetris_t *tetris, tetrimino_t *tetrimino)
{
    int x_left = tetris->frame.x;
    int new_x = tetrimino->pos.x - 1;

    if (new_x > x_left)
        tetrimino->pos.x = new_x;
    return (false);
}

bool move_right(tetris_t *tetris, tetrimino_t *tetrimino)
{
    int x_right = tetris->frame.x + tetris->frame.width;
    int new_x = tetrimino->pos.x + 1;

    if (new_x < x_right)
        tetrimino->pos.x = new_x;
    return (false);
}