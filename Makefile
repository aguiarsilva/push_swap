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
INC		= include/
SRC_DIR = src/
OBJ_DIR = obj/
CC = gcc

RM = rm -f

CFLAGS = -Wall -Werror -Wextra -I

OPERATIONS_DIR	=	$(SRC_DIR)operations/push.c	\
					$(SRC_DIR)operations/rev_rotate.c	\
					$(SRC_DIR)operations/rotate.c	\
					$(SRC_DIR)operations/sort_big.c	\
					$(SRC_DIR)operations/sort_small.c	\
					$(SRC_DIR)operations/swap.c \

PUSH_SWAP_DIR	=	$(SRC_DIR)push_swap/error.c	\
					$(SRC_DIR)push_swap/fnd_a_b.c	\
					$(SRC_DIR)push_swap/fnd_b_a.c \
					$(SRC_DIR)push_swap/init_stacks.c	\
					$(SRC_DIR)push_swap/push_swap.c \
					$(SRC_DIR)push_swap/split.c	\
					$(SRC_DIR)push_swap/utils.c \

SRCS = $(OPERATIONS_DIR) $(PUSH_SWAP_DIR)

OBJ	:= $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))

start:
	@make all

$(LIBFT):
	@make -C ./libft

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) $(INC) $(OBJ) $(LIBFT) -o $(NAME)

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