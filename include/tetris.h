/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** tetris.h
*/

#ifndef HEADER_TETRIS
#define HEADER_TETRIS

#include <stdbool.h>

typedef struct tetris
{
    int level;
    int keys[6];
    int nb_rows;
    int nb_cols;
    bool show_next;
    bool debug;
} tetris_flags_t;

typedef bool (*flag_function_t)(tetris_flags_t *, char const *);

enum KEYS
{
    LEFT,
    RIGHT,
    TURN,
    DROP,
    QUIT,
    PAUSE
};

struct flag_association
{
    char option;
    flag_function_t function;
};

int tetris_game(tetris_flags_t tetris_flags);
tetris_flags_t init_flags(void);
bool parse_args(int ac, char **av, tetris_flags_t *tetris_flags);

/* Flags functions */
bool print_help(tetris_flags_t *tetris_flags, char const *option);
bool flag_left(tetris_flags_t *flags, char const *option);
bool flag_right(tetris_flags_t *flags, char const *option);
bool flag_turn(tetris_flags_t *flags, char const *option);
bool flag_drop(tetris_flags_t *flags, char const *option);
bool flag_quit(tetris_flags_t *flags, char const *option);
bool flag_pause(tetris_flags_t *flags, char const *option);
bool flag_level(tetris_flags_t *flags, char const *option);
bool flag_map(tetris_flags_t *flags, char const *option);
bool flag_next(tetris_flags_t *flags, char const *option);
bool flag_debug(tetris_flags_t *flags, char const *option);

#endif