/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: girindi <girindi@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 12:02:49 by girindi           #+#    #+#             */
/*   Updated: 2024/10/07 15:40:54 by girindi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	*ptr;
	int				i;
	int				cont;
	int				flag;

	i = 0;
	flag = 0;
	cont = 0;
	ptr = (unsigned char *)s;
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
		{
			cont = i;
			flag = 1;
		}
		i++;
	}
	if (flag)
		return ((char *)(ptr + cont));
	else if (s[i] == (unsigned char)c)
		return ((char *)(ptr + i));
	else
		return (NULL);
}
/*
int main()
{
	const char *s = "ollare";
	printf("%s", ft_strrchr(s, 114));
	return 0; 
}*/
