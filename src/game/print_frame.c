/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** print_frame.c
*/

#include <curses.h>
#include "my.h"
#include "rect.h"

static void print_horizontal_line(int row, int col, int width)
{
    char line[width + 1];

    my_memset(line, '-', width);
    line[width] = 0;
    line[0] = '+';
    line[width - 1] = '+';
    mvprintw(row, col, line);
}

void print_frame(rect_t rect)
{
    int x_min = rect.x;
    int x_max = rect.x + rect.width - 1;
    int i = 0;

    print_horizontal_line(rect.y, rect.x, rect.width);
    for (i = 0; i < rect.height; i += 1) {
        mvprintw(rect.y + 1 + i, x_min, "|");
        mvprintw(rect.y + 1 + i, x_max, "|");
    }
    print_horizontal_line(rect.y + 1 + i, rect.x, rect.width);
}

void print_on_frame(rect_t rect, int line, char const *left, char const *right)
{
    int x_left = 0;
    int x_right = 0;
    int y = 0;

    if (line <= 0 || line > rect.height)
        return;
    x_left = rect.x + 1;
    x_right = rect.x + rect.width - my_strlen(right) - 1;
    y = rect.y + line;
    if (left != NULL)
        mvprintw(y, x_left, left);
    if (right != NULL)
        mvprintw(y, x_right, right);
}