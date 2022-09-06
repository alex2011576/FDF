# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ashatalo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/05 18:35:34 by ashatalo          #+#    #+#              #
#    Updated: 2022/04/06 20:05:53 by ashatalo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CC = gcc
FLAGS = -Wall -Wextra -Werror -o $(NAME) $(INCLUDES) 
LIBFT = -L libft -lft
MLX = -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit
INCLUDES = -I$(LIBFT_HEADERS) -I$(HEADERS_DIRECTORY)
LIBFT_HEADERS = libft/includes
HEADERS_DIRECTORY = includes/
SOURCES_DIRECTORY = ./srcs/
SOURCES_LIST = 	main.c read_map.c my_mlx_pixel_put.c draw_to_image.c\
				set_params.c iso.c deal_key.c change_window_size.c\
				line.c color.c utils.c print_menu.c
SRCS = $(addprefix $(SOURCES_DIRECTORY), $(SOURCES_LIST))

$(NAME):
	@echo "Compiling FDF..."
	@make -C libft --no-print-directory
	@$(CC) $(SRCS) $(FLAGS) $(LIBFT) $(MLX)

all: $(NAME)
	
clean:
	@echo "Cleaning object FDF files..."
	@make -C libft clean --no-print-directory

fclean: clean
	@echo "Cleaning binary FDF..."
	@make -C libft fclean --no-print-directory
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
