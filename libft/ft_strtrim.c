/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mailinci <mailinci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 18:37:56 by mailinci          #+#    #+#             */
/*   Updated: 2024/03/10 16:09:23 by mailinci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check(char const c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *str, char const *set)
{
	size_t	z;
	char	*s;

	if (!str || !set)
		return (NULL);
	while (*str)
	{
		if (ft_check(((char)*str), set) == 1)
			str++;
		else
			break ;
	}
	z = ft_strlen(str);
	while (z != 0)
	{
		if (ft_check(str[z - 1], set) == 1)
			z--;
		else
			break ;
	}
	s = (char *)malloc((z + 1) * sizeof(char));
	if (!s)
		return (NULL);
	ft_strlcpy(s, (char *)str, z + 1);
	return (s);
}
