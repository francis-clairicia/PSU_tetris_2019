/*
** EPITECH PROJECT, 2019
** Visual Studio Live Share (Workspace)
** File description:
** tetris.c
*/

#include <stddef.h>
#include "tetris.h"
#include "my.h"

bool flag_left(tetris_t *tetris, char const *option)
{
    static int called = 0;
    char key[my_strlen(option) + 1];

    called = called + 1;
    if (option == NULL || my_strlen(option) != 1)
        return (false);
    my_strlowcase(my_strcpy(key, option));
    tetris->keys[LEFT] = key[0];
    return (called == 1);
}

bool flag_right(tetris_t *tetris, char const *option)
{
    static int called = 0;
    char key[my_strlen(option) + 1];

    called = called + 1;
    if (option == NULL || my_strlen(option) != 1)
        return (false);
    my_strlowcase(my_strcpy(key, option));
    tetris->keys[RIGHT] = key[0];
    return (called == 1);
}

bool flag_turn(tetris_t *tetris, char const *option)
{
    static int called = 0;
    char key[my_strlen(option) + 1];

    called = called + 1;
    if (option == NULL || my_strlen(option) != 1)
        return (false);
    my_strlowcase(my_strcpy(key, option));
    tetris->keys[TURN] = key[0];
    return (called == 1);
}

bool flag_drop(tetris_t *tetris, char const *option)
{
    static int called = 0;
    char key[my_strlen(option) + 1];

    called = called + 1;
    if (option == NULL || my_strlen(option) != 1)
        return (false);
    my_strlowcase(my_strcpy(key, option));
    tetris->keys[DROP] = key[0];
    return (called == 1);
}

bool flag_pause(tetris_t *tetris, char const *option)
{
    static int called = 0;
    char key[my_strlen(option) + 1];

    called = called + 1;
    if (option == NULL || my_strlen(option) != 1)
        return (false);
    my_strlowcase(my_strcpy(key, option));
    tetris->keys[PAUSE] = key[0];
    return (called == 1);
}