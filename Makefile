# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdahlhof <cdahlhof@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/22 15:32:58 by hlehmann          #+#    #+#              #
#    Updated: 2022/04/05 09:59:53 by cdahlhof         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
CC = gcc
FLAGS = ##-Wall -Werror -Wextra -l readline
RM = rm -f
LFT = ./lft

SRC =	src/main.c \
		src/built-ins/echo.c \
		src/built-ins/env.c \
		src/built-ins/export.c \
		src/built-ins/pwd.c \
		src/built-ins/signals.c \
		src/built-ins/unset.c \
		src/cmd_interpret/parse/ms_arg_split.c \
		src/cmd_interpret/parse/ms_pipe_split.c \
		src/cmd_interpret/parse/ms_whitespace.c \
		src/cmd_interpret/ms_extract_cmd.c \
		src/cmd_interpret/ms_launch_cmd.c \
		src/cmd_interpret/vars.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(SRC)
	make bonus -C $(LFT)
	$(CC) $(FLAGS) $(SRC) $(LFT)/libft.a -o $(NAME) -I $(HOME)/goinfre/.brew/opt/readline/include/ -L $(HOME)/goinfre/.brew/opt/readline/lib/ -lreadline	

clean:
	make clean -C $(LFT)
	$(RM) $(OBJ)

fclean: clean
	make fclean -C $(LFT)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
