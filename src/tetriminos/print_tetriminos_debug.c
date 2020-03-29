/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** print_tetriminos.c
*/

#include "tetris.h"

static void print_tetrimino_infos(tetrimino_t *tetrimino)
{
    char format[] = "Tetriminos :  Name %s :  Size %d*%d :  Color %d :\n";
    char *name = tetrimino->name;
    int width = tetrimino->width;
    int height = tetrimino->height;
    int color = tetrimino->color;
    int i = 0;

    my_printf(format, name, width, height, color);
    for (i = 0; tetrimino->array[i] != NULL; i += 1)
        my_printf("%s\n", tetrimino->array[i]);
}

static void print_error(tetrimino_t *tetrimino)
{
    my_printf("Tetriminos :  Name %s :  Error\n", tetrimino->name);
}

void print_tetriminos_debug(list_t *tetriminos)
{
    tetrimino_t *tetrimino = NULL;
    list_t *node = NULL;

    my_printf("Tetriminos :  %d\n", my_list_size(tetriminos));
    for (node = tetriminos; node != NULL; node = node->next) {
        tetrimino = (tetrimino_t *)(node->data);
        if (tetrimino->array == NULL)
            print_error(tetrimino);
        else
            print_tetrimino_infos(tetrimino);
    }
}