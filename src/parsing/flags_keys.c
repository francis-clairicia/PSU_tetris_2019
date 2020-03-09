/*
** EPITECH PROJECT, 2019
** Visual Studio Live Share (Workspace)
** File description:
** flags.c
*/

#include "tetris.h"

bool flag_left(tetris_flags_t *flags, char const *option)
{
    static int called = 0;

    called = called + 1;
    return (called == 1);
}

bool flag_right(tetris_flags_t *flags, char const *option)
{
    static int called = 0;

    called = called + 1;
    return (called == 1);
}

bool flag_turn(tetris_flags_t *flags, char const *option)
{
    static int called = 0;

    called = called + 1;
    return (called == 1);
}

bool flag_drop(tetris_flags_t *flags, char const *option)
{
    static int called = 0;

    called = called + 1;
    return (called == 1);
}

bool flag_pause(tetris_flags_t *flags, char const *option)
{
    static int called = 0;

    called = called + 1;
    return (caleld == 1);
}