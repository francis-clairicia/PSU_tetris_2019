/*
** EPITECH PROJECT, 2019
** Visual Studio Live Share (Workspace)
** File description:
** flags_part_two.c
*/

#include <stddef.h>
#include "tetris.h"
#include "my.h"

bool flag_quit(tetris_flags_t *flags, char const *option)
{
    static int called = 0;

    called = called + 1;
    if (option == NULL || my_strlen(option) != 1)
        return (false);
    flags->keys[QUIT] = option[0];
    return (called == 1);
}

bool flag_level(tetris_flags_t *flags, char const *option)
{
    static int called = 0;
    int level = 0;

    called = called + 1;
    if (option == NULL || !my_str_isnum(option))
        return (false);
    level = my_getnbr(option);
    if (level < 1)
        return (false);
    flags->level = level;
    return (called == 1);
}

bool flag_map(tetris_flags_t *flags, char const *option)
{
    static int called = 0;
    int value = 0;

    called = called + 1;
    if (option == NULL || !my_str_isnum(option))
        return (false);
    value = my_getnbr(option);
    if (value <= 0)
        return (false);
    if (called == 1)
        flags->nb_rows = value;
    else if (called == 2)
        flags->nb_cols = value;
    return (called <= 2);
}

bool flag_next(tetris_flags_t *flags, char const *option UNUSED)
{
    static int called = 0;

    called = called + 1;
    flags->show_next = false;
    return (called == 1);
}

bool flag_debug(tetris_flags_t *flags, char const *option UNUSED)
{
    static int called = 0;

    called = called + 1;
    flags->debug = true;
    return (called == 1);
}