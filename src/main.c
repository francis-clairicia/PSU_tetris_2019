/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** main.c
*/

#include "tetris.h"

int main(int ac, char **av)
{
    tetris_flags_t tetris_flags = init_flags();

    if (parse_args(ac, av, &tetris_flags) == false)
        return (84);
    return (tetris_game(tetris_flags));
}