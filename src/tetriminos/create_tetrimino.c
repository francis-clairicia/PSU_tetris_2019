/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** create_tetrimino.c
*/

#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "tetris.h"

static bool load_file(tetrimino_t *tetrimino, char const *path)
{
    char *buffer = NULL;
    struct stat infos;
    bool status = true;
    int fd = open(path, O_RDONLY);

    if (fd < 0 || fstat(fd, &infos) == -1) {
        if (fd > 0)
            close(fd);
        return (false);
    }
    buffer = my_memset(malloc(infos.st_size + 1), 0, infos.st_size + 1);
    if (buffer != NULL) {
        if (read(fd, buffer, infos.st_size) != infos.st_size)
            status = false;
        else
            tetrimino->array = my_str_to_word_array(buffer, "\n");
        free(buffer);
    }
    close(fd);
    return ((buffer == NULL) ? false : status);
}

static char *get_name(char const *tetrimino_path)
{
    int ending = my_strstr_index(tetrimino_path, ".tetrimino");
    int start = ending - 1;

    while (start > 0 && tetrimino_path[start - 1] != '/')
        start -= 1;
    return (my_strndup(&tetrimino_path[start], ending - start));
}

tetrimino_t *create_tetrimino(char const *tetrimino_path)
{
    tetrimino_t *tetrimino = malloc(sizeof(*tetrimino));

    if (tetrimino != NULL) {
        tetrimino->name = get_name(tetrimino_path);
        tetrimino->color = -1;
        tetrimino->width = -1;
        tetrimino->height = -1;
        tetrimino->array = NULL;
        tetrimino->pos = (vector_t){0, 0};
        if (!load_file(tetrimino, tetrimino_path)) {
            free(tetrimino);
            return (NULL);
        }
        parse_tetrimino(tetrimino);
    }
    return (tetrimino);
}