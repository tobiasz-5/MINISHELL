NAME = minishell
LIBFT = libft/libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -g -lreadline
SRCS = 	main.c tokenizer.c signals.c built-in.c
		
OBJS = $(SRCS:.c=.o)


all: $(NAME) mini_art

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

mini_art:
	@echo "▗▖  ▗▖▗▄▄▄▖▗▖  ▗▖▗▄▄▄▖ ▗▄▄▖▗▖ ▗▖▗▄▄▄▖▗▖   ▗▖   "
	@echo "▐▛▚▞▜▌  █  ▐▛▚▖▐▌  █  ▐▌   ▐▌ ▐▌▐▌   ▐▌   ▐▌   "
	@echo "▐▌  ▐▌  █  ▐▌ ▝▜▌  █   ▝▀▚▖▐▛▀▜▌▐▛▀▀▘▐▌   ▐▌   "
	@echo "▐▌  ▐▌▗▄█▄▖▐▌  ▐▌▗▄█▄▖▗▄▄▞▘▐▌ ▐▌▐▙▄▄▖▐▙▄▄▖▐▙▄▄▖ \033[1mCOMPLILED!\033[0m⠀"

                                               
                                               
                                               



