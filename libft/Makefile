# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcavalei <dcavalei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/17 14:49:14 by dcavalei          #+#    #+#              #
#    Updated: 2021/04/20 13:10:50 by dcavalei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC			= ${wildcard  *.c}
OBJS		= ${SRC:.c=.o}
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
NAME		= libft.a
LIB			= ar -rcs

RED			= \033[0;31m
GREEN		= \033[0;32m
ORANGE		= \033[0;33m
BLUE		= \033[1;34m
YELLOW		= \033[1;33m
NC			= \033[0m

all:		${NAME}

%.o: %.c
			@echo "Creating object file: $@"
			@${CC} ${CFLAGS} -c $< -o $@ -Iincludes

${NAME}:	${OBJS}
			@echo "${YELLOW}Compiling:${NC} ${NAME}"
			@${LIB} ${NAME} ${OBJS}
			
bonus:		${NAME}

test:		$(TEST)

clean:
			@echo "${YELLOW}Removing:${NC} ${OBJS}"
			@rm -f ${OBJS}

fclean:		clean
			@echo "${YELLOW}Removing:${NC} ${NAME}"
			@rm -f ${NAME}

re:			fclean all

rebonus:	fclean bonus

.PHONY:		all clean fclean re bonus rebonus