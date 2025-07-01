# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: miltavar <miltavar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/24 16:57:49 by miltavar          #+#    #+#              #
#    Updated: 2025/06/19 16:02:43 by miltavar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a
CC		= cc -g
CFLAGS	= -Wall -Wextra -Werror

SRCS	= ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c \
		ft_toupper.c ft_tolower.c ft_printf.c \
		ft_strchr.c ft_strrchr.c ft_strncmp.c ft_strnstr.c ft_atoi.c \
		ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
		ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
		ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c \
		ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c get_next_line.c \
		get_next_line_utils.c ft_printf_types_utils.c ft_printf_types.c ft_calloc.c \
		ft_printf_utils.c ft_memset.c

HEADERS	= libft.h
OBJS	= ${SRCS:.c=.o}

all: ${NAME}

$(NAME): $(OBJS)
	@ar rcs $(NAME) $^

%.o: %.c ${HEADERS}
	${CC} ${CFLAGS} -c $< -o $@

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re:	fclean all
