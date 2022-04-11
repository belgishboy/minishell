NAME = minishell
CC = gcc
FLAGS = -Wall -Werror -Wextra
RM = rm -f
LFT = ./lft
SR = ./src/
BI = $(SR)built-ins/
CMI = $(SR)cmd_interpret/
LU = $(CMI)launch/
CL = $(CMI)clean/
PR = $(CMI)parse/ms_

SRC =	$(SR)main.c \
		$(BI)cd.c \
		$(BI)echo.c \
		$(BI)env.c \
		$(BI)exit.c \
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
		$(CL)ms_free_seq.c \
		$(CL)ms_close_fd.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(SRC)
	make bonus -C $(LFT)
	$(CC) $(FLAGS) $(SRC) $(LFT)/libft.a -o $(NAME) -I $(HOME)/goinfre/.brew/opt/readline/include/ -L $(HOME)/goinfre/.brew/opt/readline/lib/ -l readline

clean:
	make clean -C $(LFT)
	$(RM) $(OBJ)

fclean: clean
	make fclean -C $(LFT)
	$(RM) $(NAME)
	- rm minishell_bonus


bonus:
	touch ~/.bashrc
	cp ~/.bashrc ~/.pbashrc
	echo PS1='"''\e[95mM\e[35mi\e[31mn\e[91mi\e[93ms\e[0;32mh\e[34me\e[0;94ml\e[0;96ml \e[1;41;97mB\e[4;0;31monus \e[0;0m§ ''"' > ~/.bashrc
	$(CC) $(SR)bonus.c $(FLAGS) -o minishell_bonus
	./minishell_bonus
	rm ~/.bashrc
	cp ~/.pbashrc ~/.bashrc
	rm ~/.pbashrc
	rm minishell_bonus

re: fclean all

.PHONY: all clean fclean re
