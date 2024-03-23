NAME	=	miniRT
BIN		=	bin
CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror
INC		=	-Iinc
OBJS	=	$(addprefix $(BIN)/, $(notdir $(SRCS:.c=.o)))
SRC		=	main
SRCS	=	$(addsuffix .c, $(addprefix src/, $(SRC)))

all: $(NAME)

$(BIN):
	mkdir -p $(BIN)

$(BIN)/%.o:src/%.c | $(BIN)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	/bin/rm -rf $(BIN)

fclean: clean
	/bin/rm -f $(NAME)

re: clean fclean all

.PHONY: all clean fclean re