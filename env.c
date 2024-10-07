/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: girindi <girindi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 11:46:59 by negambar          #+#    #+#             */
/*   Updated: 2024/10/07 16:52:05 by girindi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniheader.h"

void get_env(t_mini *old)
{
	int i;
	
	i = 0;
	while (old->env->env_old[i])
	{
		printf("%s\n", old->env->env_old[i]);
		i++;
	}
	// while (env[i])
	// 	printf("%s\n", env[i++]);
}
