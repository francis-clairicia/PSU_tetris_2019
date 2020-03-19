/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** sort_tetriminos.c
*/

#include "tetris.h"

static list_t *is_sorted(list_t *list)
{
    tetrimino_t *first = NULL;
    tetrimino_t *second = NULL;
    list_t *node = NULL;

    for (node = list; node->next != NULL; node = node->next) {
        first = (tetrimino_t *)(node->data);
        second = (tetrimino_t *)(node->next->data);
        if (my_strcmp(first->name, second->name) != -1)
            return (node);
    }
    return (NULL);
}

static void swap_data(long *first, long *second)
{
    long data = *first;

    *first = *second;
    *second = data;
}

void sort_tetriminos(list_t *tetriminos)
{
    list_t *node = NULL;

    if (tetriminos == NULL || tetriminos->next == NULL)
        return;
    while ((node = is_sorted(tetriminos)) != NULL)
        swap_data(&node->data, &node->next->data);
}