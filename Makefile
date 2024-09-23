NAME = minishell
CC = cc
CFLAGS = -Wall -Wextra -Werror -g 
LDFLAGS = -lreadline
SRCS = 	main.c lexer_token.c signals.c built-in.c echo.c echo_utils.c utils.c token_type.c tokenizer_utils.c token_analyze_utils.c process_token.c lexer_utils.c free_tokens.c
OBJS = $(SRCS:.c=.o)

all: $(NAME) mini_art

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

mini_art:
	@echo "\033[38;5;27m▗▖  \033[38;5;33m▗▖▗▄▄▄▖\033[38;5;39m▗▖  ▗▖\033[38;5;45m▗▄▄▄▖ \033[38;5;51m▗▄▄▖\033[38;5;75m▗▖ ▗▖\033[38;5;87m▗▄▄▄▖\033[38;5;51m▗▖   ▗▖ \t 🐚 🦪  🐠 \033[0m"
	@echo "\033[38;5;27m▐▛▚\033[38;5;33m▞▜▌  █  \033[38;5;39m▐▛▚▖▐▌  █  \033[38;5;45m▐▌   \033[38;5;51m▐▌ ▐▌\033[38;5;75m▐▌   \033[38;5;87m▐▌   \033[38;5;51m▐▌ \t  🐚 🐟 🦪\033[0m"
	@echo "\033[38;5;27m▐▌  \033[38;5;33m▐▌  █  \033[38;5;39m▐▌ ▝▜▌  █   \033[38;5;45m▝▀▚▖▐▛▀▜▌\033[38;5;51m▐▛▀▀▘\033[38;5;75m▐▌   \033[38;5;87m▐▌ \t🦪🦪  🐠 🐚   \033[0m"
	@echo "\033[38;5;27m▐▌  \033[38;5;33m▐▌▗▄█▄▖\033[38;5;39m▐▌  ▐▌▗▄█▄▖\033[38;5;45m▗▄▄▞▘\033[38;5;51m▐▌ ▐▌\033[38;5;75m▐▙▄▄▖\033[38;5;87m▐▙▄▄▖▐▙▄▄▖ \033[1;38;5;39m 🐟 🦪 🐚 \t Compiled Underwater at High Pressure\033[0m⠀"

