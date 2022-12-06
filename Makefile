# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/28 00:46:12 by ensebast          #+#    #+#              #
#    Updated: 2022/12/06 00:18:51 by ensebast         ###   ########.br        #
#                                                                              #
# **************************************************************************** #

NAME := miniRT
NAME_B := miniRT_b

INCLUDE := -I ./include/ -I ./libft -I ./minilibx-linux/
INCLUDE_B := -I ./bonus/include/ -I ./libft/ -I ./minilibx-linux/

CC := clang
LIB := ./minilibx-linux/libmlx_Linux.a

CFLAGS := -g -lm -lX11 -lXext
CHECKFLAG := -Wall -Wextra -Werror

LIBFT := ./libft/libft.a

RM := rm -rf

# Source files
FILES_M := main.c \
		camera_compute.c\
		check_line.c \
		checker_ambient.c \
		checker_format.c \
		extension_check.c \
		micro_regex.c \
		segment_checker.c \
		util_check.c \
		prepare_ambient.c \
		prepare_elem.c \
		parse_ambient.c \
		parse_format.c \
		parse_line.c \
		segment_parse.c \
		str_to_double.c \
		str_to_int.c \
		val_range_check.c \
		mlx_draw.c \
		mlx_key.c \
		mlx_prepare.c \
		mlx_start.c \
		get_line.c \
		make_color.c \
		cmp_float.c \
		create_comp.c \
		m_create.c \
		m_det.c \
		m_op.c \
		m_transform.c \
		m_orientation.c \
		shadow.c \
		lighting.c \
		material.c \
		set_transform.c \
		tup_op.c \
		tup_s_op.c \
		tup_reflect.c \
		tup_create.c \
		c_create.c \
		c_op.c \
		normal_at.c \
		ray_op.c \
		ray_for_pixel.c \
		alloc_mem.c \
		dealloc_mem.c \
		deg_to_rad.c \
		intersect.c \
		raytrace.c \
		sphere.c \
		cylinder.c \
		plane.c

# Source files - Bonus
FILES_B := main_bonus.c \
		camera_compute_bonus.c\
		check_line_bonus.c \
		check_pattern_bonus.c \
		checker_ambient_bonus.c \
		checker_format_bonus.c \
		extension_check_bonus.c \
		micro_regex_bonus.c \
		segment_checker_bonus.c \
		util_check_bonus.c \
		prepare_pattern_bonus.c \
		prepare_ambient_bonus.c \
		prepare_elem_bonus.c \
		parse_pattern_type_bonus.c \
		parse_ambient_bonus.c \
		parse_format_bonus.c \
		parse_line_bonus.c \
		segment_parse_bonus.c \
		str_to_double_bonus.c \
		str_to_int_bonus.c \
		val_range_check_bonus.c \
		mlx_pixel_op_bonus.c \
		mlx_key_bonus.c \
		mlx_prepare_bonus.c \
		mlx_start_bonus.c \
		get_line_bonus.c \
		get_pixel_color_bonus.c \
		make_color_bonus.c \
		cmp_float_bonus.c \
		create_comp_bonus.c \
		m_create_bonus.c \
		m_det_bonus.c \
		m_op_bonus.c \
		m_transform_bonus.c \
		m_orientation_bonus.c \
		shadow_bonus.c \
		lighting_bonus.c \
		material_bonus.c \
		set_transform_bonus.c \
		tup_op_bonus.c \
		tup_s_op_bonus.c \
		tup_reflect_bonus.c \
		tup_create_bonus.c \
		c_create_bonus.c \
		c_op_bonus.c \
		normal_at_bonus.c \
		ray_op_bonus.c \
		ray_for_pixel_bonus.c \
		alloc_mem_bonus.c \
		dealloc_mem_bonus.c \
		deg_to_rad_bonus.c \
		intersect_bonus.c \
		raytrace_bonus.c \
		sphere_bonus.c \
		cylinder_bonus.c \
		cone_bonus.c \
		plane_bonus.c \
		uv_map_bonus.c \
		checker_pattern_bonus.c \
		pattern_at_bonus.c

VPATH := ./src/arg_integrity/\
		 ./src/parser/\
		 ./src/vector_op/\
		 ./src/util/\
		 ./src/mlx_util/\
		 ./src/raytrace/\
		 ./src/main/\
		 ./src/math_op/\
		 ./src/alloc_mem/\
		 ./src/ray/\
		 ./src/light/\
		 ./src/color/\
		 ./src/camera/\
		 ./src/prepare/\
		 ./bonus/arg_integrity/\
		 ./bonus/parser/\
		 ./bonus/vector_op/\
		 ./bonus/util/\
		 ./bonus/mlx_util/\
		 ./bonus/raytrace/\
		 ./bonus/main/\
		 ./bonus/math_op/\
		 ./bonus/alloc_mem/\
		 ./bonus/ray/\
		 ./bonus/light/\
		 ./bonus/color/\
		 ./bonus/camera/\
		 ./bonus/prepare/\
		 ./bonus/uv_mapping/

FILE_OBJ := $(FILES_M:c=o)
FILE_OBJ_B := $(FILES_B:c=o)

DIR_OBJ := ./obj/
DIR_OBJ_B := ./obj_b/

OBJ_B := $(addprefix $(DIR_OBJ_B), $(FILE_OBJ_B))
OBJ_M := $(addprefix $(DIR_OBJ), $(FILE_OBJ))

all: $(NAME)

bonus: $(NAME_B)

$(DIR_OBJ)%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(INCLUDE) $(CHECKFLAG) -O3 -c $^ -o $@

$(DIR_OBJ_B)%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(INCLUDE_B) $(CHECKFLAG) -O3 -c $^ -o $@

$(LIBFT):
	make -C libft

$(LIB):
	make -C ./minilibx-linux/

$(NAME): $(OBJ_M) $(LIBFT) $(LIB)
	$(CC) -O3 $(CHECKFLAG) $(CFLAGS) -o $@ $(OBJ_M) $(LIBFT) $(LIB)

$(NAME_B): $(OBJ_B) $(LIBFT) $(LIB)
	$(CC) -O3 $(CHECKFLAG) $(CFLAGS) -o $@ $(OBJ_B) $(LIBFT) $(LIB)

clean:
	$(RM) $(DIR_OBJ)
	$(RM) $(DIR_OBJ_B)
	make clean -C libft

fclean: clean
	$(RM) $(NAME)
	$(RM) $(NAME_B)
	make fclean -C libft
	make clean -C minilibx-linux

re: fclean all

.PHONY: all clean fclean re bonus
