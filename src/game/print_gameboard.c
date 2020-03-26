/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** print_gameboard.c
*/

#include <time.h>
#include <curses.h>
#include "tetris.h"

static void print_clock(rect_t frame, int line, long start)
{
    char time_str[] = "00:00";
    int elapsed_time = time(NULL) - start;
    int seconds = elapsed_time % 60;
    int minuts = (elapsed_time / 60) % 60;

    time_str[0] += minuts / 10;
    time_str[1] += minuts % 10;
    time_str[3] += seconds / 10;
    time_str[4] += seconds % 10;
    print_on_frame(frame, line, "Time", time_str);
}

static void print_number(rect_t frame, int line, char const *left, int right)
{
    char *nbr = my_nbr_to_str(right);

    if (nbr == NULL)
        return;
    print_on_frame(frame, line, left, nbr);
    free(nbr);
}

void print_gameboard(tetris_t tetris)
{
    int width = 30;
    int height = 10;
    rect_t frame = {0, 10, width, height};

    print_frame(frame);
    print_number(frame, 2, "High Score", tetris.highscore);
    print_number(frame, 3, "Score", tetris.score);
    print_number(frame, 5, "Level", tetris.level);
    print_clock(frame, frame.height, tetris.clock_start);
}