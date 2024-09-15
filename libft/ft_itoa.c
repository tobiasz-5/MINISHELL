/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mailinci <mailinci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 20:55:55 by mailinci          #+#    #+#             */
/*   Updated: 2024/03/10 16:13:16 by mailinci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_numlen(long n)
{
	size_t	len;

	len = 0;
	if (n <= 0)
	{
		n *= -1;
		len++;
	}
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_tab0(char *tab)
{
	tab = (char *)malloc(sizeof(char) * 2);
	if (!tab)
		return (NULL);
	tab[0] = '0';
	tab[1] = '\0';
	return (tab);
}

int	ft_malfail(char *tab)
{
	if (!tab)
	{
		free (tab);
		return (1);
	}
	return (0);
}

char	*ft_itoa(int num)
{
	long	n;
	size_t	len;
	char	*tab;

	n = num;
	len = ft_numlen(n);
	tab = NULL;
	if (n == 0)
		return (ft_tab0(tab));
	tab = (char *)malloc(sizeof(char) * len + 1);
	if (ft_malfail(tab) == 1)
		return (NULL);
	tab[len--] = '\0';
	if (n < 0)
	{
		tab[0] = '-';
		n *= -1;
	}
	while (n > 0)
	{
		tab[len--] = n % 10 + 48;
		n = n / 10;
	}
	return (tab);
}
