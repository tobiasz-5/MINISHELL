/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 12:06:47 by negambar          #+#    #+#             */
/*   Updated: 2024/10/15 12:11:45 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniheader.h"

void get_env(t_mini *old)
{
	int i;

	i = 0;
	printf("ENV\n");
	while (old->env->env_new[i])
	{
		printf("%s\n", old->env->env_new[i]);
		i++;
	}
}