# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/28 00:46:12 by ensebast          #+#    #+#              #
#    Updated: 2022/10/24 13:55:54 by ensebast         ###   ########.br        #
#                                                                              #
# **************************************************************************** #

NAME := minirt

INCLUDE := -I ./include/ -I ./libft -I ./minilibx-linux/

CC := gcc
LIB := ./minilibx-linux/libmlx_Linux.a

CFLAGS :=  -Wall -Wextra -Werror -g -lm -lX11 -lXext

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
		get_line.c \
		mlx_prepare.c \
		alloc_mem.c \
		dealloc_mem.c \
		deg_to_rad.c \
		raytrace.c

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
		 ./src/alloc_mem/

all: $(NAME)

$(DIR_OBJ)%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCLUDE) -c $^ -o $@

$(LIBFT):
	make -C libft

$(LIB):
	make -C ./minilibx-linux/

$(NAME): $(OBJ_M) $(LIBFT) $(LIB)
	$(CC) $(CFLAGS) -o $@ $(OBJ_M) $(LIBFT) $(LIB)

clean:
	$(RM) $(DIR_OBJ)
	make clean -C libft

fclean: clean
	$(RM) $(NAME)
	make fclean -C libft
	make clean -C minilibx-linux

re: fclean all

.PHONY: all clean fclean re bonus
