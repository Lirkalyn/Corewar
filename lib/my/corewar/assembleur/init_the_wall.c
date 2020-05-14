/*
** EPITECH PROJECT, 2019
** Minishell.c
** File description:
** réussis
*/

#include "my.h"
#include "op.h"

int init_the_wall(thewall_t *thewall, char **av)
{
    struct stat size;
    int fd = open(av[1], O_RDONLY);

    thewall->info_write = malloc(sizeof(char) * 256);
    thewall->name = malloc(sizeof(char) * 256);
    stat(av[1], &size);
    read(fd, thewall->info_write, size.st_size);
    thewall->info_write[size.st_size - 1] = '\0';
}