#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: getrembl <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/03 16:47:42 by getrembl          #+#    #+#              #
#    Updated: 2015/05/26 12:05:00 by getrembl         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME =				libft.a

CPATH =				./srcs/

SRCS =				ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c\
						ft_isdigit.c ft_isprint.c ft_memalloc.c ft_toupper.c\
						ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c\
						ft_memdel.c ft_memmove.c ft_memset.c ft_putchar.c\
						ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c\
						ft_putnbr.c ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c\
						ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c\
						ft_strcpy.c ft_strdel.c ft_strdup.c ft_strequ.c\
						ft_striter.c ft_striteri.c ft_strjoin.c ft_strlen.c\
						ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncmp.c\
						ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strrchr.c\
						ft_strstr.c ft_strsub.c ft_strtrim.c ft_tolower.c\
						ft_itoa.c ft_nbdigit.c ft_strlcat.c ft_strnstr.c\
						ft_strsplit.c ft_nwd.c ft_wdlen.c get_next_line.c\
						ft_tablen.c ft_trim.c ft_mvtab.c ft_strncapitalize.c\
						ft_tabdup.c\

OBJS =				$(SRCS:.c=.o)

AR =				ar

CC =				gcc

RM =				rm

ARFLAGS =			rc

CFLAGS =			-Wall -Wextra -Werror

RMFLAGS =			-rf


all:				$(NAME)

$(NAME):			$(OBJS)
						$(AR) $(ARFLAGS) $(NAME) $(OBJS)
						ranlib $(NAME)

%.o:				$(CPATH)%.c
						$(CC) -o $@ -c $< $(CFLAGS)

clean:
						$(RM) $(RMFLAGS) $(OBJS)
						@echo -en "\n CLEAN \n"

fclean:				clean
						$(RM) $(RMFLAGS) $(NAME)

re:					fclean all