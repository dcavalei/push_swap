# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcavalei <dcavalei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/31 13:03:52 by dcavalei          #+#    #+#              #
#    Updated: 2021/06/09 16:34:22 by dcavalei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= $(shell find srcs -type f -name "*.c")
BONUS_SRCS	= $(shell find bonus_srcs srcs/operations srcs/utils srcs/algorithms -type f -name "*.c")
LIB			= $(shell find $(LIB_DIRS) -type f -name "*.a")
INCLUDE		= $(addprefix -I, $(INCL_DIRS))
OBJS		= $(SRCS:.c=.o)
BONUS_OBJS	= $(BONUS_SRCS:.c=.o)
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
INCL_DIRS	= includes
LIB_DIRS	= libft
NAME		= push_swap
NAME_BONUS	= checker

all:		libft $(NAME)

libft:
			@$(MAKE) -C libft/

bonus:		libft $(BONUS_OBJS)
			@$(CC) -o $(NAME_BONUS) $(CFLAGS) $(INCLUDE) $(LIB) $(BONUS_OBJS)

.c.o:
			@echo "Creating object: $@"
			@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(NAME):	$(OBJS)
			@$(CC) -o $(NAME) $(CFLAGS) $(INCLUDE) $(LIB) $(OBJS)

clean:
			@rm -f $(OBJS)
			@rm -f $(BONUS_OBJS)
			@$(MAKE) -C libft/ clean

fclean:
			@$(MAKE) -C libft/ fclean
			@rm -f $(OBJS)
			@rm -f $(BONUS_OBJS)
			@rm -f $(NAME)
			@rm -f $(NAME_BONUS)

re:			fclean all

10:			all
	@./push_swap $(shell cat tests/10.txt) | wc -l

16:			all
	@./push_swap $(shell cat tests/16.txt) | wc -l

50:			all
	@./push_swap $(shell cat tests/50.txt) | wc -l

100:		all
	@./push_swap $(shell cat tests/100.txt) | wc -l

500:		all
	@./push_swap $(shell cat tests/500.txt) | wc -l

.PHONY:		all clean fclean re libft
