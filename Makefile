# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: baguiar- <baguiar-@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/17 22:21:15 by baguiar-          #+#    #+#              #
#    Updated: 2024/03/17 22:21:15 by baguiar-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap

LIBFT	= libft.a
LIBFT_PATH  = ./libft
INC		= include/
SRC_DIR = src/
OBJ_DIR = obj/
LIBNAME = libpush_swap.a
CC = cc

RM = rm -f

CFLAGS = -Wall -Werror -Wextra -I
DEBUGFLAG = -fsanitize=address

SRC	=	$(SRC_DIR)push_swap.c	\
		$(SRC_DIR)error.c	\
		$(SRC_DIR)init_stacks.c	\
		$(SRC_DIR)push.c	\
		$(SRC_DIR)rev_rotate.c	\
		$(SRC_DIR)rotate.c	\
		$(SRC_DIR)sort_big.c	\
		$(SRC_DIR)sort_small.c	\
		$(SRC_DIR)stack_utils.c	\
		$(SRC_DIR)swap.c	\
		$(SRC_DIR)utils.c	\

OBJS	= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT_PATH)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_PATH) -lft -o $(NAME)

clean:
	$(RM) $(OBJ)
	@make -C $(LIBFT_PATH) clean

fclean: clean
	$(RM) $(NAME) $(LIBNAME)
	@make -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all clean  fclean re