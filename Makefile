NAME = minishell
LIBFT = libft/libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -g -lreadline
SRCS = 	main.c tokenizer.c
		
OBJS = $(SRCS:.c=.o)


all: $(NAME)

$(NAME): $(SRCS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(SRCS) $(LIBFT)

$(LIBFT):
	make -C libft

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re: fclean all

.PHONY: all clean fclean re libft 

