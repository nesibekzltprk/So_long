# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akizilto <akizilto@student.42istanbul.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/29 13:09:43 by akizilto          #+#    #+#              #
#    Updated: 2024/04/29 13:37:20 by akizilto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INCLUDES_MAC = -Imlx

NAME = so_long

CC = gcc

CFLAGS = -Wall -Werror -Wextra -g -fsanitize=address


MLX_FLAGS_MAC = -Lmlx -lmlx -framework OpenGL -framework AppKit 

SRCS = main.c flood_fill.c error.c move.c control.c control1.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c  ft_printf/ft_printf1.c ft_printf/ft_printf.c


OBJ = $(SRCS:.c=.o)

%.o: %.c
	$(CC) $(INCLUDES_MAC) -c $< -o $@

$(NAME): $(OBJ)
	make -C mlx
	make -C ft_printf
	$(CC) $(OBJ) $(MLX_FLAGS_MAC) -o $(NAME) 

all: $(NAME)

fclean: clean
	rm -rf $(NAME)
	make fclean -C ft_printf

clean:
	make clean -C ft_printf
	make clean -C mlx
	rm -rf *.o
	rm -rf get_next_line/*.o

re: fclean all

.PHONY: all clean fclean re