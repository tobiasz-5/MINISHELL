/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 15:49:48 by mailinci          #+#    #+#             */
/*   Updated: 2024/09/15 18:05:31 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniheader.h"

void process_input(char *input)
{
    t_token_node *tokens;
    t_token_node *current;

    add_history(input);
    tokens = lexer(input);
    current = tokens;
    while (current)
    {
        printf("Token: %s \t Type: %s\n",
               current->token,
               token_type_to_string(current->type));
        current = current->next;
    }
    free_tokens(tokens);
}


int main(void)
{
    char *input;

    signal(SIGINT, handle_sigint);
    signal(SIGQUIT, handle_sigquit);
    while (1)
    {
        input = readline("MINIPROMPT$ ");
        if (!input)
        {
            printf("\nFarewell my friend\n");
            break;
        }
        if (*input == '\0')
        {
            free(input);
            continue;
        }
        if (handle_builtins(input, "exit"))
        {
            free(input);
            break;
        }
        process_input(input);
        free(input);
    }
    rl_clear_history();
    return (0);
}
