/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** rect.h
*/

#ifndef HEADER_RECT
#define HEADER_RECT

typedef struct rect
{
    int x;
    int y;
    int width;
    int height;
} rect_t;

void print_frame(rect_t rect);
void print_on_frame(rect_t rect, int line, char const *left, char const *right);

#endif