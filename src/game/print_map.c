/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** print_map.c
*/

#include <curses.h>
#include "rect.h"

void print_map(int nb_rows, int nb_cols)
{
    int x = (COLS - (nb_cols + 2)) / 2;
    int y = 0;
    rect_t frame = {x, y, nb_cols, nb_rows};

    print_frame(frame);
}