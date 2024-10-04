/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acapobia <acapobia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 23:41:51 by acapobia          #+#    #+#             */
/*   Updated: 2023/10/27 23:40:23 by acapobia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*#include<stdio.h>*/
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (*(unsigned char *)(s1 + i) != *(unsigned char *)(s2 + i))
		{
			if (*(unsigned char *)(s1 + i) > *(unsigned char *)(s2 + i))
				return (1);
			else
				return (-1);
		}
		i++;
	}
	return (0);
}
/*
int main()
{
	char *s1 = "olare";
	char *s2 = "ollare";
	printf("%d",ft_memcmp(s1, s2, 4));
	return 0;
}*/
