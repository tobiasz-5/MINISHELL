NAME = minishell
CC = cc
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
CFLAGS = -Wall -Wextra -Werror -g -I$(LIBFT_DIR)
LDFLAGS = -L$(LIBFT_DIR) -lreadline -lft
SRCS = 	built-in.c echo.c echo_utils.c env.c mini.c\
		main.c lexer_token.c signals.c utils.c utils_2.c token_type.c tokenizer_utils.c token_analyze_utils.c \
		process_token.c lexer_utils.c free_tokens.c pwd.c built_in_utils.c
OBJS = $(SRCS:.c=.o)

all: $(NAME) $(LIBFT) mini_art

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LDFLAGS)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re

mini_art:
	@echo "\033[38;5;27m▗▖  \033[38;5;33m▗▖▗▄▄▄▖\033[38;5;39m▗▖  ▗▖\033[38;5;45m▗▄▄▄▖ \033[38;5;51m▗▄▄▖\033[38;5;75m▗▖ ▗▖\033[38;5;87m▗▄▄▄▖\033[38;5;51m▗▖   ▗▖ \t 🐚 🦪  🐠 \033[0m"
	@echo "\033[38;5;27m▐▛▚\033[38;5;33m▞▜▌  █  \033[38;5;39m▐▛▚▖▐▌  █  \033[38;5;45m▐▌   \033[38;5;51m▐▌ ▐▌\033[38;5;75m▐▌   \033[38;5;87m▐▌   \033[38;5;51m▐▌ \t  🐚 🐟 🦪\033[0m"
	@echo "\033[38;5;27m▐▌  \033[38;5;33m▐▌  █  \033[38;5;39m▐▌ ▝▜▌  █   \033[38;5;45m▝▀▚▖▐▛▀▜▌\033[38;5;51m▐▛▀▀▘\033[38;5;75m▐▌   \033[38;5;87m▐▌ \t🦪🦪  🐠 🐚   \033[0m"
	@echo "\033[38;5;27m▐▌  \033[38;5;33m▐▌▗▄█▄▖\033[38;5;39m▐▌  ▐▌▗▄█▄▖\033[38;5;45m▗▄▄▞▘\033[38;5;51m▐▌ ▐▌\033[38;5;75m▐▙▄▄▖\033[38;5;87m▐▙▄▄▖▐▙▄▄▖ \033[1;38;5;39mCompiled Underwater at High Pressure\033[0m⠀"

.SILENT: