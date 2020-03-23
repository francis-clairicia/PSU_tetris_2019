/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** tetris.h
*/

#ifndef HEADER_TETRIS
#define HEADER_TETRIS

#include "my.h"
#include "mylist.h"

typedef struct tetris
{
    int level;
    int keys[6];
    int nb_rows;
    int nb_cols;
    bool show_next;
    bool debug;
} tetris_flags_t;

enum KEYS
{
    LEFT,
    RIGHT,
    TURN,
    DROP,
    QUIT,
    PAUSE
};

tetris_flags_t init_flags(void);
int tetris_game(tetris_flags_t options);
void show_debug(tetris_flags_t option, list_t *tetriminos);
void tetris_gameloop(tetris_flags_t options, list_t *tetriminos);
int my_usleep(int useconds);

void print_game(tetris_flags_t options, list_t *tetriminos);
void print_map(int nb_rows, int nb_cols);

/* Flags functions */

typedef bool (*flag_function_t)(tetris_flags_t *, char const *);

struct flag_association
{
    char option;
    flag_function_t function;
};

void print_help(char const *binary);
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

typedef struct tetrimino
{
    char *name;
    int width;
    int height;
    int color;
    char **array;
} tetrimino_t;

list_t *load_tetriminos(void);
void destroy_tetrimino_list(list_t **list);
tetrimino_t *create_tetrimino(char const *tetrimino_path);
void parse_tetrimino(tetrimino_t *tetrimino);
void destroy_tetrimino(tetrimino_t *tetrimino);
void sort_tetriminos(list_t *tetriminos);
void print_tetriminos(list_t *tetriminos);

#endif