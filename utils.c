/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 12:55:15 by negambar          #+#    #+#             */
/*   Updated: 2024/10/05 12:55:15 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniheader.h"

void	ft_reset(t_mini **mini)
{
	if ((*mini)->cmd)
	{
		ft_free_mtx((*mini)->cmd);
		(*mini)->cmd = NULL;
	}
	if ((*mini)->pipe_check == true)
		(*mini)->pipe_check = false;
	if ((*mini)->redirect == true)
		(*mini)->redirect = false;
	if ((*mini)->input)
	{
		free((*mini)->input);
		(*mini)->input = NULL;
	}
}

int	ft_check_cmd(char *cmd)
{
	if (check_word(cmd, "echo", 4) == 0)
		return (1);
	else if (check_word(cmd, "cd", 2) == 0)
		return (1);
	else if (check_word(cmd, "pwd", 3) == 0)
		return (1);
	else if (check_word(cmd, "export", 6) == 0)
		return (1);
	else if (check_word(cmd, "unset", 4) == 0)
		return (1);
	else if (check_word(cmd, "env", 3) == 0)
		return (1);
	else
		return (2);
}

void	ft_free_env(t_env **env)
{
	if ((*env)->env_old)
		ft_free_mtx((*env)->env_old);
	if ((*env)->env_new)
		ft_free_mtx((*env)->env_new);
	free((*env));
}

void	ft_free_exp(t_exp **export)
{
	t_exp	*ptr;

	ptr = (*export);
	while (ptr)
	{
		if (ptr->name)
			free(ptr->name);
		if (ptr->value)
			free(ptr->value);
		ptr = ptr->next;
	}
	free((*export));
}
