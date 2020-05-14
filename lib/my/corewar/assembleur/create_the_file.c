/*
** EPITECH PROJECT, 2019
** Minishell.c
** File description:
** réussis
*/

#include "my.h"
#include "op.h"

int create_the_file(char *name, thewall_t *thewall)
{
    char *new_name = malloc(sizeof(char) * 100 + 5);
    int arr[2];
    char extend[5] = ".cor";
    int fd = 0;
    int fd2 = 0;
    struct stat size;

    arr[0] = 0;
    arr[1] = 0;
    for (arr[0] = 0; name[arr[0]] != '\0' && name[arr[0]] != '.'; arr[0]++)
        new_name[arr[0]] = name[arr[0]];
    for (arr[1] = 0; arr[1] <= 4; arr[1]++){
        new_name[arr[0]] = extend[arr[1]];
        arr[0]++;
}
    new_name[arr[0] - 1] = '\0';
    if ((fd = open(new_name, O_WRONLY | O_CREAT | O_TRUNC,
    S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH)) == -1)
        return (-1);
    return fd;
}