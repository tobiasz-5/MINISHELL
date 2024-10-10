/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 11:46:39 by negambar          #+#    #+#             */
/*   Updated: 2024/10/10 14:15:16 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniheader.h"

static void	freenew(t_mini *mtx)
{
	int i;

	if (!mtx->env->env_new || !mtx->env || !mtx)
		return ;
	i = 0;
	while (mtx->env->env_new[i])
	{
		free(mtx->env->env_new[i]);
		i++;
	}
	free(mtx->env->env_new);
	mtx->env->env_new = NULL;
}

static char **fresh_mtx(char **mtx)
{
	char	**new;
	int		c;
	int		i;

	c = 0;
	i = 0;
	while (mtx && mtx[c])
		c++;
	new = (char **)malloc((c + 2) * sizeof(char *));
	if (!new)
		return (NULL);
	while (i < c)
	{
		new[i] = ft_strdup(mtx[i]);
		if (!new[i])
		{
			ft_free_mtx(new);
			return (NULL);
		}
		i++;
	}
	new[i] = NULL;
	new[i+1] = NULL;
	return (new);
}

static int no_doll(t_mini *mtx, char *input, int i)
{
	int j;

	j = 0;
	char **new_env = fresh_mtx(mtx->env->env_new);
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


int ft_exp(t_mini *mtx, char *input)
{
    int i;

    i = 0;
    i = skip_echo("export", input, 0);
    while (input[i] == ' ' || input[i] == '\t')
    {
	    i++;
	}
	if (input[i] != '$')
		no_doll(mtx, input, i);
    printf("After skip_echo, i = %d, input[i] = '%c'\n", i, input[i]);
    return (1);
}
