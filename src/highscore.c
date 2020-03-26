/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** highscore.c
*/

#include <stdio.h>
#include "tetris.h"

int get_highscore(char const *save_file)
{
    FILE *file = fopen(save_file, "r");
    int highscore = 0;

    if (file == NULL)
        return (0);
    fread(&highscore, sizeof(int), 1, file);
    fclose(file);
    return (highscore);
}

void save_highscore(int highscore, char const *save_file)
{
    FILE *file = fopen(save_file, "w");

    if (file == NULL)
        return;
    fwrite(&highscore, sizeof(int), 1, file);
    fclose(file);
}