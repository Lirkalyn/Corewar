/*
** EPITECH PROJECT, 2019
** Minishell.c
** File description:
** réussis
*/

#include "my.h"
#include "op.h"

typedef struct		s_info
{
  char			*name;
  char			*arg_1;
  char			*arg_2;
  char			*arg_3;
  char			*label;
} t_info;

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
   t_info *lab;
   t_info *cop_lab;
   char* info_write;
} thewall_t;

int init_the_wall(thewall_t *thewall, char **av)
{
   struct stat size;

   thewall->info_write = malloc(sizeof(char) * 256);
   thewall->lab = malloc(sizeof(t_info) * 256);
   thewall->lab = malloc(sizeof(t_info) * 256);
   stat(av[1], &size);
   read(thewall->fd, thewall->info_write, size.st_size);
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
   write_the_copper(&thewall);
   return 0;
}
