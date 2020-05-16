/*
** EPITECH PROJECT, 2019
** Minishell.c
** File description:
** réussis
*/

#include "my.h"
#include "op.h"

void create_the_double_cut_tab(thewall_t *thewall)
{ // 29/20 lignes
    int len_1 = 0;
    int len_2 = 0;
    int len_3 = 0;
    int space = 0;
    int vir = 0;

    thewall->info_cut[len_2] = malloc(sizeof(char) * my_strlen(thewall->info_write)); //trop long
    for (;thewall->info_write[len_1] != '\0'; len_1++){
        if (vir > 3){
            if (thewall->info_write[len_1] == ' ' && space == 0 || thewall->info_write[len_1] == '\t' && space == 0) { //trop long
                len_2++;
                len_3 = 0;
                thewall->info_cut[len_2] = malloc(sizeof(char) * my_strlen(thewall->info_write)); //trop long
                space = 1;
            }
            if (thewall->info_write[len_1] != ' ' && thewall->info_write[len_1] != '\t') { //trop long
                if (thewall->info_write[len_1] == '\n' || thewall->info_write[len_1] == ',') //trop long
                    thewall->info_cut[len_2][len_3] = '\0';
                else
                    thewall->info_cut[len_2][len_3] = thewall->info_write[len_1]; //trop long
                len_3++;
                space = 0;
            }
        }
        if (vir <= 4)
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
    write(thewall.fd, &temporaire, sizeof(temporaire) - 3);
    /*-----------------------------------------------------*/
    write_the_comment(&thewall);
    /*analyse_fonction(thewall.info_cut, thewall.fd);*/

    return 0;
}