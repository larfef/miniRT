NAME			=	miniRT
BIN				=	bin
CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror
INC				=	-Iinc
OBJS			=	$(addprefix $(BIN)/, $(notdir $(SRCS:.c=.o)))
FILE_PARSING	= 	read_file
SRC				=	main
SRCS			=	$(addsuffix .c, $(addprefix src/, $(SRC)))

all: $(NAME)

$(BIN):
	mkdir -p $(BIN)

$(BIN)/%.o:src/%.c | $(BIN)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(NAME): $(OBJS)
	make -C src/mlx42/build -j4
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -Lsrc/mlx42/build -L/Users/$(USER)/.brew/opt/glfw/lib/ -lglfw -lmlx -framework Cocoa -framework OpenGL -framework IOKit

clean:
	make -C src/mlx42/build clean
	/bin/rm -rf $(BIN)

fclean: clean
	/bin/rm -f $(NAME)

re: clean fclean all

.PHONY: all clean fclean re