/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** print_help.c
*/

#include <stdlib.h>
#include "tetris.h"
#include "my.h"

static void print_options_part_one(void)
{
    my_putstr("\n --help\tDisplay this help");
    my_putstr("\n -L --level={num}\tStart Tetris at level num (def: 1)");
    my_putstr("\n -l --key-left={K}\tMove the tetrimino LEFT using the K key ");
    my_putstr("def: left arrow)");
    my_putstr("\n -r --key-right={K}\tMove the tetrimino RIGHT using the K ");
    my_putstr("key (def: right arrow)");
    my_putstr("\n -t --key-turn={K}\tTURN the tetrimino clockwise 90d using ");
    my_putstr("the K key (def: top arrow)");
}

static void print_options_part_two(void)
{
    my_putstr("\n -d --key-drop={K}\tDROP the tetrimino using the K key ");
    my_putstr("def: down arrow)");
    my_putstr("\n -q --key-quit={K}\tQUIT the game using the K key (def: 'q' ");
    my_putstr("key)");
    my_putstr("\n -p --key-pause={K}\tPAUSE/RESTART the game using the K key ");
    my_putstr("def: space bar)");
    my_putstr("\n -map-size={row,col}\tSet the numbers of rows and columns ");
    my_putstr("of the map (def: 20,10)");
    my_putstr("\n -w --without-next\tHide next tetrimino (def: false)");
    my_putstr("\n -D --debug\t\tDebug mode (def: false)\n");
}

bool print_help(tetris_flags_t *tetris_flags __attribute__((unused)),
    char const *option __attribute__((unused)))
{
    my_putstr("Usage: ./tetris [options]");
    my_putstr("\nOptions:");
    print_options_part_one();
    print_options_part_two();
    exit(0);
    return (0);
}