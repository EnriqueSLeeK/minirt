# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/28 00:46:12 by ensebast          #+#    #+#              #
#    Updated: 2022/11/20 21:49:17 by ensebast         ###   ########.br        #
#                                                                              #
# **************************************************************************** #

NAME := minirt

INCLUDE := -I ./include/ -I ./libft -I ./minilibx-linux/

CC := clang
LIB := ./minilibx-linux/libmlx_Linux.a

CFLAGS := -g -lm -lX11 -lXext
CHECKFLAG := -Wall -Wextra -Werror

LIBFT := ./libft/libft.a

RM := rm -rf

# Source files
FILES_M := main.c \
		check_line.c \
		checker_ambient.c \
		checker_format.c \
		extension_check.c \
		micro_regex.c \
		segment_checker.c \
		util_check.c \
		parse_ambient.c \
		parse_format.c \
		parse_line.c \
		segment_parse.c \
		str_to_double.c \
		str_to_int.c \
		val_range_check.c \
		vec_init.c \
		mlx_draw.c \
		mlx_key.c \
		mlx_prepare.c \
		mlx_start.c \
		get_line.c \
		make_color.c \
		cmp_float.c \
		m_create.c \
		m_det.c \
		m_op.c \
		m_transform.c \
		tup_op.c \
		tup_s_op.c \
		ray_op.c \
		alloc_mem.c \
		dealloc_mem.c \
		deg_to_rad.c \
		intersect.c \
		raytrace.c \
		sphere.c

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
		 ./src/ray/

all: $(NAME)

$(DIR_OBJ)%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(INCLUDE) $(CHECKFLAG) -c $^ -o $@

$(LIBFT):
	make -C libft

$(LIB):
	make -C ./minilibx-linux/

$(NAME): $(OBJ_M) $(LIBFT) $(LIB)
	$(CC) $(CHECKFLAG) $(CFLAGS) -o $@ $(OBJ_M) $(LIBFT) $(LIB)

clean:
	$(RM) $(DIR_OBJ)
	make clean -C libft

fclean: clean
	$(RM) $(NAME)
	make fclean -C libft
	make clean -C minilibx-linux

re: fclean all

.PHONY: all clean fclean re bonus
