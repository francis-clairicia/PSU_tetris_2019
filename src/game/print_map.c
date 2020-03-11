/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** print_map.c
*/

#include <curses.h>

static void print_horizontal_line(int row, int nb_cols)
{
    int i = 0;
    int x = (COLS - (nb_cols + 2)) / 2;

    mvprintw(row, x, "+");
    for (i = 1; i <= nb_cols; i += 1)
        mvprintw(row, x + i, "-");
    mvprintw(row, x + i, "+");
}

void print_map(int nb_rows, int nb_cols)
{
    int x = (COLS - (nb_cols + 2)) / 2;
    int y = 0;

    print_horizontal_line(0, nb_cols);
    for (y = 0; y < nb_rows; y += 1) {
        mvprintw(y + 1, x, "|");
        mvprintw(y + 1, x + nb_cols + 1, "|");
    }
    print_horizontal_line(y + 1, nb_cols);
}