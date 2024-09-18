#ifndef MINIHEADER_H
# define MINIHEADER_H

# include <stdio.h>
# include <stdlib.h>
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
    struct s_token_node *next;
}   t_token_node;

void            handle_sigint(int sig);
void            handle_sigquit(int sig);
int             ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int             handle_builtins(char *input, char *cmd);
void			ft_echo(char *input, int n);
const char      *token_type_to_string(t_token_type type);
t_token_node    *lexer(char *input);
void            process_input(char *input);
void            free_tokens(t_token_node *tokens);
t_token_type    determine_token_type(char *token_str);
t_token_node    *create_token_node(char *token_str);
t_token_node    *extract_token_str(char *input, int start, int end);
void            add_token_node(t_token_node **head, t_token_node **tail, t_token_node *new_node);

#endif