/*
** EPITECH PROJECT, 2019
** Minishell.c
** File description:
** réussis
*/

#include "my.h"
#include "op.h"

int	conv_conv(int var)
{
    int temporaire;

    temporaire = 0;
    temporaire = (var & 0xFF000000) >> 24;
    temporaire |= ((var & 0x00FF0000) >> 8);
    temporaire |= (var & 0x0000FF00) << 8;
    temporaire |= ((var & 0x000000FF) << 24);
    return (temporaire);
}

char wiew_the_arg(core_t *info_gater, int i)
{
    char temporaire = 0x00;

    if (i == 0 && info_gater->argument[0] != NULL){
        if (info_gater->argument[0][0] == '%')
            return (temporaire = 0x80 >> 0);
        else if (info_gater->argument[0][0] == 'r')
            return (temporaire = 0x40 >> 0);
        else
            return (temporaire = 0xC0 >> 0);
    }
    if (i == 1 && info_gater->argument[1] != NULL){
        if (info_gater->argument[1][0] == '%')
            return (temporaire = 0x80 >> 2);
        else if (info_gater->argument[1][0] == 'r')
            return (temporaire = 0x40 >> 2);
        else
            return (temporaire = 0xC0 >> 2);
    }
    if (i == 2 && info_gater->argument[2] != NULL){
        if (info_gater->argument[2][0] == '%')
            return (temporaire = 0x80 >> 4);
        else if (info_gater->argument[2][0] == 'r')
            return (temporaire = 0x40 >> 4);
        else
            return (temporaire = 0xC0 >> 4);
    }
}

int put_the_byte(core_t *info_gater, int fd)
{
    char byte = 0x00;
    int i = 0;

    for(; info_gater->argument[i] != 0; i++)
        byte |= wiew_the_arg(info_gater, i);
    if (write(fd, &byte, sizeof(byte)) == -1)
        return (-1);
    return 0;
}

int ld_f(core_t *info_gater, int fd)
{
    char adress = 0X02;

    write(fd, &adress, sizeof(adress));
    put_the_byte(info_gater, fd);
    return 0;
}

void crea_info_gater(core_t *info_gater, char **doub_tab, int i)
{
    info_gater->name = malloc(sizeof(char) * 256);
    info_gater->argument = malloc(sizeof(char *) * 3);
    if (same_char(doub_tab[i], "live")) {
        my_strcpy(info_gater->name, "live");
        info_gater->argument[0] = malloc(sizeof(char) * 50);
        my_strcpy(info_gater->argument[0], doub_tab[i + 1]);
    }
    if (same_char(doub_tab[i], "ld")) {
        my_strcpy(info_gater->name, "ld");
        info_gater->argument[0] = malloc(sizeof(char) * 50);
        info_gater->argument[1] = malloc(sizeof(char) * 50);
        my_strcpy(info_gater->argument[0], doub_tab[i + 1]);
        my_strcpy(info_gater->argument[1], doub_tab[i + 2]);
    }
}

void analyse_fonction(char **doub_tab, int fd)
{
    core_t info_gater;

    for (int i = 0; doub_tab[i] != 0; i++){
        if (same_char("live", doub_tab[i]) == 1) {
            crea_info_gater(&info_gater, doub_tab, i);
            live_f(&info_gater, fd);
        }
        if (same_char("ld", doub_tab[i]) == 1) {
            crea_info_gater(&info_gater, doub_tab, i);
            ld_f(&info_gater, fd);
        }
        
    }
}