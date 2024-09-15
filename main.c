/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mailinci <mailinci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 15:49:48 by mailinci          #+#    #+#             */
/*   Updated: 2024/09/15 15:59:16 by mailinci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniheader.h"


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

// gestisce il segnale SIGINT (Ctrl+C)
void handle_sigint(int sig)
{
    (void)sig;
    write(STDOUT_FILENO, "\n", 1);
    rl_on_new_line();
    rl_replace_line("", 0);
    rl_redisplay();
}

// gestisce il segnale SIGQUIT (Ctrl+\)
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
        input = readline("MINIPROMPT$ ");
        if (!input)
        {
            printf("\nFarewell my friend\n");
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
                printf("Token: %s \t Type: %s\n", tokens[i].token, token_type_to_string(tokens[i].type));
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