/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 12:55:28 by negambar          #+#    #+#             */
/*   Updated: 2024/10/05 12:55:28 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniheader.h"

static char	**ft_cmd_util(t_token_node *ptr, int i)
{
	char	**mtx;
	int		j;

	j = 0;
	mtx = (char **)malloc((i + 1) * sizeof(char *));
	if (!mtx)
		return (NULL);
	while (j < i)
	{
		mtx[j] = ft_strdup((const char *)ptr->token);
		if (!mtx[j])
		{
			ft_free_mtx(mtx);
			return (NULL);
		}
		ptr = ptr->next;
		j++;
	}
	mtx[j] = NULL;
	return (mtx);
}

char	**ft_copy_cmd(t_token_node *current)
{
	t_token_node	*ptr;
	char			**mtx;
	int				i;

	ptr = current->next;
	mtx = NULL;
	i = 1;
	while (ptr && ptr->token[0] == '-')
	{
		i++;
		ptr = ptr->next;
	}
	ptr = current;
	mtx = ft_cmd_util(ptr, i);
	if (!mtx)
		return (NULL);
	return (mtx);
}

void	ft_free_selected_mini(t_mini **mini)
{
	(*mini)->pipe_check = false;
	(*mini)->redirect = false;
	if ((*mini)->input)
		free((*mini)->input);
	if ((*mini)->cmd)
		ft_free_mtx((*mini)->cmd);
}

char	**ft_copy_mtx(char **mtx)
{
	char	**new;
	int		c;
	int		i;

	c = 0;
	i = 0;
	while (mtx[c])
		c++;
	new = (char **)malloc((c + 1) * sizeof(char *));
	if (!new)
		return (NULL);
	while (i < c)
	{
		new[i] = ft_strdup(mtx[i]);
		if (!new)
		{
			ft_free_mtx(new);
			return (NULL);
		}
		i++;
	}
	new[i] = NULL;
	return (new);
}
