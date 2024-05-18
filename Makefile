NAME			=	miniRT
BIN				=	bin
CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror -g
INC				=	-Iinc -Isrc/libft/inc/ -Isrc/gnl/
OBJS			=	$(addprefix $(BIN)/, $(notdir $(SRCS:.c=.o)))
FILE_PARSING	= 	ambient_light_parsing check_rgb ft_atod open_file parse_line read_file set_current_line_type set_duplicate_check utils_check utils_skip
GNL				=	get_next_line get_next_line_utils	
SRC				=	main
SRCS			=	$(addsuffix .c, $(addprefix src/, $(SRC))) \
					$(addsuffix .c, $(addprefix src/gnl/, $(GNL))) \
					$(addsuffix .c, $(addprefix src/file_parsing/, $(FILE_PARSING)))
all: $(NAME)

$(BIN):
	mkdir -p $(BIN)

$(BIN)/%.o:src/%.c | $(BIN)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(BIN)/%.o:src/file_parsing/%.c | $(BIN)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(BIN)/%.o:src/gnl/%.c | $(BIN)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(NAME): $(OBJS)
	make -C src/libft
	make -C src/mlx42/build -j4
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -Lsrc/libft -Lsrc/mlx42/build -L/Users/$(USER)/.brew/opt/glfw/lib/ -lft -lglfw -lmlx -framework Cocoa -framework OpenGL -framework IOKit

clean:
	make -C src/libft clean
	make -C src/mlx42/build clean
	/bin/rm -rf $(BIN)

fclean: clean
	/bin/rm -f $(NAME)

re: clean fclean all

.PHONY: all clean fclean re