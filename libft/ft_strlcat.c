/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acapobia <acapobia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 16:59:59 by acapobia          #+#    #+#             */
/*   Updated: 2023/10/27 20:45:40 by acapobia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	len_d;
	size_t	len_s;
	size_t	i;
	size_t	j;

	if (size == 0)
		return (ft_strlen(src));
	len_d = ft_strlen(dest);
	len_s = ft_strlen(src);
	i = 0;
	j = len_d;
	while (src[i] && j < size - 1)
	{
		dest[j] = src[i];
		i++;
		j++;
	}
	dest[j] = '\0';
	if (size < len_d)
		return (len_s + size);
	return (len_d + len_s);
}
