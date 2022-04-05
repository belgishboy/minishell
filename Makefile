
NAME = minishell
CC = gcc
FLAGS = -Wall -Werror -Wextra -l readline
RM = rm -f
LFT = ./lft
SR = ./src/
BI = $(SR)built-ins/
CMI = $(SR)cmd_interpret/
LU = $(CMI)launch/
PR = $(CMI)parse/ms_

SRC =	$(SR)main.c \
		$(BI)cd.c \
		$(BI)echo.c \
		$(BI)env.c \
		$(BI)export.c \
		$(BI)pwd.c \
		$(BI)signals.c \
		$(BI)unset.c \
		$(PR)arg_split.c \
		$(PR)cmd.c \
		$(PR)parse.c \
		$(PR)pipe_split.c \
		$(PR)rmv_quotes.c \
		$(PR)whitespace.c \
		$(PR)fd.c \
		$(CMI)ms_extract_cmd.c \
		$(CMI)ms_launch_cmd.c \
		$(LU)ms_exec_builtins.c \
		$(LU)ms_pipe.c \
		$(CMI)vars.c \

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
