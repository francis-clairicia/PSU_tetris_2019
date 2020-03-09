/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** print_help.c
*/

#include <stdlib.h>
#include "my.h"

int print_help(void)
{
    my_printf("Usage: ./tetris [options]");
    my_printf("\nOptions:");
    my_printf("\n --help Display this help");
    my_printf("\n -L --level={num} Start Tetris at level num (def: 1)");
    my_printf("\n -l --key-left={K} Move the tetrimino LEFT using the K key ");
    my_printf("def: left arrow)");
    my_printf("\n -r --key-right={K} Move the tetrimino RIGHT using the K ");
    my_printf("key (def: right arrow)");
    my_printf("\n -t --key-turn={K} TURN the tetrimino clockwise 90d using ");
    my_printf("the K key (def: top arrow)");
    my_printf("\n -d --key-drop={K} DROP the tetrimino using the K key ");
    my_printf("def: down arrow)");
    my_printf("\n -q --key-quit={K} QUIT the game using the K key (def: ‘q’ ");
    my_printf("key)");
    my_printf("\n -p --key-pause={K} PAUSE/RESTART the game using the K key ");
    my_printf("def: space bar)");
    my_printf("\n -map-size={row,col} Set the numbers of rows and columns ");
    my_printf("of the map (def: 20,10)");
    my_printf("\n -w --without-next Hide next tetrimino (def: false)");
    my_printf("\n -D --debug Debug mode (def: false)");
    exit(0);
}