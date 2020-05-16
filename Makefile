##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

.PHONY: all debug clean fclean re

NAME		=	asm/asm

SRC 		=	lib/my/fonction_printf/hexa.c \
				lib/my/fonction_printf/my_conv_oct.c \
				lib/my/fonction_printf/my_convhexa.c \
				lib/my/fonction_printf/my_printf.c \
				lib/my/fonction_printf/my_put_nbr.c \
				lib/my/fonction_printf/my_putchar.c \
				lib/my/fonction_printf/my_putstr_detect.c \
				lib/my/fonction_printf/my_putstr.c \
				lib/my/fonction_printf/number_case.c \
				lib/my/fonction_str_to_word/str_to_word.c \
				lib/my/list_fonction/list_fonction.c \
				lib/my/list_fonction/list_fonction2.c \
				lib/my/disp_stdarg.c \
				lib/my/corewar/assembleur/init_the_wall.c \
				lib/my/corewar/assembleur/create_the_file.c \
				lib/my/corewar/assembleur/analyse_fonct.c \
				lib/my/corewar/assembleur/function_bib.c \
				lib/my/corewar/op.c \
				lib/my/my_getnbr.c \
				lib/my/my_revstr.c \
				lib/my/my_strcpy.c \
				lib/my/my_strlen.c \
				lib/my/my_to_binary.c \
				lib/my/my_transformnbr.c \
				lib/my/parcour_2.c \
				lib/my/parcour.c \
				lib/my/same_char.c \
				lib/my/sum_stdarg.c \
				main.c \
				in_search_of_and_write.c

CC			?=	gcc

CPPFLAGS	=	-I./include/

CFLAGS		=	-W -Wall -Wextra

OBJ			=	$(SRC:.c=.o)

all:	$(NAME)

debug: CFLAGS += -g3
debug:	$(OBJ)
			$(CC) $(OBJ) -o $(NAME) $(CFLAGS) $(CPPFLAGS)

$(NAME): $(OBJ)
			$(CC) $(OBJ) -o $(NAME) $(CFLAGS)

clean:
			rm -f $(OBJ)

fclean:	clean
			rm -f $(NAME)

re:		fclean all
