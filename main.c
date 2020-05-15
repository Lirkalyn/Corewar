/*
** EPITECH PROJECT, 2019
** Minishell.c
** File description:
** réussis
*/

#include "my.h"
#include "op.h"

int write_the_copper(thewall_t *thewall)
{
    int copperfield = COREWAR_EXEC_MAGIC;
    int temporaire = 0;

    temporaire = (copperfield & 0xFF000000) >> 24;
    temporaire |= ((copperfield & 0x00FF0000) >> 8);
    temporaire |= (copperfield & 0x0000FF00) << 8;
    temporaire |= ((copperfield & 0x000000FF) << 24);
    copperfield = temporaire;
    if (write(thewall->fd, &copperfield, sizeof(copperfield)) == -1)
       return (1);
    return 0;
}

void in_search_of_the_name(char *command, char *name_to_put)
{
    int i = 0;
    int j = 0;

    for (i = 0; command[i] != '"' && command[i] != '\0'; i++);
    i++;
    name_to_put[j] = command[i];
    for (; command[i] != '"' && command[i] != '\0'; i++){
        name_to_put[j] = command[i];
        j++;
    }
    name_to_put[j] = '\0';

}

void write_the_name(char *name, int fd)
{
    int size = 129;
    int j = 0;

    size = size - my_strlen(name);
    write(fd, name, my_strlen(name));
    while (j < size + 4){
        write(fd, "\0", 1);
        j++;
    }
}

void in_search_of_the_comment(thewall_t *thewall)
{
    int nbr_p = 0;
    int jej = 0;
    int kek = 0;

    for (jej = 0; thewall->info_write[jej] != '\0' && nbr_p < 3; jej++)
        if (thewall->info_write[jej] == '"')
            nbr_p++;
    jej--;
    if (thewall->info_write[jej] == '"'){
        jej++;
        for (; thewall->info_write[jej] != '"' && thewall->info_write[jej] != '\0'; jej++){
            thewall->coment[kek] = thewall->info_write[jej];
            kek++;
        }
    }
    thewall->coment[kek - 1] = '\0'; 
}

int write_the_comment(thewall_t *thewall)
{
    int i = -1;
    int taille;

    in_search_of_the_comment(thewall);
    write(thewall->fd, thewall->coment, my_strlen(thewall->coment));
    taille = 2052 - my_strlen(thewall->coment);
    while (i < taille){
        write(thewall->fd, "\0", 1);
        i++;
    }
    return 0;
}

void create_the_double_cut_tab(thewall_t *thewall)
{
    int len_1 = 0;
    int len_2 = 0;
    int len_3 = 0;
    int space = 0;
    int vir = 0;

    thewall->info_cut[len_2] = malloc(sizeof(char) * my_strlen(thewall->info_write));
    for(;thewall->info_write[len_1] != '\0'; len_1++){
        if (vir > 3){
            if (thewall->info_write[len_1] == ' ' && space == 0 || thewall->info_write[len_1] == '\t' && space == 0){
                len_2++;
                len_3 = 0;
                thewall->info_cut[len_2] = malloc(sizeof(char) * my_strlen(thewall->info_write));
                space = 1;
            }
            if (thewall->info_write[len_1] != ' ' && thewall->info_write[len_1] != '\t'){
                if (thewall->info_write[len_1] == '\n' || thewall->info_write[len_1] == ',')
                    thewall->info_cut[len_2][len_3] = '\0';
                else
                    thewall->info_cut[len_2][len_3] = thewall->info_write[len_1];
                len_3++;
                space = 0;
            }
        }
        if(vir <= 4)
            if (thewall->info_write[len_1] == '"')
                vir++;
    }
    thewall->info_cut[len_2 + 1] = 0; 
}

int main(int ac, char **av, char **en)
{
    head_t head;
    thewall_t thewall;

    if (ac != 2){
        my_printf("Wrong argument\n");
        return 84;
    }
    init_the_wall(&thewall, av);
    thewall.fd = create_the_file(av[1], &thewall);
    in_search_of_the_name(thewall.info_write, thewall.name);
    write_the_copper(&thewall);
    write_the_name(thewall.name, thewall.fd);
    create_the_double_cut_tab(&thewall);
   /*---------------------------------------------*/
    int prog_size = 1;
    int addr = 136;

    int temporaire = 0;
    temporaire = (prog_size & 0xFF000000) >> 24;
    temporaire |= ((prog_size & 0x00FF0000) >> 8);
    temporaire |= (prog_size & 0x0000FF00) << 8;
    temporaire |= ((prog_size & 0x000000FF) << 24);
    write(thewall.fd, &temporaire, sizeof(temporaire));
   /*-----------------------------------------------------*/
    write_the_comment(&thewall);
    analyse_fonction(thewall.info_cut, thewall.fd);

    return 0;
}


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