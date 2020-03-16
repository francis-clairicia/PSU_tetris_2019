/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** parse_args.c
*/

#include <stdlib.h>
#include <getopt.h>
#include "tetris.h"

static const struct option long_opt[] = {
    {"help", no_argument, NULL, 'h'},
    {"level", required_argument, NULL, 'L'},
    {"key-left", required_argument, NULL, 'l'},
    {"key-right", required_argument, NULL, 'r'},
    {"key-turn", required_argument, NULL, 't'},
    {"key-drop", required_argument, NULL, 'd'},
    {"key-quit", required_argument, NULL, 'q'},
    {"key-pause", required_argument, NULL, 'p'},
    {"map-size", required_argument, NULL, 'm'},
    {"without-next", no_argument, NULL, 'w'},
    {"debug", no_argument, NULL, 'D'},
    {NULL, 0, NULL, 0}
};

static const struct flag_association flags_list[] = {
    {'h', &print_help},
    {'L', &flag_level},
    {'l', &flag_left},
    {'r', &flag_right},
    {'t', &flag_turn},
    {'d', &flag_drop},
    {'q', &flag_quit},
    {'p', &flag_pause},
    {'m', &flag_map},
    {'w', &flag_next},
    {'D', &flag_debug},
    {'\0', NULL}
};

static bool is_a_flag(char flag, int *flag_index)
{
    int i = 0;

    for (i = 0; flags_list[i].option != '\0'; i += 1) {
        if (flags_list[i].option == flag) {
            *flag_index = i;
            return (true);
        }
    }
    return (false);
}

bool parse_args(int ac, char **av, tetris_flags_t *tetris_flags)
{
    char short_opt[] = "L:l:r:t:d:q:p:wD";
    char flag = 0;
    int flag_index = 0;

    while ((flag = getopt_long(ac, av, short_opt, long_opt, NULL)) != -1) {
        if (!is_a_flag(flag, &flag_index))
            return (false);
        if (flags_list[flag_index].function(tetris_flags, optarg) == false)
            return (false);
    }
    if (tetris_flags->nb_cols <= 0)
        return (false);
    return (true);
}