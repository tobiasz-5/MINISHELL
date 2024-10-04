/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acapobia <acapobia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 12:02:49 by acapobia          #+#    #+#             */
/*   Updated: 2023/10/29 11:07:19 by acapobia         ###   ########.fr       */
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
