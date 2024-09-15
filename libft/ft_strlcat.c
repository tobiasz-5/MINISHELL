/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mailinci <mailinci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 10:35:47 by mailinci          #+#    #+#             */
/*   Updated: 2024/03/10 16:11:01 by mailinci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	z;

	i = 0;
	z = ft_strlen(dst);
	if (size <= z)
		return (size + ft_strlen(src));
	while (src[i] != '\0' && z + 1 < size)
	{
		dst[z] = src[i];
		z++;
		i++;
	}
	dst[z] = '\0';
	return (ft_strlen(dst) + ft_strlen(&src[i]));
}
