/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** flags_map.c
*/

#include "tetris.h"

static bool free_and_return(char **size, bool status)
{
    if (size != NULL)
        my_free_array(size);
    return (status);
}

bool flag_map(tetris_t *tetris, char const *option)
{
    static int called = 0;
    char **size = my_str_to_word_array(option, ",");
    int row = 0;
    int col = 0;

    called = called + 1;
    if (size == NULL || my_array_len(size) != 2)
        return (free_and_return(size, false));
    if (!my_str_isnum(size[0]) || !my_str_isnum(size[1]))
        return (free_and_return(size, false));
    row = my_getnbr(size[0]);
    col = my_getnbr(size[1]);
    if (row <= 0 || col <= 0)
        return (free_and_return(size, false));
    tetris->nb_rows = row;
    tetris->nb_cols = col;
    return (free_and_return(size, called == 1));
}