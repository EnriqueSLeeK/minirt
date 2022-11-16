# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/06 14:24:40 by ensebast          #+#    #+#              #
#    Updated: 2022/09/12 17:54:23 by ensebast         ###   ########.br        #
#                                                                              #
# **************************************************************************** #

CC:=clang

CFLAGS:=-c -Wall -Werror -Wextra

NAME:=libft.a

BASE:=ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
	  ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c \
	  ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c \
	  ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c \
	  ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c \

BONUS:=ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c \
	   ft_lstdelone.c ft_lstiter.c ft_lstlast.c \
	   ft_lstmap.c ft_lstnew.c ft_lstsize.c

RM:=rm -f

BASE-OBJ:=$(BASE:.c=.o)

BONUS-OBJ=$(BONUS:.c=.o)

$(NAME): libft.h $(BASE)
	$(CC) $(CFLAGS) $(BASE)
	ar r $(NAME) $(BASE-OBJ)

all:$(BASE) $(BONUS)
	$(CC) $(CFLAGS) -c $(BONUS) $(BASE)
	ar r $(NAME) $(BASE-OBJ) $(BONUS-OBJ)

bonus:
	$(CC) $(CFLAGS) -c $(BONUS) $(BASE)
	ar r $(NAME) $(BONUS-OBJ) $(BASE-OBJ)

clean:
	$(RM) $(BASE-OBJ) $(BONUS-OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
