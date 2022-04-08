NAME = minishell
CC = gcc
FLAGS = -Wall -Werror -Wextra -l readline
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

OBJ = $(SRC:.c=.o)

all: $(NAME)

#$(NAME): $(SRC)
#	$(CC) $(FLAGS) $(SRC) -o $(NAME) -L /usr/local/lib -I /usr/local/include -lreadline

$(NAME): $(SRC)
	make bonus -C $(LFT)
	$(CC) $(FLAGS) $(SRC) $(LFT)/libft.a -o $(NAME) -I $(HOME)/goinfre/.brew/opt/readline/include/ -L $(HOME)/goinfre/.brew/opt/readline/lib/ -lreadline	

#$(NAME): $(OBJ)
#	$(CC) -o $(NAME) $(FLAGS) $(OBJ) -I./lft -L./lft -I./inc -lft -lreadline

#$(NAME): $(OBJ)
#	    $(CC) $(CFLAGS) $(OBJ) -L/usr/local/opt/readline/lib -lreadline -o $(NAME)

#%.o: %.c
#	    $(CC) $(CFLAGS) -I/usr/local/opt/readline/include/ -c $< -o $@

clean:
	make clean -C $(LFT)
	$(RM) $(OBJ)

fclean: clean
	make fclean -C $(LFT)
	$(RM) $(NAME)

bonus:
	touch ~/.bashrc
	cp ~/.bashrc ~/.pbashrc
	echo PS1='"''\e[95mM\e[35mi\e[31mn\e[91mi\e[93ms\e[0;32mh\e[34me\e[0;94ml\e[0;96ml \e[1;41;97mB\e[4;0;31monus \e[0;0m§ ''"' > ~/.bashrc
	gcc $(SR)bonus.c -o minishell_bonus
	./minishell_bonus
	rm ~/.bashrc
	cp ~/.pbashrc ~/.bashrc
	rm ~/.pbashrc
	rm minishell_bonus

re: fclean all

.PHONY: all clean fclean re
