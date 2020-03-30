/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** print_map.c
*/

#include <curses.h>
#include "tetris.h"

static void print_box(char box, int row, int col, int pair_color UNUSED)
{
    if (box == 0)
        return;
    init_pair(2, box, COLOR_BLACK);
    attron(COLOR_PAIR(2));
    mvaddch(row, col, '*');
    attroff(COLOR_PAIR(2));
}

void print_map(tetris_t *tetris)
{
    int x = (COLS - (tetris->nb_cols + 2)) / 2;
    int y = 0;
    rect_t frame = {x, y, tetris->nb_cols, tetris->nb_rows};
    int row = 0;
    int col = 0;
    int pair_color = 2;

    print_frame(frame);
    for (y = 0; y < tetris->nb_rows; y += 1) {
        for (x = 0; x < tetris->nb_cols; x += 1) {
            row = frame.y + y + 1;
            col = frame.x + x + 1;
            print_box(tetris->map[y][x], row, col, pair_color);
            pair_color += 1;
        }
    }
    tetris->frame = frame;
}