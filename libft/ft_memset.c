/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acapobia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:34:29 by acapobia          #+#    #+#             */
/*   Updated: 2023/10/09 15:34:32 by acapobia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
/*#include<stdio.h>*/
void	*ft_memset(void *s, int c, size_t n)
{
	char	*ptr;
	size_t	i;

	i = 0;
	ptr = (char *)s;
	while (i < n)
	{
		ptr[i] = (char )c;
		i++;
	}
	return (ptr);
}
/*
int main()
{
	char str[]= "ollare";
	ft_memset(str, '0', 3);
	printf("%s", str);
	return 0;
}*/
