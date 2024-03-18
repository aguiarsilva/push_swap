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

SRC	=	./src/push_swap.c	\
		

OBJS	= $(SRC:.c=.o)

LIBFT	= ./libft/libft.a
LIBFT_PATH	= ./libft
PRINTF = ./libft/ft_printf/libftprintf.a
PRINTF_PATH	= ./libft/ft_printf

CC = cc

RM = rm -f

CFLAGS = -Wall -Werror -Wextra
DEBUGFLAG = -fsanitize=address

all: $(NAME)

$(LIBFT):
	@make bonus -C $(LIBFT_PATH)

$(PRINTF):
	@make -C $(PRINTF_PATH)

$(NAME): $(LIBFT) $(PRINTF) $(SRC)
	$(CC) $(CFLAGS) $(SRC) $(LIBFT) $(PRINTF) -o $(NAME)

clean:
	@make clean -C $(LIBFT_PATH)
	@make clean -C $(PRINTF_PATH)
	@$(RM) *.o

fclean: clean
	@make fclean -C $(LIBFT_PATH)
	@make fclean -C $(PRINTF_PATH)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean  fclean re