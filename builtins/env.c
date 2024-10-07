/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 11:46:59 by negambar          #+#    #+#             */
/*   Updated: 2024/10/07 12:29:55 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniheader.h"

void get_env(char **env)
{
	int i;

	ft_mini_init(env);
	i = 0;
	while (old->env_old[i])
	{
		printf("%s\n", old->env_old[i]);
		i++;
	}
}
