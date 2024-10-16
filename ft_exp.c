/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 11:46:39 by negambar          #+#    #+#             */
/*   Updated: 2024/10/15 13:10:50 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniheader.h"

int	no_doll(t_mini **mtx, int i)
{
	int		j;
	char	**new_env;

	j = 0;
	new_env = fresh_mtx((*mtx)->env->env_new);
	if (!new_env)
		return (printf("Memory allocation failed\n"));
	freenew((*mtx));
	(*mtx)->env->env_new = new_env;
	while ((*mtx)->env->env_new[j] != NULL)
		j++;
	(*mtx)->env->env_new[j] = strdup(&(*mtx)->input[i]);
	if (!(*mtx)->env->env_new[j])
	{
		freenew((*mtx));
		return (0);
	}
	(*mtx)->env->env_new[j + 1] = NULL;
	return (1);
}

static int	doll(t_mini **mtx, int i, int j)
{
	free((*mtx)->env->env_new[j]);
	(*mtx)->env->env_new[j] = strdup(&(*mtx)->input[i]);
	return (1);
}

int	ft_exp(t_mini **mtx)
{
	//int	i;
	int	j;

	j = 0;
	//printf("input: %s\ninput pointer: %p", (*mtx)->input, (*mtx)->input);
	if ((*mtx)->input[0] == '\0')
		return (ft_putnbr_fd(ft_isalnum((*mtx)->input[0]), 1), get_env((*mtx)), 0);
	while ((*mtx)->env->env_new[j])
	{
		if (dollar_check((*mtx)->env->env_new[j], (*mtx)->input, '=') == 0){
			printf(COLOR_ORANGE"string number: %d\n" COLOR_RESET, j);
			return(doll(mtx, 0, j), 1);
			}
		j++;
	}
	if (!(*mtx)->env->env_new[j] && ft_strnstr((*mtx)->input, "=", ft_strlen((*mtx)->input)))
		{
			printf(COLOR_ORANGE"string number: %d\n" COLOR_RESET, j);
			no_doll(mtx, 0);}
	else
	{
		printf(COLOR_RED"check input\n"COLOR_RESET);
		return (0);
	}
	return (1);
}
