# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hwakatsu <hwakatsu@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/24 19:20:27 by hwakatsu          #+#    #+#              #
#    Updated: 2026/01/21 19:24:18 by hwakatsu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
B_NAME = checker

CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

INCDIR = includes

DIR = src

SRCS =		main_util.c \
			main_util2.c \
			main.c \
			push_swap_util.c \
			push_swap.c \
			stack_control_a.c \
			stack_control_b.c \
			stack_control.c \
			turk_sort_util.c \
			turk_sort.c \

B_SRCS =	checker_bonus.c \
			main_util.c \
			main_util2.c \
			main_bonus.c \
			stack_control_a.c \
			stack_control_b.c \
			stack_control.c \

SRCS := $(addprefix $(DIR)/, $(SRCS))
OBJS = $(SRCS:.c=.o)

B_SRCS := $(addprefix $(DIR)/, $(B_SRCS))
B_OBJS = $(B_SRCS:.c=.o)

all: $(NAME)
bonus: $(B_NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(B_NAME): $(B_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(B_OBJS) $(LIBFT) -o $(B_NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I $(INCDIR) -c $< -o $@

clean:
	rm -f $(OBJS) $(B_OBJS)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME) $(B_NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all bonus clean fclean re
