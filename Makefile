# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: miltavar <miltavar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/12 13:17:19 by miltavar          #+#    #+#              #
#    Updated: 2025/07/03 15:11:05 by miltavar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= pipex
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g -Ilibft/includes -Iincludes
SRCS		= srcs/pipex.c srcs/utils.c srcs/path.c
LIBFT_PATH	= ./libft
LIBFT		= $(LIBFT_PATH)/libft.a
OBJS		= $(SRCS:.c=.o)
BONUS_SRC	= srcs/pipex_bonus.c srcs/path.c srcs/utils.c srcs/utils_bonus.c
BONUS_OBJ	= $(BONUS_SRC:.c=.o)
all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

bonus: $(BONUS_OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(BONUS_OBJ) $(LIBFT) -o $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_PATH)

%.o: %.c includes/pipex.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS) $(BONUS_OBJ)
	@$(MAKE) -C $(LIBFT_PATH) clean

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all clean fclean re
