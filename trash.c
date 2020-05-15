/*
** EPITECH PROJECT, 2020
** corewar
** File description:
** just here for garbage code or heavy WIP code
*/

/*



/*
** EPITECH PROJECT, 2019
** Minishell.c
** File description:
** réussis


#include "my.h"
#include "op.h"

typedef struct core_f
{
    char *name;
    char **argument;
} core_t;

int	conv_conv(int var)
{
    int   tmp;

    tmp = 0;
    tmp = (var & 0xFF000000) >> 24;
    tmp |= ((var & 0x00FF0000) >> 8);
    tmp |= (var & 0x0000FF00) << 8;
    tmp |= ((var & 0x000000FF) << 24);
    return (tmp);
}

int	live_f(core_t *info_gater, int fd)
{
    char hexa;
    int	arg;
    char *arg_de_rechange = malloc(sizeof(char) * 256);
    int i = 1;
    int v = 0;

    hexa = 0x01;
    if (write(fd, &hexa, sizeof(hexa)) == -1)
        return 1;
    if(argument[0][0] == '%'){
        for (i = 1; argument[0][i] != '\0'; i++)
            arg_de_rechange[i - 1] = argument[0][i];
    }

    arg = atoi(&arg_de_rechange);
    arg = conv_conv(arg);
    if (write(fd, &arg, sizeof(arg)) == -1)
        return (1);
    return (0);

}

void crea_info_gater(core_t *info_gater, char **doub_tab)
{   
    int i = 0;

    info_gater->name = malloc(sizeof(char) * 256);
    info_gater->argument = malloc(sizeof(char *) * 3);
    for(; doub_tab[i] != 0; i++)
    {
        if (same_char(doub_tab[i], "live")){
            my_strcpy(info_gater->name, "live");
            info_gater->argument[0] = malloc(sizeof(char) * 50);
            my_strcpy(info_gater->argument[0], doub_tab[i + 1]);
        }
    }
}

void analyse_fonction(char **doub_tab, int fd)
{   
    core_t info_gater;

    for (int i = 0; doub_tab[i] != 0; i++){
        if (same_char("live", doub_tab[i]) == 1){
            crea_info_gater(&info_gater, doub_tab);
            live_f(&info_gater, fd);
        }
    }
}


*/