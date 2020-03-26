/*
** EPITECH PROJECT, 2019
** Visual Studio Live Share (Workspace)
** File description:
** flags_part_two.c
*/

#include <stddef.h>
#include "tetris.h"
#include "my.h"

bool flag_quit(tetris_t *tetris, char const *option)
{
    static int called = 0;

    called = called + 1;
    if (option == NULL || my_strlen(option) != 1)
        return (false);
    tetris->keys[QUIT] = option[0];
    return (called == 1);
}

bool flag_level(tetris_t *tetris, char const *option)
{
    static int called = 0;
    int level = 0;

    called = called + 1;
    if (option == NULL || !my_str_isnum(option))
        return (false);
    level = my_getnbr(option);
    if (level < 1)
        return (false);
    tetris->level = level;
    return (called == 1);
}

bool flag_next(tetris_t *tetris, char const *option UNUSED)
{
    static int called = 0;

    called = called + 1;
    tetris->show_next = false;
    return (called == 1);
}

bool flag_debug(tetris_t *tetris, char const *option UNUSED)
{
    static int called = 0;

    called = called + 1;
    tetris->debug = true;
    return (called == 1);
}