/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 11:46:59 by negambar          #+#    #+#             */
/*   Updated: 2024/10/07 12:06:44 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniheader.h"

void get_env(char **env)
{
	int i;
	t_env *old;
	int count;

	old = malloc(sizeof(t_env));
	if (!old)
		return ;
	count = 0;
	while (env[count])
		count++;
	old->env_old = malloc(sizeof(char *) * (count + 1));
	if (!old->env_old)
		return ;
	i = 0;
	while (i < count)
	{
		old->env_old[i] = env[i];
		i++;
	}
	old->env_old[i] = NULL;
	i = 0;
	while (old->env_old[i])
	{
		printf("%s\n", old->env_old[i]);
		i++;
	}
}
