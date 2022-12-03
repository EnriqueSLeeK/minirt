# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/28 00:46:12 by ensebast          #+#    #+#              #
#    Updated: 2022/12/02 20:54:10 by ensebast         ###   ########.br        #
#                                                                              #
# **************************************************************************** #

NAME := miniRT

INCLUDE := -I ./include/ -I ./libft -I ./minilibx-linux/

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

FILE_OBJ := $(FILES_M:c=o)

DIR_OBJ := ./obj/

OBJ_M := $(addprefix $(DIR_OBJ), $(FILE_OBJ))

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
		 ./src/prepare/

#$(CC) $(INCLUDE) $(CHECKFLAG) -c $^ -o $@
all: $(NAME)

$(DIR_OBJ)%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(INCLUDE) -o3 -c $^ -o $@

$(LIBFT):
	make -C libft

$(LIB):
	make -C ./minilibx-linux/

$(NAME): $(OBJ_M) $(LIBFT) $(LIB)
	$(CC) -g $(CHECKFLAG) $(CFLAGS) -o $@ $(OBJ_M) $(LIBFT) $(LIB)

clean:
	$(RM) $(DIR_OBJ)
	make clean -C libft

fclean: clean
	$(RM) $(NAME)
	make fclean -C libft
	make clean -C minilibx-linux

re: fclean all

.PHONY: all clean fclean re bonus
