# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: itahri <itahri@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/16 16:42:32 by itahri            #+#    #+#              #
#    Updated: 2024/07/04 21:11:31 by itahri           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

SRCS = $(addprefix srcs/, args_management.c args_management2.c args_management3.c main.c sorting_funcs.c stack_func.c stack_func2.c stack_mouvement_reverse_swap.c \
stack_mouvements_rotate.c stack_mouvement_swap.c stack_mouvements_push.c radix_algo.c special_case.c)

INCLUDES = ./includes -I ./libft/includes/

LIBFT = libft.a
LIB_DIR = ./libft
OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror -g3

NAME = push_swap

all : $(LIBFT) $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -I $(INCLUDES) -c  $< -o $@ 

$(LIBFT):
	make -C ./libft

$(NAME):  $(OBJS)
	$(CC) $(CFLAGS) -I $(INCLUDES)  $(OBJS) -o $(NAME) -L$(LIB_DIR) -lft 

clean:
	rm -f $(OBJS)
	make clean -C ./libft

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
