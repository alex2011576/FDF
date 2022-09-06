# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile2                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ashatalo <ashatalo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/06 19:12:31 by ashatalo          #+#    #+#              #
#    Updated: 2022/04/06 19:57:56 by ashatalo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRCS = ft_abs.c\
	ft_isspace.c\
	ft_lstnew.c\
	ft_memprint.c\
	ft_putnbr_fd.c\
	ft_strdel.c\
	ft_strmapi.c\
	ft_strstr.c\
	ft_atoi.c\
	ft_itoa.c\
	ft_max.c\
	ft_memset.c\
	ft_putstr.c\
	ft_strdup.c\
	ft_strncat.c\
	ft_strsub.c\
	ft_atoi_hex.c\
	ft_lst_contentfree.c\
	ft_memalloc.c\
	ft_min.c\
	ft_putstr_fd.c\
	ft_strequ.c\
	ft_strncmp.c\
	ft_strtrim.c\
	ft_bzero.c\
	ft_lstadd.c\
	ft_memccpy.c\
	ft_printlst.c\
	ft_sqrt.c\
	ft_striter.c\
	ft_strncpy.c\
	ft_tolistsplit.c\
	ft_isalnum.c\
	ft_lstadd_back.c\
	ft_memchr.c\
	ft_putchar.c\
	ft_strcat.c\
	ft_striteri.c\
	ft_strnequ.c\
	ft_tolower.c\
	ft_isalpha.c\
	ft_lstdel.c\
	ft_memcmp.c\
	ft_putchar_fd.c\
	ft_strchr.c\
	ft_strjoin.c\
	ft_strnew.c\
	ft_toupper.c\
	ft_isascii.c\
	ft_lstdelone.c\
	ft_memcpy.c\
	ft_putendl.c\
	ft_strclr.c\
	ft_strlcat.c\
	ft_strnstr.c\
	get_next_line.c\
	ft_isdigit.c\
	ft_lstiter.c\
	ft_memdel.c\
	ft_putendl_fd.c\
	ft_strcmp.c\
	ft_strlen.c\
	ft_strrchr.c\
	ft_isprint.c\
	ft_lstmap.c\
	ft_memmove.c\
	ft_putnbr.c\
	ft_strcpy.c\
	ft_strmap.c\
	ft_strsplit.c\

OBJS = $(patsubst %.c, %.o, $(SRCS))
CC = gcc
FLAGS = -Wall -Wextra -Werror -c -I $(INCLUDES)
INCLUDES = includes/

$(NAME): 
	@echo "Compiling libft..."
	@$(CC) $(FLAGS) $(SRCS)
	@ar rcs $(NAME) $(OBJS)

all: $(NAME)
	
clean:
	@echo "Cleaning libft object files..."
	@rm -f $(OBJS)

fclean: clean
	@echo "Cleaning libft binary..."
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
