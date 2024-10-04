/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acapobia <acapobia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 16:41:28 by acapobia          #+#    #+#             */
/*   Updated: 2023/10/23 10:28:46 by acapobia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*#include<stdio.h>*/
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (i + 1 < (size) && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	if (size > 0)
		dst[i] = '\0';
	while (src[i])
		i++;
	return (i);
}
/*
int main()
{
	char src[]="copy";
	char dst[]="ollare";
	size_t len_src = ft_strlcpy(dst, src, 5);
	printf("la len di src e' : %ld \n", len_src);
	printf("dst ora e' : %s", dst);
	return 0;
}*/
