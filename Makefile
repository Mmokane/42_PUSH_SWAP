# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmokane <mmokane@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/24 14:08:53 by mmokane           #+#    #+#              #
#    Updated: 2023/04/18 14:11:01 by mmokane          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

NAME_BONUS = checker

CC = cc
 
CFLAGS = -Wall -Wextra -Werror #-fsanitize=address -g

SRCS = algorithm/algorithms.c algorithm/sort_utils.c algorithm/sort_utils2.c \
	   moves/moves_utils.c moves/push_moves.c moves/rev_rotate_moves.c moves/rotate_moves.c moves/swap_moves.c \
	   utils/ft_linked.c utils/ft_putstr.c utils/input_parse.c \
	   push_swap.c \
	   libft/ft_isdigit.c libft/ft_split.c libft/ft_strjoin.c libft/ft_atoi.c libft/ft_strlen.c \
	   libft/ft_memmove.c libft/ft_memcpy.c libft/ft_strdup.c utils/strjoinv2.c \

SRCS_BONUS = BONUS/moves/moves_utils_bonus.c BONUS/moves/push_moves_bonus.c BONUS/moves/rev_rotate_moves_bonus.c \
			 BONUS/moves/rotate_moves_bonus.c BONUS/moves/swap_moves_bonus.c \
			 BONUS/utils/ft_strcmp.c BONUS/utils/ft_putstr.c \
			 libft/ft_split.c \
	  		 libft/ft_memmove.c libft/ft_memcpy.c libft/ft_strdup.c \
			 BONUS/checker.c  BONUS/utils/stack_a_fill.c BONUS/utils/linked.c \
			 BONUS/utils/array_in.c libft/ft_atoi.c BONUS/GNL/get_next_line.c \
			 BONUS/GNL/get_next_line_utils.c BONUS/utils/digit.c \

OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

.c.o	:
		@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)
	
$(NAME) : $(OBJS)
		@echo "\033[1;32m---- COMPILING! ----\033[0m"
		@cc $(CFLAGS) $(OBJS) -o $(NAME)
		@echo "\033[1;32m   ---- DONE ----\033[0m"

$(NAME_BONUS) : $(OBJS_BONUS)
		@echo "\033[1;32m---- COMPILING! ----\033[0m"
		@cc $(CFLAGS) $(OBJS_BONUS) -o $(NAME_BONUS)
		@echo "\033[1;32m   ---- DONE ----\033[0m"

all : $(NAME)

bonus : $(NAME_BONUS)

clean :
		@rm -rf $(OBJS)
		@rm -rf $(OBJS_BONUS)

fclean : 
		@rm -rf $(NAME) $(OBJS)
		@rm -rf $(NAME_BONUS) $(OBJS_BONUS)

re : clean all