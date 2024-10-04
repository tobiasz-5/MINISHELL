/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acapobia <acapobia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 13:06:56 by acapobia          #+#    #+#             */
/*   Updated: 2023/11/14 14:00:41 by acapobia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*#include <stdio.h>*/
static char	**ft_free(char **mat, int i)
{
	int	j;

	j = 0;
	while (j < i)
		free(mat[j++]);
	free(mat);
	return (NULL);
}

static size_t	wordlen(char const *s, char c, size_t j)
{
	size_t	i;

	i = 0;
	while (s[j] && s[j] != c)
	{
		i++;
		j++;
	}
	return (i);
}

static size_t	word(char const *s, char c)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			len++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (len);
}

char	**ft_split(char const *s, char c)
{
	char	**mat;
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	j = 0;
	len = word(s, c);
	mat = (char **)malloc(sizeof(char *) * (len + 1));
	if (!mat)
		return (0);
	while (i < len)
	{
		if (s[j] && s[j] != c)
		{
			mat[i++] = ft_substr(s, j, wordlen(s, c, j));
			if (!mat[i -1])
				return (ft_free(mat, i));
			j += wordlen(s, c, j);
		}
		else
			j++;
	}
	mat[i] = NULL;
	return (mat);
}
/*
int main()
{
	char const *s = "ollare_the_gang";
	char c = '_';
	char **ptr = ft_split(s, c);
	size_t count = word(s, c), i = 0;
	while (i < count)
	{
		printf("%s\n", ptr[i]);
		i++;
	}
	
	
	return 0;
}*/