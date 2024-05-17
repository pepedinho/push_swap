# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: itahri <itahri@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/16 16:42:32 by itahri            #+#    #+#              #
#    Updated: 2024/05/17 15:27:24 by itahri           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

SRCS = $(addprefix srcs/, args_management.c main.c sorting_funcs.c stack_func.c stack_func2.c stack_mouvement_reverse_swap.c \
stack_mouvements_rotate.c stack_mouvement_swap.c stack_mouvements_push.c sorting_funcs2.c)

INCLUDES = ./includes -I ./libft/includes/

LIBFT = libft.a
LIB_DIR = ./libft
OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

NAME = push_swap

%.o : %.c
	$(CC) $(CFLAGS) -I $(INCLUDES) -c  $< -o $@ 

$(LIBFT):
	make -C ./libft

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) -I $(INCLUDES)  $(OBJS) -o $(NAME) -L$(LIB_DIR) -lft

all : $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re