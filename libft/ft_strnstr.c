/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mailinci <mailinci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 21:22:41 by mailinci          #+#    #+#             */
/*   Updated: 2024/03/10 16:08:50 by mailinci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	n;

	i = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (big[i] != '\0')
	{
		n = 0;
		while (big[n + i] == little[n] && (n + i) < len)
		{
			if (big[n + i] == '\0' && little[n] == '\0')
				return ((char *)&big[i]);
			n++;
		}
		if (little[n] == '\0')
			return ((char *)big + i);
		i++;
	}
	return (0);
}
