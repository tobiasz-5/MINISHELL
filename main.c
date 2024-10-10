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

static void ft_test(t_mini *mini)
{
    // Stampa il codice di uscita
    printf("Exit Status: %d\n", mini->exit_status);

    // Stampa se c'è una pipe
    printf("Pipe Check: %s\n", mini->pipe_check ? "true" : "false");

    // Stampa se ci sono redirezioni
    printf("Redirect: %s\n", mini->redirect ? "true" : "false");

    // Stampa l'input
    if (mini->input != NULL)
        printf("Input: %s\n", mini->input);
    else
        printf("Input is NULL\n");

    // Stampa i comandi
    if (mini->cmd != NULL)
    {
        int i = 0;
        while (mini->cmd[i] != NULL)
        {
            printf("Command[%d]: %s\n", i, mini->cmd[i]);
            i++;
        }
    }
    else
        printf("Command is NULL\n");

    // Stampa la variabile export
    if (mini->export != NULL)
    {
        t_exp *temp = mini->export;
        while (temp != NULL)
        {
            printf("Export: Name = %s, Value = %s\n", temp->name, temp->value);
            temp = (t_exp *)temp->next; // Cast di next
        }
    }
    else
        printf("Export is NULL\n");

    // Stampa l'ambiente
    if (mini->env != NULL)
    {
        printf("Old Env:\n");
        for (int i = 0; mini->env->env_old[i] != NULL; i++)
            printf("env_old[%d]: %s\n", i, mini->env->env_old[i]);

        printf("New Env:\n");
        for (int i = 0; mini->env->env_new[i] != NULL; i++)
            printf("env_new[%d]: %s\n", i, mini->env->env_new[i]);
    }
    else
        printf("Env is NULL\n");
}


void process_input(char *input, t_mini **mini)// Funzione che processa l'intero input dell'utente
{
    t_token_node *tokens;	       // Variabile che conterrà la lista di token			
    t_token_node *current;

    add_history(input);
    tokens = lexer(input);
	if (!tokens)
	{
	    printf(COLOR_RED "Error creating tokens.\n"COLOR_RESET);
    	return;
	}
    current = tokens;
	while (current != NULL)
	{
		ft_update_mini(&(*mini), &current);//TODO aggiorna cmd, pipe, redirect per eseguirli
		// if ((*mini)->pipe_check == true)
			// ft_pipe(mini, tokens);//TODO controlla se ci sono pipe o meno e in caso li inizializa
		// else if (ft_check_cmd((*mini)->cmd) == 1)//TODO 1 builtin | 2 execv
		// 	handle_builtins(mini);//upgrade gestione builtin
		// else
		//	ft_execv(mini);//TODO
		// if ((*mini)->redirect != NULL)
		// 	ft_reset()
		current = current->next;
		ft_test((*mini));//DA preparare
	}
    free_tokens(tokens);
}

void init_sign(void)
{
	signal(SIGINT, handle_sigint);
	signal(SIGQUIT, handle_sigquit);
}

void shell_loop(char **env)
{
	t_mini	*mini;
	char	*input;

	mini = ft_mini_init(env);
	if (!mini)
		return ;
	while (1)
	{
		input = readline(BLUE"MINIPROMPT$ "COLOR_RESET);
		if (!input || ft_strncmp(input, "exit", 4) == 0)//TOUPGRADEfare funzione che skippi gli spazi e poi strncmp// Se l'input è NULL, significa che l'utente ha premuto Ctrl+D
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
		ft_free_selected_mini(&mini);//TODO free e setta alcune variabili per il nuovo promt eccetto es. export, env
		free(input);
	}
	ft_free_mini(&mini);
	rl_clear_history();                     // Pulisce la history prima di uscire
}

int main(int ac, char **av, char **env)
{
	if (ac > 1 && av)
		return (printf(COLOR_RED"Usage: %s\t[No Additional Arguments]\n"COLOR_RESET, av[0]), 1);
	init_sign();
	shell_loop(env);
	return (0);
}
