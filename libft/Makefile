# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fhenry <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/23 14:51:08 by fhenry            #+#    #+#              #
#    Updated: 2016/02/02 17:06:01 by fhenry           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME = libft.a
INCLUDE_PATH = ../Include/
OBJ_PATH = ../Objet/
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = ft_putchar.c ft_putnbr.c ft_putstr.c ft_strlen.c \
	  ft_strcpy.c ft_strncpy.c ft_strdup.c ft_strcat.c \
	  ft_strncat.c ft_strlcat.c ft_strchr.c ft_strrchr.c \
	  ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c \
	  ft_atoi.c ft_isdigit.c ft_isalpha.c ft_isalnum.c \
	  ft_isascii.c ft_isprint.c ft_tolower.c ft_toupper.c \
	  ft_memset.c ft_bzero.c ft_memcpy.c ft_memchr.c \
	  ft_memccpy.c ft_memmove.c ft_memcmp.c ft_memalloc.c \
	  ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c \
	  ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c \
	  ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c \
	  ft_strtrim.c ft_strsplit.c ft_itoa.c ft_putendl.c \
	  ft_putchar_fd.c ft_putstr_fd.c ft_putnbr_fd.c \
	  ft_putendl_fd.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c \
	  ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_str_printable.c \
	  ft_strnncpy.c ft_putnbr_base.c ft_is_upper.c ft_is_lower.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) -c $(SRC) $(CFLAGS)
	@ar -r $(NAME) $(OBJ)
	@ranlib $(NAME)
	@mv $(NAME) $(INCLUDE_PATH)
	@mv $(OBJ) $(OBJ_PATH)
	@echo libft loaded

clean:
	@rm -f $(OBJ_PATH)$(OBJ)

fclean: clean
	@rm -f $(INCLUDE_PATH)$(NAME)

re: fclean all
