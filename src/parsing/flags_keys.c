/*
** EPITECH PROJECT, 2019
** Visual Studio Live Share (Workspace)
** File description:
** flags.c
*/

#include <stddef.h>
#include "tetris.h"
#include "my.h"

bool flag_left(tetris_flags_t *flags, char const *option)
{
    static int called = 0;
    char key[my_strlen(option) + 1];

    called = called + 1;
    if (option == NULL || my_strlen(option) != 1)
        return (false);
    my_strlowcase(my_strcpy(key, option));
    flags->keys[LEFT] = key[0];
    return (called == 1);
}

bool flag_right(tetris_flags_t *flags, char const *option)
{
    static int called = 0;
    char key[my_strlen(option) + 1];

    called = called + 1;
    if (option == NULL || my_strlen(option) != 1)
        return (false);
    my_strlowcase(my_strcpy(key, option));
    flags->keys[RIGHT] = key[0];
    return (called == 1);
}

bool flag_turn(tetris_flags_t *flags, char const *option)
{
    static int called = 0;
    char key[my_strlen(option) + 1];

    called = called + 1;
    if (option == NULL || my_strlen(option) != 1)
        return (false);
    my_strlowcase(my_strcpy(key, option));
    flags->keys[TURN] = key[0];
    return (called == 1);
}

bool flag_drop(tetris_flags_t *flags, char const *option)
{
    static int called = 0;
    char key[my_strlen(option) + 1];

    called = called + 1;
    if (option == NULL || my_strlen(option) != 1)
        return (false);
    my_strlowcase(my_strcpy(key, option));
    flags->keys[DROP] = key[0];
    return (called == 1);
}

bool flag_pause(tetris_flags_t *flags, char const *option)
{
    static int called = 0;
    char key[my_strlen(option) + 1];

    called = called + 1;
    if (option == NULL || my_strlen(option) != 1)
        return (false);
    my_strlowcase(my_strcpy(key, option));
    flags->keys[PAUSE] = key[0];
    return (called == 1);
}