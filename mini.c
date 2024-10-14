/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 13:03:50 by negambar          #+#    #+#             */
/*   Updated: 2024/10/05 13:03:50 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniheader.h"

int	ft_check_token(t_token_node *t_ptr, t_token_node **start)
{
	t_token_node	*ptr;

	if (!t_ptr)
		return (1);
	ptr = (*start);
	while (ptr->next != t_ptr)
		ptr = ptr->next;
	if (ptr->type == TOKEN_PIPE)
		return (1);
	else
		return (0);
}

void	ft_handle_first_token(t_token_node **current, t_mini **mini)
{
	t_token_node	*t_ptr;
	int				size;
	int				i;
	
	i = 0;
	t_ptr = (*current)->next;
	size = 1;
	while (t_ptr != NULL && ft_strncmp((const char *)t_ptr->token, "-", 1) == 0)
	{
		size++;
		t_ptr = t_ptr->next;
	}
	(*mini)->cmd = (char **)malloc((size + 1) * (sizeof(char *)));
	if (!(*mini)->cmd)
		return ;
	while (i < size)
	{
		(*mini)->cmd[i] = ft_strdup((*current)->token);
		(*current) = (*current)->next;
		i++;
	}
	(*mini)->cmd[i] = NULL;
}

void	ft_update_mini(t_mini **mini,t_token_node **current)
{
	t_token_node	*t_ptr;

	ft_handle_first_token(&(*current), &(*mini));//vede se il primo token è un comando e se si fa t_ptr = next;
	t_ptr = (*current);
	while (t_ptr != NULL)//controlla il token finchè non da NULL
	{
		if (ft_strncmp((const char *)t_ptr->token, "$", 1) == 0)//DOLLAR CASE
			ft_handle_dollar(&(*mini), (*current));
		else if (t_ptr->type == TOKEN_WORD)
			ft_handle_world(&(*mini), (*current));
		else if (t_ptr->type == TOKEN_PIPE)
			(*mini)->pipe_check = true;
		else if (t_ptr->type == TOKEN_HEREDOC)
			ft_handle_heredoc(&(*mini), (*current));
		else if (t_ptr->type == TOKEN_REDIR_APPEND)
			ft_handle_append(&(*mini), &(*current));
		else if (t_ptr->type == TOKEN_REDIR_IN)
			ft_handle_red_in(&(*mini), &(*current));
		else if (t_ptr->type == TOKEN_REDIR_OUT)
			ft_handle_red_out(&(*mini), &(*current));
		t_ptr = t_ptr->next;
		if (ft_check_token(t_ptr, &(*current)) == 1)//se trova la pipe nel token precendete esce (unico caso in cui uscire senno da errore automaticamente)
			break ;
	}
}

//non libera la pipe
void	ft_free_mini(t_mini **mini)
{
	if ((*mini)->input)
		free((*mini)->input);
	if ((*mini)->cmd)
		ft_free_mtx((*mini)->cmd);
	if ((*mini)->export)
		ft_free_exp(&(*mini)->export);
	if ((*mini)->env)
		ft_free_env(&(*mini)->env);
	free((*mini));
}

t_mini	*ft_mini_init(char **env)
{
	t_mini	*mini;

	mini = NULL;
	mini = (t_mini *)malloc(sizeof(t_mini));
	if (!mini)
		return (NULL);
	mini->env = (t_env *)malloc(sizeof(t_env));
	if (!mini->env)
		return (NULL);
	mini->env->env_old = ft_copy_mtx(env);
	if (!mini->env->env_old)
		return (NULL);
	mini->input = NULL;
	mini->redirect = false;
	mini->cmd = NULL;
	mini->export = NULL;
	mini->pipe_check = false;
	mini->exit_status = 0;

	return (mini);
}
