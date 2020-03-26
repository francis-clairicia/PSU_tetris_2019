/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** test_highscore.c
*/

#include <unistd.h>
#include <stdio.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "tetris.h"

Test(hihgscore_function, save_and_load_the_highscore_of_the_player)
{
    int highscore = 472;
    char high_score_path[] = "tests/save.sav";

    save_highscore(highscore, high_score_path);
    cr_assert_eq(access(high_score_path, F_OK), 0);
    cr_assert_eq(get_highscore(high_score_path), highscore);
    remove(high_score_path);
}