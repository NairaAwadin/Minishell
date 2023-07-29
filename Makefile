##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

SRC	=	my_str_to_word_array.c  \
		my_str_to_word_array_path.c	\
		my_word_array_sep.c	\
		my_put_str_char.c	\
		minishell.c		\
		path_env.c	\
		copie_env.c	\
		command_cd.c	\
		my_strdup.c	\
		my_strlen.c	\
		my_strcmp.c	\
		exit.c	\
		basic_command.c	\
		separator_function.c	\
		word_array_bin.c	\
		main.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-g

NAME	=	mysh

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) -Wall -Wextra

clean:
	rm -f $(OBJ)

fclean:	clean
	-rm -f $(NAME)

re:	fclean all
