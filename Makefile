# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmokane <mmokane@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/24 14:08:53 by mmokane           #+#    #+#              #
#    Updated: 2023/04/17 21:33:47 by mmokane          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

NAME_BONUS = checker

CC = cc
 
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g

SRCS = algorithm/algorithms.c algorithm/sort_utils.c algorithm/sort_utils2.c \
	   moves/moves_utils.c moves/push_moves.c moves/rev_rotate_moves.c moves/rotate_moves.c moves/swap_moves.c \
	   utils/free_str.c utils/ft_error.c utils/ft_linked.c utils/ft_putstr.c utils/input_parse.c \
	   push_swap.c \
	   libft/ft_isdigit.c libft/ft_split.c libft/ft_strjoin.c libft/ft_atoi.c libft/ft_strlen.c \
	   libft/ft_memmove.c libft/ft_memcpy.c \
	   
OBJS = $(SRCS:.c=.o)

.c.o	:
		@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)
	
$(NAME) : $(OBJS)
		@echo "\033[1;32m---- COMPILING! ----\033[0m"
		@cc $(CFLAGS) $(OBJS) -o $(NAME)
		@echo "\033[1;32m   ---- DONE ----\033[0m"


all : $(NAME)

clean :
		@rm -rf $(OBJS)

fclean : 
		@rm -rf $(NAME) $(OBJS)

re : clean all