NAME			=	miniRT
BIN				=	bin
CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror -g
INC				=	-Iinc -Isrc/libft/inc/ -Isrc/gnl/
OBJS			=	$(addprefix $(BIN)/, $(notdir $(SRCS:.c=.o)))
FILE_PARSING	= 	exit init_instructions init_parsing_functions is_duplicate is_length_valid is_line_valid is_orientation_valid is_rgb_valid ft_atof\
					is_coordinates_valid is_brightness_valid is_end_of_line_valid is_file_valid is_filename_valid is_light_ratio_valid is_minimal_scene_valid\
					open_file parse_line read_file set_current_line_type set_duplicate_check utils_check utils_skip
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
	# make -C src/mlx42/build -j4
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -Lsrc/libft -lft
	# -Lsrc/mlx42/build -L/Users/$(USER)/.brew/opt/glfw/lib/
	# -lglfw -lmlx -framework Cocoa -framework OpenGL -framework IOKit

clean:
	make -C src/libft clean
	make -C src/mlx42/build clean
	/bin/rm -rf $(BIN)

fclean: clean
	make -C src/libft fclean
	/bin/rm -f $(NAME)

re: clean fclean all

.PHONY: all clean fclean re