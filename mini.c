/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: girindi <girindi@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 12:51:30 by girindi           #+#    #+#             */
/*   Updated: 2024/10/08 18:20:55 by girindi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniheader.h"
//non libera la pipe
/* void	ft_free_mini(t_mini **mini)
{
	if ((*mini)->redirect)
		free((*mini)->redirect);
	if ((*mini)->input)
		free((*mini)->input);
	if ((*mini)->cmd)
		free((*mini)->cmd);
	if ((*mini)->export)
		ft_free_exp(&(*mini)->export);
	if ((*mini)->env)
		ft_free_env(&(*mini)->env);
	free((*mini));
} */
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
	mini->env->env_new = mini->env->env_old;
	if (!mini->env->env_old)
		return (NULL);
	mini->input = NULL;
	mini->redirect = NULL;
	mini->cmd = NULL;
	mini->export = NULL;
	return (mini);
}
