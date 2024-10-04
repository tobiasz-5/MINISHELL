# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acapobia <acapobia@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/23 06:57:49 by acapobia          #+#    #+#              #
#    Updated: 2024/05/20 19:48:18 by acapobia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
ft_isdigit.c ft_isprint.c ft_itoa.c ft_memcpy.c ft_memchr.c ft_memcmp.c \
ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c \
ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_strjoin.c \
ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c \
ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c ft_striteri.c \
get_next_line.c ft_printf.c put_character.c putnum.c ft_free_matrix.c ft_strtol.c ft_abs.c

OBJ = $(SRC:.c=.o)

BONUS = ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c \
ft_lstdelone.c ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c \

BONUS_OBJ = $(BONUS:.c=.o)

NAME = libft.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)


bonus: $(OBJ) $(BONUS_OBJ)
	ar rcs $(NAME) $(OBJ) $(BONUS_OBJ)

clean:
	$(RM) $(OBJ) $(BONUS_OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus

