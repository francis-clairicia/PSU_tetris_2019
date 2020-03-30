/*
** EPITECH PROJECT, 2019
** Visual Studio Live Share (Workspace)
** File description:
** next_tetriminos.c
*/

#include <curses.h>
#include "tetris.h"
#include "rect.h"

void next_tetriminos_frame(tetrimino_t *next, rect_t frame)
{
    int i = 0;
    int x = frame.x + frame.width + 3;
    int y = 3;
    rect_t next_tetri = {x, y, 10, 10};

    mvprintw(1, 20, "NEXT TETRIMINOS");
    print_frame(next_tetri);
    while (next->array[i] != NULL) {
        print_on_frame(next_tetri, i + 1, next->array[i], NULL);
        i = i + 1;
    }
}