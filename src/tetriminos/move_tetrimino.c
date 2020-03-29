/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** move_tetrimino.c
*/

#include "tetris.h"

static bool check_fall(tetris_t *tetris, int x, int y)
{
    if (y < 0)
        return (false);
    if (y < tetris->nb_rows) {
        if (tetris->map[y][x] == 0)
            return (false);
    }
    return (true);
}

static int set_map_value(tetrimino_t *tetrimino, int row, int col)
{
    if (tetrimino->array[row][col] == '*')
        return (tetrimino->color);
    return (0);
}

static void stop_tetrimino(tetris_t *tetris, tetrimino_t *tetrimino, int speed)
{
    int row = 0;
    int col = 0;
    int x = 0;
    int y = 0;

    for (row = 0; row < tetrimino->height; row += 1) {
        for (col = 0; col < tetrimino->width; col += 1) {
            x = (tetrimino->pos.x + col) - tetris->frame.x - 1;
            y = (tetrimino->pos.y + row) - tetris->frame.y - 1 + (speed - 1);
            tetris->map[y][x] = set_map_value(tetrimino, row, col);
        }
    }
}

bool move_tetrimino(tetris_t *tetris, tetrimino_t *tetrimino, int move_speed)
{
    int last_row = tetrimino->height - 1;
    int col = 0;
    int x = 0;
    int y = (tetrimino->pos.y + last_row) - tetris->frame.y - 1 + move_speed;
    bool stop = false;

    for (col = 0; col < tetrimino->width; col += 1) {
        if (tetrimino->array[last_row][col] == '*') {
            x = (tetrimino->pos.x + col) - tetris->frame.x - 1;
            stop = check_fall(tetris, x, y);
        }
        if (stop)
            break;
    }
    if (stop)
        stop_tetrimino(tetris, tetrimino, move_speed);
    else
        tetrimino->pos.y += move_speed;
    return (stop);
}