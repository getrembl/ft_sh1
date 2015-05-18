#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: getrembl <getrembl@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/09 14:29:46 by getrembl          #+#    #+#              #
#    Updated: 2015/05/18 14:27:02 by getrembl         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME		= ft_minishell1
SRC			= minishell_1.c \
				prompt.c \
				execute.c \
				ft_builtin.c \
				cd_builtin.c \
				ft_pwd.c

OBJ			= $(SRC:.c=.o)
CC			= /usr/bin/gcc
CFLAGS		= -Wall -Wextra -Werror
CDEBUG		= -Wall -Wextra -Werror -ansi -pedantic -g
RM			= /bin/rm -f
ECHO		= /bin/echo -e

$(NAME)	:		$(OBJ)
				@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) libft.a
				@$(ECHO) '> Compiled'

clean	:
				-@$(RM) $(OBJ)
				-@$(RM) *~
				@$(ECHO) '> Directory cleaned'

all		:		$(NAME)

fclean	:		clean
				-@$(RM) $(NAME)
				@$(ECHO) '> Remove executable'

re		:		fclean all

.PHONY	:		all clean re

debug	:		$(OBJ)
				@$(CC) $(INC) $(CDEBUG) -o $(NAME) $(OBJ)
				@$(ECHO) '> Mode Debug: done'

.c.o	:
				$(CC) $(CFLAGS) -o $@ -c $<
