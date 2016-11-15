# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fhenry <fhenry@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/22 15:53:05 by fhenry            #+#    #+#              #
#    Updated: 2016/03/15 12:41:07 by fhenry           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

CC = gcc
CFLAGS = -Werror -Wall -Wextra -g

SRC_PATH = Src/
OBJ_PATH = Objet/
LIB_PATH = libft/
INCLUDE_PATH = Include/

SRC_NAME = main.c \
		   read_buf.c \
		   load_struct.c \
		   smaller_size.c \
		   compare.c \
		   save_data.c \
		   ref_abs.c \
		   error.c \
		   find_data.c \
		   init_env.c \
		   gen_table.c \
		   backtracking.c \
		   back_in_track.c \
		   check_position.c \
		   resize.c \

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))

all: $(NAME)

$(NAME): $(OBJ)
	    @$(CC) -c $(SRC) $(CFLAGS) -I $(INCLUDE_PATH) && $(MAKE) -C $(LIB_PATH)
		@mkdir $(OBJ_PATH) 2> /dev/null || true
		@mv $(OBJ_NAME) $(OBJ_PATH)
		@$(CC) -o $(NAME) $(OBJ) $(INCLUDE_PATH)libft.a
		@echo fillit exec done

$(OBJ): $(INCLUDE_PATH)fillit.h

clean:
		@rm -rf $(OBJ_PATH) && $(MAKE) -C $(LIB_PATH) $@
		@rmdir $(OBJ_PATH) 2> /dev/null || true
		@echo clean done

fclean: clean
	    @rm -f $(NAME) && $(MAKE) -C $(LIB_PATH) $@
		@echo fclean done

re: fclean all

.PHONY: all, clean, fclean, re


