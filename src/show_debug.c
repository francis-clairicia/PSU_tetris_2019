/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** show_debug.c
*/

#include <curses.h>
#include "tetris.h"
#include "my.h"

static void wait_key(void)
{
    char *buffer = NULL;

    if (get_next_line(&buffer, 0))
        free(buffer);
}

static void print_key(char const *str_key, int key)
{
    if (key == ' ')
        my_printf("Key %s :  (space)\n", str_key);
    else
        my_printf("Key %s :  %c\n", str_key, key);
}

static void print_flags(tetris_flags_t options)
{
    print_key("Left", options.keys[LEFT]);
    print_key("Right", options.keys[RIGHT]);
    print_key("Turn", options.keys[TURN]);
    print_key("Drop", options.keys[DROP]);
    print_key("Quit", options.keys[QUIT]);
    print_key("Pause", options.keys[PAUSE]);
    my_printf("Next :  %s\n", (options.show_next) ? "Yes" : "No");
    my_printf("Level :  %d\n", options.level);
    my_printf("Size :  %d*%d\n", options.nb_rows, options.nb_cols);
}

static void print_tetriminos(list_t *tetriminos)
{
    my_printf("Tetriminos :  %d\n", my_list_size(tetriminos));
}

void show_debug(tetris_flags_t options, list_t *tetriminos)
{
    my_putstr("*** DEBUG MODE ***\n");
    print_flags(options);
    print_tetriminos(tetriminos);
    my_putstr("Press any key to start Tetris");
    wait_key();
}