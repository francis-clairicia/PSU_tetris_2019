/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** event.c
*/

#include "tetris.h"
#include "event.h"

static const tetris_event_handler_t event_hander[] = {
    [LEFT] = move_left,
    [RIGHT] = move_right,
    [TURN] = turn_tetrimino,
    [DROP] = drop_tetrimino
};

static tetris_event_handler_t get_function_handler(int key, int *tetris_keys)
{
    int i = 0;
    int nb_functions = sizeof(event_hander) / sizeof(event_hander[0]);

    for (i = 0; i < nb_functions; i += 1) {
        if (key == tetris_keys[i])
            return (event_hander[i]);
    }
    return (NULL);
}

bool tetris_key_event(int key, tetris_t *tetris, tetrimino_t *tetrimino,
    int frames_per_fall)
{
    static int nb_frames = 0;
    int move_speed = 1;
    tetris_event_handler_t handler = get_function_handler(key, tetris->keys);

    nb_frames += 1;
    if (handler != NULL)
        move_speed += handler(tetris, tetrimino);
    if (nb_frames <= frames_per_fall)
        move_speed = 0;
    else
        nb_frames = 0;
    return (move_tetrimino(tetris, tetrimino, move_speed));
}