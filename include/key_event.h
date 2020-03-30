/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** event.h
*/

#ifndef HEADER_TETRIS_EVENT
#define HEADER_TETRIS_EVENT

#include "tetris.h"

typedef void (*tetris_event_handler_t)(tetris_t *, tetrimino_t *);

void move_left(tetris_t *tetris, tetrimino_t *tetrimino);
void move_right(tetris_t *tetris, tetrimino_t *tetrimino);
void turn_tetrimino(tetris_t *tetris, tetrimino_t *tetrimino);
void drop_tetrimino(tetris_t *tetris, tetrimino_t *tetrimino);

#endif