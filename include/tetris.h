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
#include "rect.h"

typedef struct tetris
{
    int level;
    int keys[6];
    int nb_rows;
    int nb_cols;
    bool show_next;
    bool debug;
    int highscore;
    int score;
    long clock_start;
    int lines_deleted;
    char **map;
    rect_t frame;
} tetris_t;

enum KEYS
{
    LEFT,
    RIGHT,
    TURN,
    DROP,
    QUIT,
    PAUSE
};

tetris_t init_tetris(void);
int tetris_game(tetris_t tetris);
void show_debug(tetris_t option, list_t *tetriminos);
int tetris_gameloop(tetris_t tetris, list_t *tetriminos);
int my_usleep(int useconds);

/* HighScore */

#define HIGHSCORE_SAVE "score.sav"
int get_highscore(char const *save_file);
void save_highscore(int highscore, char const *save_file);

/* tetris functions */

typedef bool (*flag_function_t)(tetris_t *, char const *);

struct flag_association
{
    char option;
    flag_function_t function;
};

void print_help(char const *binary);
bool flag_left(tetris_t *tetris, char const *option);
bool flag_right(tetris_t *tetris, char const *option);
bool flag_turn(tetris_t *tetris, char const *option);
bool flag_drop(tetris_t *tetris, char const *option);
bool flag_quit(tetris_t *tetris, char const *option);
bool flag_pause(tetris_t *tetris, char const *option);
bool flag_level(tetris_t *tetris, char const *option);
bool flag_map(tetris_t *tetris, char const *option);
bool flag_next(tetris_t *tetris, char const *option);
bool flag_debug(tetris_t *tetris, char const *option);

/* Tetriminos */

enum TETRIMINO
{
    ACTUAL,
    NEXT
};

typedef struct vector
{
    int x;
    int y;
} vector_t;

typedef struct tetrimino
{
    char *name;
    int width;
    int height;
    int color;
    char **array;
    char **form;
    vector_t pos;
} tetrimino_t;

list_t *load_tetriminos(void);
void destroy_tetrimino_list(list_t **list);
tetrimino_t *create_tetrimino(char const *tetrimino_path);
void parse_tetrimino(tetrimino_t *tetrimino);
void destroy_tetrimino(tetrimino_t *tetrimino);
void sort_tetriminos(list_t *tetriminos);
void print_tetriminos_debug(list_t *tetriminos);
void print_tetrimino(tetrimino_t *tetrimino, rect_t frame, bool new);
bool move_tetrimino(tetris_t *tetris, tetrimino_t *tetrimino, int move_speed);

/* Gameplay */

int show_menu(tetris_t tetris);
void print_map(tetris_t *tetris);
void print_game(tetris_t *tetris, tetrimino_t **tetrimino, bool new);
void print_gameboard(tetris_t tetris);
bool tetris_key_event(int key, tetris_t *tetris, tetrimino_t *tetrimino,
    int frames_per_fall);
void key_options(tetris_t tetris);

#endif