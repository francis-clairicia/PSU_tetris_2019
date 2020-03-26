/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** print_keys.c
*/

#include <curses.h>
#include "tetris.h"
#include "key.h"

static struct key special_keys[] = {
    {KEY_BACKSPACE, "backspace"},
    {KEY_LEFT, "left arrow"},
    {KEY_RIGHT, "right arrow"},
    {KEY_UP, "up arrow"},
    {KEY_DOWN, "down arrow"},
    {' ', "space bar"},
    {'\0', NULL}
};

static char const *get_special_key(int key)
{
    int i = 0;

    for (i = 0; special_keys[i].value != '\0'; i += 1) {
        if (special_keys[i].value == key)
            return (special_keys[i].name);
    }
    return (NULL);
}

static void print_key(int row, int col, int key, char const *action)
{
    char const *key_name = get_special_key(key);

    if (key_name != NULL)
        mvprintw(row, col, "press %s to %s", key_name, action);
    else
        mvprintw(row, col, "press %c to %s", key, action);
}

void key_options(tetris_t tetris)
{
    rect_t frame = {0, 0, 50, 6};

    print_frame(frame);
    print_key(1, 1, tetris.keys[QUIT], "quit");
    print_key(2, 1, tetris.keys[LEFT], "move tetriminos left");
    print_key(3, 1, tetris.keys[RIGHT], "move tetriminos right");
    print_key(4, 1, tetris.keys[DROP], "move tetriminos faster");
    print_key(5, 1, tetris.keys[TURN], "turn tetriminos");
    print_key(6, 1, tetris.keys[PAUSE], "pause the game");
}