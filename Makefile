# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hlehmann <hlehmann@student.42wolfsburg.de  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/22 15:32:58 by hlehmann          #+#    #+#              #
#    Updated: 2022/03/23 11:48:24 by hlehmann         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
CC = gcc
FLAGS = -Wall -Werror -Wextra -l readline
RM = rm -f
LFT = ./lft

SRC = src/main.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(SRC)
	make bonus -C $(LFT)
	$(CC) $(FLAGS) $(SRC) $(LFT)/libft.a -o $(NAME)

clean:
	make clean -C $(LFT)
	$(RM) $(OBJ)

fclean: clean
	make fclean -C $(LFT)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
