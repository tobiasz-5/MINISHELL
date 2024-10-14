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

int	ft_check_cmd(char *cmd)
{
	if (check_word(cmd, "echo", 4) == 0)
		return (1);
	else if (check_word(cmd, "cd", 1) == 0)
		return (1);
	else if (check_word(cmd, "pwd", 2) == 0)
		return (1);
	else if (check_word(cmd, "export", 6) == 0)
		return (1);
	else if (check_word(cmd, "unset", 4) == 0)
		return (1);
	else if (check_word(cmd, "env", 2) == 0)
		return (1);
	else
		return (0);
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
