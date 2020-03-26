/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** main.c
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

static bool get_long_flag_index(char const *flag, bool *require_arg)
{
    char long_flag[my_strlen(flag) + 1];
    int equal_index = my_strchr_index(my_strcpy(long_flag, flag), '=');
    int i = 0;

    if (equal_index >= 0)
        long_flag[equal_index] = '\0';
    for (i = 0; long_opt[i].name != NULL; i += 1) {
        if (my_strcmp(long_opt[i].name, long_flag) == 0) {
            *require_arg = long_opt[i].has_arg;
            return (true);
        }
    }
    return (false);
}

static bool get_flag_index(char flag, int *flag_index)
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

static bool check_args(int ac, char **av)
{
    int i = 0;
    bool require_arg = false;

    for (i = 1; i < ac; i += 1) {
        if (av[i][0] == '-' && av[i][1] != '-' && my_strlen(&av[i][1]) > 1)
            return (false);
        if (my_strncmp(av[i], "--", 2) != 0)
            continue;
        if (!get_long_flag_index(&av[i][2], &require_arg)) {
            my_printf("%s: unrecognized option '%s'\n", av[0], av[i]);
            return (false);
        }
        if (require_arg && !my_strchr(av[i], '='))
            return (false);
    }
    return (true);
}

static bool parse_args(int ac, char **av, tetris_t *tetris)
{
    char short_opt[] = "L:l:r:t:d:q:p:wD";
    char flag = 0;
    int flag_index = 0;

    while ((flag = getopt_long(ac, av, short_opt, long_opt, NULL)) != -1) {
        if (flag == 'h')
            print_help(av[0]);
        if (!get_flag_index(flag, &flag_index))
            return (false);
        if (flags_list[flag_index].function(tetris, optarg) == false)
            return (false);
    }
    return (true);
}

int main(int ac, char **av)
{
    tetris_t tetris = init_tetris();

    if (check_args(ac, av) == false)
        return (84);
    if (parse_args(ac, av, &tetris) == false)
        return (84);
    return (tetris_game(tetris));
}