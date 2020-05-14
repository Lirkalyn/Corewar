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
}

int main(int ac, char **av, char **en)
{
    head_t head;
    thewall_t thewall;
    struct stat size;

    if (ac != 2){
        my_printf("Wrong argument\n");
        return 84;
    }
    init_the_wall(&thewall, av);
    thewall.fd = create_the_file(av[1], &thewall);
    in_search_of_the_name(thewall.info_write, thewall.name);
    write_the_copper(&thewall);
    write_the_name(thewall.name, thewall.fd);
   /*---------------------------------------------*/
   /*lseek(thefd, addr, SEEK_SET);
   prog_size = convert_littleend_to_bigend_int(prog_size);
   write(fd, &prog_size, sizeof(prog_size));*/
   /*-----------------------------------------------------*/
    in_search_of_the_comment(&thewall);
    write(thewall.fd, &thewall.coment, my_strlen(thewall.coment));
   /*--------------------------------------------------------*/
   return 0;
}
