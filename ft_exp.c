/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 11:46:39 by negambar          #+#    #+#             */
/*   Updated: 2024/10/11 11:52:05 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniheader.h"

int	no_doll(t_mini *mtx, char *input, int i)
{
	int		j;
	char	**new_env;

	j = 0;
	new_env = fresh_mtx(mtx->env->env_new);
	if (!new_env)
		return (printf("Memory allocation failed\n"));
	freenew(mtx);
	mtx->env->env_new = new_env;
	while (mtx->env->env_new[j] != NULL)
		j++;
	mtx->env->env_new[j] = strdup(&input[i]);
	if (!mtx->env->env_new[j])
	{
		freenew(mtx);
		return (0);
	}
	mtx->env->env_new[j + 1] = NULL;
	return (1);
}

static int	doll(t_mini *mtx, char *input, int i, int j)
{
	free(mtx->env->env_new[j]);
	mtx->env->env_new[j] = strdup(&input[i]);
	return (1);
}

int	ft_exp(t_mini *mtx, char *input)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	i = skip_echo("export", input, 0);
	i = skip_spaces(input, i);
	while (mtx->env->env_new[j])
	{
		if (dollar_check(mtx->env->env_new[j], &input[i], '=') == 0){
			printf("string number: %d\n", j);
			return(doll(mtx, input, i, j), 1);
			}
		j++;
	}
	if (!mtx->env->env_new[j] && ft_strnstr(input, "=", ft_strlen(input)))
		no_doll(mtx, input, i);
	else
	{
		printf(COLOR_RED"check input\n"COLOR_RESET);
		return (0);
	}
	return (1);
}
