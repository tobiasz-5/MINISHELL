/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acapobia <acapobia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:38:58 by acapobia          #+#    #+#             */
/*   Updated: 2023/11/08 18:06:16 by acapobia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*char_dest;
	char	*char_src;

	i = 0;
	char_dest = (char *)dest;
	char_src = (char *)src;
	if (!dest && !src)
		return (NULL);
	while (i < n)
	{
		char_dest[i] = char_src[i];
		i++;
	}
	return ((void *)char_dest);
}
/*
int main()
{
	char str[]="ollare";
	char res[]="cia mondo";
	ft_memcpy(res, str, 3);
	printf("%s", res);
	return 0;
}
*/
