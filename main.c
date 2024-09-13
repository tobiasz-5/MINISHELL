#include <readline/readline.h>
#include <readline/history.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>

#define MAX_TOKENS 100


typedef enum    e_token_type
{
    TOKEN_PIPE = 0,
    TOKEN_REDIR_APPEND = 1,
    TOKEN_HEREDOC = 2,
    TOKEN_REDIR_IN = 3,
    TOKEN_REDIR_OUT = 4,
    TOKEN_SINGLE_QUOTE = 5,
    TOKEN_DOUBLE_QUOTE = 6,
    TOKEN_DOLLAR = 7,
    TOKEN_WORD = 8,
}               t_token_type;

typedef struct  s_token_data
{
    char            *token;
    t_token_type    type;
}               t_token_data;

char **realloc_tokens(char **tokens, int *capacity) 
{
    *capacity *= 2;
    tokens = realloc(tokens, *capacity * sizeof(char *));
    if (!tokens) 
    {
        perror("realloc");
        return NULL;
    }
    return tokens;
}

int add_token(char **tokens, int *num_tokens, char *token) {
    tokens[*num_tokens] = strdup(token);
    if (!tokens[*num_tokens]) {
        perror("strdup");
        return -1;
    }
    (*num_tokens)++;
    return 0;
}


char **first_split(char *input) 
{
    char **tokens;
    int num_tokens = 0, i = 0, start;

    tokens = malloc(MAX_TOKENS * sizeof(char *));
    if (!tokens) return NULL;

    while (input[i] && num_tokens < MAX_TOKENS)
    {
        while (input[i] == ' ') i++; // Salta gli spazi
        start = i;
        while (input[i] && input[i] != ' ') i++; // Trova la fine del token
        if (i > start) {
            tokens[num_tokens++] = strndup(input + start, i - start);
        }
    }
    tokens[num_tokens] = NULL;
    return tokens;
}

int     count_tokens(char **words)
{
    int     i;

    i = 0;
    while (words[i])
        i++;
    return (i);
}

t_token_data    give_token_type(char *token)
{
    t_token_data    token_data;

    token_data.token = strdup(token);
    if(strcmp(token, "|") == 0)
        token_data.type = TOKEN_PIPE;
    else if(strcmp(token, ">>") == 0)
        token_data.type = TOKEN_REDIR_APPEND;
    else if(strcmp(token, "<<") == 0)
        token_data.type = TOKEN_HEREDOC;
    else if(strcmp(token, "<") == 0)
        token_data.type = TOKEN_REDIR_IN;
    else if(strcmp(token, ">") == 0)
        token_data.type = TOKEN_REDIR_OUT;
    else if(strcmp(token, "'") == 0)
        token_data.type = TOKEN_SINGLE_QUOTE;
    else if(strcmp(token, "\"") == 0)
        token_data.type = TOKEN_DOUBLE_QUOTE;
    else if(strcmp(token, "$") == 0)
        token_data.type = TOKEN_DOLLAR;
    else
        token_data.type = TOKEN_WORD;
    return (token_data);
}

t_token_data  *lexer(char *input)
{
    char            **words;
    t_token_data    *tokens;
    int             num_tokens;
    int             i;

    words = first_split(input);
    if (!words)
        return NULL;
    num_tokens = count_tokens(words);
    tokens = malloc(sizeof(t_token_data) * (num_tokens + 1));
    if (!tokens)
        return NULL;
    i = 0;
    num_tokens = 0;
    while(words[i])
    {
        tokens[num_tokens] = give_token_type(words[i]);
        num_tokens++;
        free(words[i]);
        i++;
    }
    free(words);
    tokens[num_tokens].token = NULL;
    return (tokens); 
}

void handle_sigint(int sig)
{
    (void)sig;
    write(STDOUT_FILENO, "\n", 1);
    rl_on_new_line();
    rl_replace_line("", 0);
    rl_redisplay();
}

void handle_sigquit(int sig)
{
    (void)sig;
}

int     main()
{
    char            *input;
    t_token_data    *tokens;
    int             i;

    signal(SIGINT, handle_sigint);
    signal(SIGQUIT, handle_sigquit);
    while (1)
    {
        i = 0;
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
            tokens = lexer(input);
            while (tokens[i].token)
            {
                printf("Rappres_Token: %s\n", tokens[i].token);
                printf("N_Type: %d\n", tokens[i].type);
                free(tokens[i].token);
                i++;
            }
            free(tokens);
            free(input);
        }
    }
    rl_clear_history();
    return(0);
}