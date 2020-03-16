/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** load_tetriminos.c
*/

#include <dirent.h>
#include "tetris.h"
#include "my.h"
#include "mylist.h"

static bool str_ends_with(char *str, char const *to_find)
{
    char *ptr = my_strstr(str, to_find);

    if (ptr == NULL)
        return (false);
    return (my_strlen(ptr) == my_strlen(to_find));
}

list_t *load_tetriminos(void)
{
    char tetriminos_folder[] = "./tetriminos/";
    DIR *folder = opendir(tetriminos_folder);
    char *path = NULL;
    list_t *tetriminos = NULL;
    struct dirent *ent = NULL;

    if (folder == NULL)
        return (NULL);
    while ((ent = readdir(folder)) != NULL) {
        if (str_ends_with(ent->d_name, ".tetrimino")) {
            path = join_path(tetriminos_folder, ent->d_name);
            my_append_to_list(&tetriminos, (long)create_tetrimino(path));
            free(path);
        }
    }
    closedir(folder);
    return (tetriminos);
}