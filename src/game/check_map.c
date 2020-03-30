/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** check_map.c
*/

#include <stdio.h>
#include "tetris.h"

static bool all_line_full(char const *line, int length)
{
    int i = 0;

    for (i = 0; i < length; i += 1) {
        if (line[i] == 0)
            return (false);
    }
    return (true);
}

static void make_fall_boxes(char **map, int row, int line_length)
{
    int col = 0;

    while (row >= -1) {
        for (col = 0; col < line_length; col += 1)
            map[row + 1][col] = (row >= 0) ? (map[row][col]) : 0;
        row -= 1;
    }
}

int check_map(tetris_t *tetris, int actual_frame_speed)
{
    int i = 0;

    for (i = 0; tetris->map[i] != NULL; i += 1) {
        if (all_line_full(tetris->map[i], tetris->nb_cols)) {
            my_memset(tetris->map[i], 0, tetris->nb_cols);
            make_fall_boxes(tetris->map, i - 1, tetris->nb_cols);
            tetris->lines_deleted += 1;
            tetris->level += ((tetris->lines_deleted % 10) == 0);
            actual_frame_speed += ((tetris->lines_deleted % 10) == 0);
        }
    }
    return (actual_frame_speed);
}