#ifndef MINIHEADER_H
# define MINIHEADER_H

# define COLOR_RED "\033[31m"      // Colore rosso
# define MAGENTA "\033[1;34m"   
# define COLOR_ORANGE "\033[1;38;5;208m"  // Colore arancione
# define COLOR_RESET "\033[0m"     // Reset del colore

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <string.h>
# include <unistd.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>

typedef enum e_token_type
{
    TOKEN_PIPE,
    TOKEN_REDIR_APPEND,
    TOKEN_HEREDOC,
    TOKEN_REDIR_IN,
    TOKEN_REDIR_OUT,
    TOKEN_SINGLE_QUOTE,
    TOKEN_DOUBLE_QUOTE,
    TOKEN_DOLLAR,
    TOKEN_WORD,
    TOKEN_UNKNOWN,
}   t_token_type;

typedef struct s_token_node
{
    char                *token;
    t_token_type        type;
    bool                single_quote;
    bool                double_quote;
    struct s_token_node *next;
}   t_token_node;

typedef struct s_token_state 
{
    char *token_str;
    bool single_quote;
    bool double_quote;
} t_token_state;


void            handle_sigint(int sig);
void            handle_sigquit(int sig);
int             ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int             ft_strlen(const char *s);
int             handle_builtins(char *input, char *cmd);
void			ft_echo(char *input);
void			init_sign(void);
int				closed_quote(char *str, int i);
int				check_forn(char *input, int i);
int				skip_white(char c, int *in_word, char *cpy, int *j);
const char      *token_type_to_string(t_token_type type);
t_token_node    *lexer(char *input);
void            process_input(char *input);
void            free_tokens(t_token_node *tokens);
t_token_type    determine_token_type(char *token_str);
t_token_node    *create_token_node(char *token_str);
t_token_node    *extract_token_str(char *input, int start, int end);
void            add_token_node(t_token_node **head, t_token_node **tail, t_token_node *new_node);
void            *ft_memcpy(void *dest, const void *src, size_t n);
char            *ft_strjoin(const char *s1, const char *s2);
int             skip_spaces(char *input, int i);
int             find_closing_quote(char *input, int i, char quote);
void            handle_unclosed_quote_error(t_token_state *state);
void            set_quote_flag(t_token_state *state, char quote);
int             handle_token_error(t_token_state *state);
void            init_lexer_vars(t_token_node **head, t_token_node **tail, t_token_state *state, int *i, int *result);
int             process_next_token(char *input, int i, t_token_state *state, t_token_node **head, t_token_node **tail);
int             append_to_temp_token_str(t_token_state *state, char *temp_token);

#endif