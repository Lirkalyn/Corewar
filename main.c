/*
** EPITECH PROJECT, 2019
** Minishell.c
** File description:
** réussis
*/

#include "my.h"
#include "op.h"

typedef struct header_yes
{
   int copperfield;
   char name[256];
   int size;
   char comment[256];
} head_t;

typedef struct info_yes
{
   int fd;
   int lenght;
   char* name;
   char* info_write;
} thewall_t;

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

int create_the_file(char *name)
{
   char *new_name = malloc(sizeof(char) * my_strlen(name) + 5);
   int i = 0;
   char extend[4] = ".cor";
   int j = 0;
   int fd;
   
   for (i = 0; name[i] != '\0' && name[i] != '.'; i++)
      new_name[i] = name[i];
   for (j = 0; j <= 4; j++){
      new_name[i] = extend[j];
      i++;
   }
   new_name[i - 1] = '\0';
   if ((fd = open(new_name, O_WRONLY | O_CREAT | O_TRUNC,
   S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH)) == -1)
      return (-1);
   return fd;
   
}

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

   for(i = 0; command[i] != '"' && command[i] != '\0'; i++);
   i++;
   name_to_put[j] = command[i];
   for(;command[i] != '"'; i++){
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
   thewall.fd = create_the_file(av[1]);
   in_search_of_the_name(thewall.info_write, thewall.name);
   write_the_copper(&thewall);
   write_the_name(thewall.name, thewall.fd);
   /*---------------------------------------------*/
   /*lseek(thefd, addr, SEEK_SET);
   prog_size = convert_littleend_to_bigend_int(prog_size);
   write(fd, &prog_size, sizeof(prog_size));*/
   /*-----------------------------------------------------*/
   return 0;
}
