UNAME_S			:= $(shell uname -s)
NAME			=	miniRT
BIN				=	bin
DEP				=	dep
CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror -g -fsanitize=address
LDFLAGS			:=
INC				=	-Iinclude -Iinc -Isrc/libft/inc/ -Isrc/gnl/ -Isrc/mlx/
OBJS			=	$(addprefix $(BIN)/, $(notdir $(SRCS:.c=.o)))
DEPS			=	$(addprefix $(DEP)/, $(notdir $(SRCS:.c=.d)))
FILE_PARSING	= 	exit init_instructions init_parsing_functions init_file is_duplicate is_length_valid is_line_valid is_orientation_valid is_rgb_valid ft_atof\
					is_coordinates_valid is_brightness_valid is_end_of_line_valid is_file_valid is_filename_valid is_light_ratio_valid is_minimal_scene_valid\
					is_size_valid open_file parse_line read_file set_current_line_type utils_check utils_skip
GNL				=	get_next_line get_next_line_utils
HOOKS			=	close_window init_hooks k_input
INIT_STACK		=	_exit extract_file_data free_list init_fct_ptr init_stack set_element_type set_shape_type
OPERATION		:=	add_point add_vector at cross_product cylinder_normal dot_product get_cos length multiply_point\
					multiply_vector normalize sub_point sub_vector
UTILS			=	progress_bar
RENDERING		=	cylinder_intersection get_nearest_intersection init_fct_ptr_normal iterate_through_shapes_list iterate_through_viewport jittered_grid plane_intersection \
					set_normal set_pixel_color sphere_intersection trace_rays vector_utils
WINDOW_MANAGEMENT = create_window exit_error get_vup init_window_struct set_pixel00_loc set_pixel_center set_pixel_delta set_upper_left_pixel\
					set_viewport set_viewport_vectors set_window_height
SRC				=	main
SRCS			=	$(addsuffix .c, $(addprefix src/utils/, $(UTILS))) \
					$(addsuffix .c, $(addprefix src/, $(SRC))) \
					$(addsuffix .c, $(addprefix src/gnl/, $(GNL))) \
					$(addsuffix .c, $(addprefix src/hooks/, $(HOOKS))) \
					$(addsuffix .c, $(addprefix src/file_parsing/, $(FILE_PARSING))) \
					$(addsuffix .c, $(addprefix src/init_stack/, $(INIT_STACK))) \
					$(addsuffix .c, $(addprefix src/operation/, $(OPERATION))) \
					$(addsuffix .c, $(addprefix src/rendering/, $(RENDERING))) \
					$(addsuffix .c, $(addprefix src/window_management/, $(WINDOW_MANAGEMENT)))

ifeq ($(UNAME_S), Linux)
    LDFLAGS += -lmlx_Linux -lX11 -lXext -lm
endif

ifeq ($(UNAME_S), Darwin)
    LDFLAGS +=  -framework OpenGL -framework AppKit
endif

all: $(NAME)

$(BIN):
	mkdir -p $(BIN)

$(DEP):
	mkdir -p $(DEP)

-include $(DEPS)

$(BIN)/%.o:src/%.c | $(BIN) $(DEP)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@
	$(CC) $(CFLAGS) $(INC) -MM $< > $(DEP)/$*.d

$(BIN)/%.o:src/file_parsing/%.c | $(BIN) $(DEP)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@
	$(CC) $(CFLAGS) $(INC) -MM $< > $(DEP)/$*.d

$(BIN)/%.o:src/gnl/%.c | $(BIN) $(DEP)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@
	$(CC) $(CFLAGS) $(INC) -MM $< > $(DEP)/$*.d

$(BIN)/%.o:src/init_stack/%.c | $(BIN) $(DEP)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@
	$(CC) $(CFLAGS) $(INC) -MM $< > $(DEP)/$*.d

$(BIN)/%.o:src/rendering/%.c | $(BIN) $(DEP)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@
	$(CC) $(CFLAGS) $(INC) -MM $< > $(DEP)/$*.d

$(BIN)/%.o:src/window_management/%.c | $(BIN) $(DEP)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@
	$(CC) $(CFLAGS) $(INC) -MM $< > $(DEP)/$*.d

$(BIN)/%.o:src/utils/%.c | $(BIN) $(DEP)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@
	$(CC) $(CFLAGS) $(INC) -MM $< > $(DEP)/$*.d

$(BIN)/%.o:src/hooks/%.c | $(BIN) $(DEP)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@
	$(CC) $(CFLAGS) $(INC) -MM $< > $(DEP)/$*.d

$(BIN)/%.o:src/operation/%.c | $(BIN) $(DEP)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@
	$(CC) $(CFLAGS) $(INC) -MM $< > $(DEP)/$*.d

$(NAME): $(OBJS)
	make -C src/libft
	#make -C src/mlx42/build -j4
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -Lsrc/libft -lft -Lsrc/mlx -lmlx $(LDFLAGS)
	# -Lsrc/mlx42/build -L/Users/$(USER)/.brew/opt/glfw/lib/
	# -lglfw -lmlx -framework Cocoa -framework OpenGL -framework IOKit

clean:
	make -C src/libft clean
	#make -C src/mlx42/build clean
	/bin/rm -rf $(BIN) $(DEP)

fclean: clean
	make -C src/libft fclean
	/bin/rm -f $(NAME)

re: clean fclean all

.PHONY: all clean fclean re