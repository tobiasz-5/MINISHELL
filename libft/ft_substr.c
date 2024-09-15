/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mailinci <mailinci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 16:56:39 by mailinci          #+#    #+#             */
/*   Updated: 2024/03/10 16:09:56 by mailinci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	l;
	size_t	end;

	if (!s)
		return (0);
	l = ft_strlen(s);
	end = 0;
	if (start <= l)
		end = l - start;
	if (start > l)
		return (ft_calloc(1, 1));
	if (end > len)
		end = len;
	new = (char *)malloc(sizeof(char) * end + 1);
	if (!new)
		return (0);
	ft_strlcpy(new, s + start, end + 1);
	return (new);
}
