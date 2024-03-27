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

LIBFT	= ./libft/libft.a
LIBFT_PATH  = ./libft
INC		= include/
SRC_DIR = src/
OBJ_DIR = obj/
CC = gcc

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

SRCS = $(SRC)

OBJS	= $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o,$(SRCS))

start:
		@make all

$(LIBFT):
	@make -C ./libft

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(INC) $(OBJS) $(LIBFT) -o $(NAME)

$(OBJ_DIR)%.o:	$(SRC_DIR)%.c 
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	@$(RM) -r $(OBJ_DIR)
	@make clean -C ./libft

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(LIBFT)

re: fclean all

.PHONY: all clean start fclean re