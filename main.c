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
// Funzione che processa l'intero input dell'utente
void	process_input(char *input)
{
	t_token_node	*current;
	t_token_node	*tokens;
	// Variabile che conterrà la lista di token
	add_history(input);
	tokens = lexer(input);
	if (!tokens)
	{
		fprintf(stderr, COLOR_RED "Error creating tokens.\n"COLOR_RESET);
		return ;
	}
	current = tokens;
	while (current)
	// Toglieremo le print e manderemo
	// token al parser per l'esecuzione dei comandi
	{
		printf("Token: %s \t Type: %s\n",
			current->token,
			token_type_to_string(current->type));
		if (current->single_quote)
			printf("Single quote: true\n");
		else if (current->double_quote)
			printf("Double quote: true\n");
		else
			printf("No quotes\n");
		current = current->next;
	}
	free_tokens (tokens);
}

void	init_sign(void)
{
	signal(SIGINT, handle_sigint);
	signal(SIGQUIT, handle_sigquit);
}

void	shell_loop(char **env)
{
	char	*input;

	while (1)
	{
		input = readline(BLUE"MINIPROMPT$ "COLOR_RESET);
		// Se l'input è NULL, significa che l'utente ha premuto Ctrl+D
		if (!input || handle_builtins(input, env))
		{
			printf(COLOR_ORANGE"\nFarewell my friend\n"COLOR_RESET);
			free(input);
			break ;
		}
		// Per non aggiungere linee vuote alla history 
		//(Enter e' infatti un input vuoto)
		if (*input == '\0')
		{
			free(input);
			continue ;
		}
		process_input(input);
		free(input);
	}
	rl_clear_history();
	// Pulisce la history prima di uscire
}

int	main(int ac, char **av, char **env)
{
	if (ac > 1)
		return (printf(COLOR_RED"Usage: %s\t[No Additional Arguments]\n" \
		COLOR_RESET, av[0]), 1);
	init_sign();
	shell_loop(env);
	return (0);
}
