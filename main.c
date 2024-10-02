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

void process_input(char *input, t_mini **mini)// Funzione che processa l'intero input dell'utente
{
    t_token_node *tokens;	       // Variabile che conterrà la lista di token			
    t_token_node *current;

    add_history(input);
    tokens = lexer(input);
	if (!tokens) 
	{
	    printf(stderr, COLOR_RED "Error creating tokens.\n"COLOR_RESET);
    	return;
	}
    current = tokens;
	while (current != NULL)
	{
		ft_update_mini(*mini, current);//TODO aggiorna cmd, pipe, redirect per eseguirli
		ft_pipe_or_redirect(mini);//TODO controlla se ci sono pipe o meno e in caso li inizializa
		if (ft_check_cmd((*mini)->cmd) == 1)//TODO 1 builtin | 2 execv 
			handle_builtins(mini);//upgrade gestione builtin
		else
			ft_execv(mini);//TODO
		ft_update_pipe(mini);//TODO se ce la pipe la chiude
		current = current->next;
	}
    free_tokens(tokens);
}

void init_sign(void)
{
	signal(SIGINT, handle_sigint);
	signal(SIGQUIT, handle_sigquit);
}

void shell_loop(void)
{
	t_mini	*mini;
	char	*input;

	mini = ft_mini_init();//TODO
	while (1)
	{
		input = readline(BLUE"MINIPROMPT$ "COLOR_RESET);
		if (!input || ft_strncmp(input, "exit", 4) == 0)                             // Se l'input è NULL, significa che l'utente ha premuto Ctrl+D
		{
			printf(COLOR_ORANGE"\nFarewell my friend\n"COLOR_RESET);
			free(input);
			break;
		}
		if (*input == '\0')                     // Per non aggiungere linee vuote alla history (Enter e' infatti un input vuoto)
		{
			free(input);
			continue;
		}
		process_input(input, &mini);
		free(input);
	}
	ft_free_mini(mini);//TODO
	rl_clear_history();                         // Pulisce la history prima di uscire
}

int main(int ac, char **av, char **env)
{
	void(av);
	if (ac > 1)
		return (printf(COLOR_RED"Usage: %s\t[No Additional Arguments]\n"COLOR_RESET, av[0]), 1);
	init_sign();
	shell_loop();
	return (0);
}
