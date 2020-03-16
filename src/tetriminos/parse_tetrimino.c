/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** parse_tetrimino.c
*/

#include "tetris.h"

static bool free_array_and_return(char **array, bool status)
{
    my_free_array(array);
    return (status);
}

static bool valid_first_line(char * const *line)
{
    int i = 0;

    if (my_array_len(line) != 3)
        return (false);
    for (i = 0; i < 3; i += 1) {
        if (!my_str_isnum(line[i]))
            return (false);
    }
    return (true);
}

static bool valid_body(char * const *body, int *values)
{
    int nb_cols = values[0];
    int nb_rows = values[1];
    int row = 0;

    if (nb_rows <= 0 || nb_cols <= 0 || my_array_len(body) != nb_rows)
        return (false);
    for (row = 0; row < nb_rows; row += 1) {
        if (!my_str_contains_only(body[row], " *"))
            return (false);
        if (my_strlen(body[row]) >= nb_cols
        && my_strchr(&body[row][nb_cols], '*') != NULL)
            return (false);
    }
    return (true);
}

static bool valid_array_content(char * const *array, int *values)
{
    char **first_line = NULL;

    if (array == NULL)
        return (false);
    first_line = my_str_to_word_array(array[0], " ");
    if (!valid_first_line(first_line))
        return (free_array_and_return(first_line, false));
    values[0] = my_getnbr(first_line[0]);
    values[1] = my_getnbr(first_line[1]);
    values[2] = my_getnbr(first_line[2]);
    if (values[2] < 0 || !valid_body(&array[1], values))
        return (free_array_and_return(first_line, false));
    return (free_array_and_return(first_line, true));
}

void parse_tetrimino(tetrimino_t *tetrimino)
{
    int values[3] = {0, 0, 0};
    char **array = NULL;
    int i = 0;

    if (tetrimino == NULL)
        return;
    array = tetrimino->array;
    tetrimino->array = NULL;
    if (valid_array_content(array, values)) {
        tetrimino->width = values[0];
        tetrimino->height = values[1];
        tetrimino->color = values[2];
        tetrimino->array = my_malloc_array(values[0] + 1, values[1], 1);
        if (tetrimino->array == NULL)
            return my_free_array(array);
        for (i = 0; tetrimino->array[i] != NULL; i += 1)
            my_strncpy(tetrimino->array[i], array[i + 1], tetrimino->width);
    }
    my_free_array(array);
}