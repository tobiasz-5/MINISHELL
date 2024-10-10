/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exp_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 15:40:14 by negambar          #+#    #+#             */
/*   Updated: 2024/10/10 16:47:26 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniheader.h"

void	freenew(t_mini *mtx)
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

char **fresh_mtx(char **mtx)
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

int dollar_check(const char *s1, const char *s2, char c)
{
    size_t i;

    i = 0;
    if (c == 0)
        return (0);
    while (s1[i] && s2[i] && s1[i] != c && s2[i] != c && s1[i] == s2[i])
        i++;
    return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	not_existing(t_mini *mtx, char *input, int i)
{
	int j;

	j = 0;
	while (mtx->env->env_new[j] != NULL)
    {
		if (dollar_check(mtx->env->env_new[j], &input[i], '=') == 0)
			return (0);
	    j++;
	}
	return (1);
}