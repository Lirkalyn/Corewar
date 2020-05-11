/*
** EPITECH PROJECT, 2019
** my_to_binary.c.c
** File description:
** réussis
*/

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include "my.h"

char *my_to_binary(int v)
{
    char *res = malloc(sizeof(char) * v);
    int j = 0;
    int l = 0;

    while (v != 0 && v != 1) {
        l = v % 2;
        res[j] = my_transformnbr(l);
        j++;
        v = v / 2;
    }
    res[j] = my_transformnbr(v);
    my_revstr(res);
    return res;
}