/*
** EPITECH PROJECT, 2020
** corewar
** File description:
** start of the error handling-desu
*/

#include "my_error.h"

int error(char *name)
{
    FILE *adres;
    input_t *info = NULL;

    if (open(name, (O_RDONLY | O_DIRECTORY)) != -1)
        return 84;
    adres = fopen(name, "r");
    if (adres == NULL)
        return 84;
    info = input_taker(adres);
//    for (; info->next != NULL;) {
//        //printf("%ld\n", info->len);
//        printf("%s", info->line);
//        info = info->next;
//    }
//    printf("POST\n");
    info = input_rewinder(info);
    return error_master(info);
    //return 0;
}