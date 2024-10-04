NAME = minishell
CC = cc
CFLAGS = -Wall -Wextra -Werror -g 
LDFLAGS = -lreadline
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
SRCS = 	main.c lexer_token.c signals.c built-in.c echo.c echo_utils.c \
		utils.c token_type.c tokenizer_utils.c token_analyze_utils.c \
		process_token.c lexer_utils.c free_tokens.c pwd.c
OBJS = $(SRCS:.c=.o)

all: $(LIBFT) $(NAME) mini_art

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LDFLAGS)

$(LIBFT):
	make bonus -C $(LIBFT_DIR)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	make clean -C $(LIBFT_DIR)
fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)
re: fclean all

.PHONY: all clean fclean re

mini_art:
	@echo "\033[38;5;27m▗▖  \033[38;5;33m▗▖▗▄▄▄▖\033[38;5;39m▗▖  ▗▖\033[38;5;45m▗▄▄▄▖ \033[38;5;51m▗▄▄▖\033[38;5;75m▗▖ ▗▖\033[38;5;87m▗▄▄▄▖\033[38;5;51m▗▖   ▗▖ \t 🐚 🦪  🐠 \033[0m"
	@echo "\033[38;5;27m▐▛▚\033[38;5;33m▞▜▌  █  \033[38;5;39m▐▛▚▖▐▌  █  \033[38;5;45m▐▌   \033[38;5;51m▐▌ ▐▌\033[38;5;75m▐▌   \033[38;5;87m▐▌   \033[38;5;51m▐▌ \t  🐚 🐟 🦪\033[0m"
	@echo "\033[38;5;27m▐▌  \033[38;5;33m▐▌  █  \033[38;5;39m▐▌ ▝▜▌  █   \033[38;5;45m▝▀▚▖▐▛▀▜▌\033[38;5;51m▐▛▀▀▘\033[38;5;75m▐▌   \033[38;5;87m▐▌ \t🦪🦪  🐠 🐚   \033[0m"
	@echo "\033[38;5;27m▐▌  \033[38;5;33m▐▌▗▄█▄▖\033[38;5;39m▐▌  ▐▌▗▄█▄▖\033[38;5;45m▗▄▄▞▘\033[38;5;51m▐▌ ▐▌\033[38;5;75m▐▙▄▄▖\033[38;5;87m▐▙▄▄▖▐▙▄▄▖ \033[1;38;5;39mCompiled Underwater at High Pressure\033[0m⠀"

