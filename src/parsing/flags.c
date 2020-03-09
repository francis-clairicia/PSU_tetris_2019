/*
** EPITECH PROJECT, 2019
** Visual Studio Live Share (Workspace)
** File description:
** flags_part_two.c
*/

#include "tetris.h"

bool flag_quit(tetris_flags_t *flags, char const *option)
{
    static int called = 0;

    called = called + 1;
    return (called == 1);
}

bool flag_level(tetris_flags_t *flags, char const *option)
{
    static int called = 0;

    called = called + 1;
    return (called == 1);
}

bool flag_map(tetris_flags_t *flags, char const *option)
{
    static int called = 0;

    called = called + 1;
    return (called <= 2);
}

bool flag_next(tetris_flags_t *flags, char const *option)
{
    static int called = 0;

    called = called + 1;
    return (called == 1);
}

bool flag_debug(tetris_flags_t *flags, char const *option)
{
    static int called = 0;

    called = called + 1;
    return (called == 1);
}