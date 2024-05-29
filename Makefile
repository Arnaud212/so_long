# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agiraud <agiraud@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/14 18:25:03 by agiraud           #+#    #+#              #
#    Updated: 2024/05/29 19:13:33 by agiraud          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

HEADER = so_long.h

LIBFT_DIR = libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra -I./libft -I./include -I./minilibx-linux

SRCS = main.c \
	check_map.c \
	create_map.c \
	create_screen.c \
	load_assets.c \
	utils.c \
	gnl/get_next_line.c \
	gnl/get_next_line_utils.c
	
OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -o $@ -c $<
	
$(NAME): $(OBJS) $(LIBFT_LIB) $(HEADER)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_LIB) -L./minilibx-linux -lmlx -lXext -lX11 -lm -o $(NAME)

$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	$(RM) $(OBJS)
	$(MAKE) clean -C $(LIBFT_DIR)
	@echo "\033[32mObject files Removed\033[0m"

fclean: clean
	$(RM) $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)
	@echo "\033[032mso_long Removed\033[0m"

re: fclean all

.PHONY: all clean fclean re
