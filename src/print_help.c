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
    my_putstr(" --help\t\t\tDisplay this help\n");
    my_putstr(" -L --level={num}\tStart Tetris at level num (def: 1)\n");
    my_putstr(" -l --key-left={K}\tMove the tetrimino LEFT using the K key ");
    my_putstr("(def: left arrow)\n");
    my_putstr(" -r --key-right={K}\tMove the tetrimino RIGHT using the K ");
    my_putstr("key (def: right arrow)\n");
    my_putstr(" -t --key-turn={K}\tTURN the tetrimino clockwise 90d using ");
    my_putstr("the K key (def: top arrow)\n");
}

static void print_options_part_two(void)
{
    my_putstr(" -d --key-drop={K}\tDROP the tetrimino using the K key ");
    my_putstr("(def: down arrow)\n");
    my_putstr(" -q --key-quit={K}\tQUIT the game using the K key ");
    my_putstr("(def: 'q' key)\n");
    my_putstr(" -p --key-pause={K}\tPAUSE/RESTART the game using the K key ");
    my_putstr("(def: space bar)\n");
    my_putstr(" --map-size={row,col}\tSet the numbers of rows and columns ");
    my_putstr("of the map (def: 20,10)\n");
    my_putstr(" -w --without-next\tHide next tetrimino (def: false)\n");
    my_putstr(" -D --debug\t\tDebug mode (def: false)\n");
}

void print_help(char const *binary)
{
    my_printf("Usage:\t%s [options]\n", binary);
    my_putstr("Options:\n");
    print_options_part_one();
    print_options_part_two();
    exit(0);
}