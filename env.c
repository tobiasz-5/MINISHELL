/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 11:46:59 by negambar          #+#    #+#             */
/*   Updated: 2024/10/07 12:42:38 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniheader.h"

void get_env(char **env)
{
	int i;
	t_mini *old;

	old = malloc(sizeof(t_mini));
	old = ft_mini_init(env);
	i = 0;
	while (old->env->env_old[i])
	{
		printf("%s\n", old->env->env_old[i]);
		i++;
	}
}
