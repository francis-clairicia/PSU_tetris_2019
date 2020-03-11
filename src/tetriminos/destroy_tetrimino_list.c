/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** destroy_tetrimino_list.c
*/

#include "tetris.h"
#include "mylist.h"

void destroy_tetrimino_list(list_t **list)
{
    list_t *node = NULL;

    for (node = *list; node != NULL; node = node->next)
        destroy_tetrimino((tetrimino_t *)(node->data));
    my_free_list(list, false);
}