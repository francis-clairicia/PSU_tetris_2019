/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** my_usleep.c
*/

#include <time.h>

int my_usleep(int useconds)
{
    struct timespec time_pause = {0, useconds * 1000};

    return (nanosleep(&time_pause, NULL));
}