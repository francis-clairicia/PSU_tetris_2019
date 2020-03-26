/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** show_menu.c
*/

#include <curses.h>
#include "tetris.h"

int option_func(int key_to_quit)
{
    int key = 0;

    do {
        clear();
        mvprintw(1, 5, "Press %c to quit, down key to return", key_to_quit);
        mvprintw(5, 5, "WELCOME TO OUR TETRIS");
        mvprintw(6, 7, "The goal of the game is simple");
        mvprintw(7, 7, "Objects will come down from the top of the map");
        mvprintw(8, 7, "Move them using the arrow keys");
        mvprintw(9, 7, "Your goal is to form a complete lign");
        mvprintw(10, 7, "The line will be erased, and you'll get points");
        refresh();
        my_usleep(50000);
        key = getch();
    } while (key != KEY_DOWN && key != key_to_quit);
    return (key);
}

int show_menu(tetris_t tetris UNUSED)
{
    int key = 0;

    do {
        clear();
        mvprintw(1, 5, "TETRIS");
        mvprintw(3, 5, "PRESS ENTER TO START");
        mvprintw(4, 5, "PRESS %c TO QUIT", tetris.keys[QUIT]);
        mvprintw(5, 5, "PRESS DOWN KEY FOR OPTION");
        refresh();
        my_usleep(50000);
        key = getch();
        if (key == KEY_DOWN)
            key = option_func(tetris.keys[QUIT]);
        if (key == tetris.keys[QUIT])
            return (false);
    } while (key != '\n');
    return (true);
}