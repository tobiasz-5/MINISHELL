/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acapobia <acapobia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:04:54 by acapobia          #+#    #+#             */
/*   Updated: 2023/10/23 07:11:38 by acapobia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*p;

	i = 0;
	p = s;
	while (i < n)
	{
		p[i] = '\0';
		i++;
	}
}
/*
int main()
{
	char str[] = "ollare";
	ft_bzero(str, 3);
	for(int i = 0; i < 6; i++)
	{
		write(1, &str[i], 1);
	}
	
}*/
