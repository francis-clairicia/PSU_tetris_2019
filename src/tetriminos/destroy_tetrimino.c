/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** destroy_tetrimino.c
*/

#include "tetris.h"

void destroy_tetrimino(tetrimino_t *tetrimino)
{
    if (tetrimino == NULL)
        return;
    my_free_array(tetrimino->array);
    my_free_array(tetrimino->form);
    free(tetrimino->name);
    free(tetrimino);
}