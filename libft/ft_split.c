/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mailinci <mailinci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 14:47:13 by mailinci          #+#    #+#             */
/*   Updated: 2024/09/06 20:25:16 by mailinci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	mtx_fill(const char *str, int words, char **mtx, char c)
{
	int	i;
	int	j;
	int	x;

	if (!str || !mtx)
		return (0);
	i = 0;
	j = -1;
	x = 0;
	while (str[i] == c)
		i++;
	while (++j < words)
	{
		while (str[i] != c && str[i] != '\0')
		{
			if (!mtx[j])
				return (0);
			mtx[j][x++] = str[i++];
		}
		mtx[j][x] = '\0';
		x = 0;
		while (str[i] == c)
			i++;
	}
	return (1);
}

int	count_words(const char *str, char c)
{
	int	i;
	int	j;
	int	counter;

	i = 0;
	j = ft_strlen(str) - 1;
	counter = 0;
	while (j >= 0 && str[j] == c)
		j--;
	while (str[i] && str[i] == c)
		i++;
	while (i <= j)
	{
		if ((str[i] != c && str[i + 1] == c)
			|| (str[i] != c && str[i + 1] == '\0'))
			counter++;
		i++;
	}
	return (counter);
}

int	*word_len(const char *str, int words, char c)
{
	int	*holder;
	int	i;
	int	j;
	int	x;

	i = 0;
	j = 0;
	x = 0;
	holder = (int *)ft_calloc(words, sizeof(int));
	if (!holder)
		return (NULL);
	while (str[i] == c)
		i++;
	while (j < words && str[i] != '\0')
	{
		while (str[i] && str[i] != c && ++x)
			i++;
		holder[j] = x;
		x = 0;
		while (str[i] == c && str[i] != '\0')
			i++;
		j++;
	}
	return (holder);
}

void	*ft_free(char **mtx, int len)
{
	int	i;

	i = -1;
	while (++i < len)
		free(mtx[i]);
	free(mtx);
	return (NULL);
}

char	**ft_split(const char *str, char c)
{
	char	**mtx;
	int		words;
	int		*letters;
	int		i;

	words = count_words(str, c);
	mtx = (char **)ft_calloc(words + 1, sizeof(char *));
	if (!mtx)
		return (NULL);
	letters = word_len(str, words, c);
	if (!letters)
		return (ft_free(mtx, words + 1), NULL);
	i = -1;
	while (++i < words)
	{
		mtx[i] = (char *)ft_calloc(letters[i] + 1, sizeof(char));
		if (!mtx[i])
			return (free(letters), ft_free(mtx, i));
	}
	if (!mtx_fill(str, words, mtx, c))
		return (free(letters), ft_free(mtx, words));
	return (free(letters), mtx);
}
/*
 int	main(int argc, char **argv)
{
	char	**x = NULL;
	char	*str = NULL;
	char	c;
	int		i, j;

	if (argc == 2)
	{
		i = 0;
		j = 0;
		str = ft_strdup(argv[1]);
		c = ' ';
		x = ft_split(str, c);
		while (x[i] != NULL)
			printf("%s\n", x[i++]);
		while (j < i)
			free(x[j++]);
		free (x);
		free(str);
	}
	return (0);
}
*/
