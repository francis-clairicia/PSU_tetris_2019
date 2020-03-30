/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** turn.c
*/

#include <stdio.h>
#include "tetris.h"

void turn_tetrimino(tetris_t *tetris UNUSED, tetrimino_t *tetrimino)
{
    int x = 0;
    int y = 0;
    int width = tetrimino->width;
    int height = tetrimino->height;
    char **new_array = my_malloc_array(height + 1, width, sizeof(char));

    if (new_array == NULL)
        return;
    for (y = 0; y < height; y += 1) {
        for (x = 0; x < width; x += 1) {
            new_array[width - 1 - x][y] = tetrimino->form[y][x];
        }
    }
    my_free_array(tetrimino->form);
    tetrimino->form = new_array;
    tetrimino->width = height;
    tetrimino->height = width;
}