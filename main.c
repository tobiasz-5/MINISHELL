#include <readline/readline.h>
#include <readline/history.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

typedef struct  s_token_data
{
    char            *token;
    t_token_type    type;
}               t_token_data;

typedef enum    e_token_type
{
    TOKEN_WORD,
    TOKEN_PIPE,
    TOKEN_REDIR_IN,
    TOKEN_REDIR_OUT,
    TOKEN_REDIR_APPEND,
    TOKEN_HEREDOC,
    TOKEN_SINGLE_QUOTE,
    TOKEN_DOUBLE_QUOTE,
    TOKEN_DOLLAR,
}               t_token_type;

char    **split_input(char *input)
{
    char    **tokens = malloc(sizeof(char *) *  100)
}

int     count_tokens(char **words)
{
    int     i;

    i = 0;
    while (words[i])
        i++;
    return (i);
}

t_token_data  *lexer(char *input)
{
    char            **words;
    t_token_data    *tokens;
    int             num_tokens;
    int             i;

    words = first_split(input);
    tokens = malloc(sizeof(t_token_data) * (count_tokens(words) + 1));
    

    
}

void handle_sigint(int sig)
{
    write(STDOUT_FILENO, "\n", 1);
    rl_on_new_line();
    rl_replace_line("", 0);
    rl_redisplay();
}

void handle_sigquit(int sig)
{
    //ignora il segnale
}

int     main()
{
    char    *input;

    signal(SIGINT, handle_sigint);
    signal(SIGQUIT, handle_sigquit);
    while (1)
    {
        input = readline("MINIPROMPT> ");
        if (!input)
        {
            printf("\nExit From The Shell\n");
            break;
        }
        if (*input == '\0')
            free(input);
        else
        {
            add_history(input);
            lexer(input);
            free(input);
        }
    }
    rl_clear_history();
    return(0);
}
