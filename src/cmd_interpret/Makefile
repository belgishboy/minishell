NAME = parse_test
CC = gcc
FLAGS = -Wall -Werror -Wextra -l readline
RM = rm -f
LFT = ../../lft
PR = ./parse/ms_

SRC =	ms_extract_cmd.c \
		$(PR)arg_split.c \
		$(PR)cmd.c \
		$(PR)parse.c \
		$(PR)pipe_split.c \
		$(PR)rmv_quotes.c \
		$(PR)whitespace.c \
		$(PR)fd.c \

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